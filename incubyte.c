#include <stdio.h>

// Define constants for directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Define a structure to represent the position
struct Position {
    int x;
    int y;
    int z;
};

// Define a structure to represent the spacecraft
struct Chandrayaan3 {
    struct Position position;
    int direction;
};

// Function to move forward
void move_forward(struct Chandrayaan3 *chandrayaan) {
    switch (chandrayaan->direction) {
        case NORTH:
            chandrayaan->position.y++;
            break;
        case EAST:
            chandrayaan->position.x++;
            break;
        case SOUTH:
            chandrayaan->position.y--;
            break;
        case WEST:
            chandrayaan->position.x--;
            break;
    }
}

// Function to turn right
void turn_right(struct Chandrayaan3 *chandrayaan) {
    chandrayaan->direction = (chandrayaan->direction + 1) % 4;
}

// Function to turn left
void turn_left(struct Chandrayaan3 *chandrayaan) {
    chandrayaan->direction = (chandrayaan->direction + 3) % 4;
}

// Function to move up
void move_up(struct Chandrayaan3 *chandrayaan) {
    chandrayaan->position.z++;
}

// Function to move back
void move_back(struct Chandrayaan3 *chandrayaan) {
    switch (chandrayaan->direction) {
        case NORTH:
            chandrayaan->position.y--;
            break;
        case EAST:
            chandrayaan->position.x--;
            break;
        case SOUTH:
            chandrayaan->position.y++;
            break;
        case WEST:
            chandrayaan->position.x++;
            break;
    }
}

// Function to execute commands
void execute_commands(struct Chandrayaan3 *chandrayaan, char commands[], int num_commands) {
    for (int i = 0; i < num_commands; i++) {
        char command = commands[i];
        switch (command) {
            case 'f':
                move_forward(chandrayaan);
                break;
            case 'r':
                turn_right(chandrayaan);
                break;
            case 'l':
                turn_left(chandrayaan);
                break;
            case 'u':
                move_up(chandrayaan);
                break;
            case 'b':
                move_back(chandrayaan);
                break;
        }
    }
}

int main() {
    struct Chandrayaan3 chandrayaan = {{0, 0, 0}, NORTH};
    char commands[] = {'f', 'r', 'u', 'b', 'l'};
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    execute_commands(&chandrayaan, commands, num_commands);

    printf("Final Position: (%d, %d, %d)\n", chandrayaan.position.x, chandrayaan.position.y, chandrayaan.position.z);
    printf("Final Direction: %s\n", chandrayaan.direction == NORTH ? "N" : (chandrayaan.direction == EAST ? "E" : (chandrayaan.direction == SOUTH ? "S" : "W")));

    return 0;
}

