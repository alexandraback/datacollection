//
//  main.c
//  codejam-qr-c
//
//  Created by Yunzhu Li on 12/4/14.
//  Copyright (c) 2014 Yunzhu Li. All rights reserved.
//

#include <stdio.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// IO
int* readNIntegersInLine(char *line, int n);
double* readNFloatsInLine(char *line, int n);
void printBoardConfiguration(int R, int C, char *board);

// Algorithm
void process_dot(int x, int y);
int countCleanDots();
char verifyAndSetDot(int x, int y);
void setDotRoundClean(int x, int y);
void fillNonConfWithMines();
char getDotByPos(char *boardToSet, int x, int y);
void setDotByPos(char *boardToSet, int x, int y, char value);

char *board = NULL;
char *board_visited = NULL;
int R = 0, C = 0, M = 0;

int main(int argc, const char * argv[])
{
	
	const char *inputFileName;
	char bufLine[32];
	
	if (argc > 1) {
		inputFileName = argv[1];
	} else {
		inputFileName = "input.in";
	}
	
	FILE *pFileIn = fopen(inputFileName, "r");
	if (!pFileIn) {
		printf("Cannot open input file:%s.\n", inputFileName);
		exit(0);
	}
	
	// Read number of cases
	fgets(bufLine, 32, pFileIn);
	int numberOfCases = atoi(bufLine);
	
	for (int caseNum = 1; caseNum <= numberOfCases; caseNum++) {
		
		// Read & parse numbers
		fgets(bufLine, 32, pFileIn);
		int *parsedNumbers = readNIntegersInLine(bufLine, 3);
		R = parsedNumbers[0]; C = parsedNumbers[1]; M = parsedNumbers[2];
		
		// Init board
		board = malloc(R * C * sizeof(char));
		board_visited = malloc(R * C * sizeof(char));

		char solutionFound = 0;
		if ((R * C) - M == 1) {
			setDotByPos(board, 0, 0, 3);
			fillNonConfWithMines(board, R, C);
			solutionFound = 1;
		} else {
			for (int y = 0; y < R; y++) {
				for (int x = 0; x < C; x++) {
					memset(board, 0, R * C * sizeof(char));
					memset(board_visited, 0, R * C * sizeof(char));
					
					process_dot(x, y);
					if ((R * C) - countCleanDots(board, R, C) == M) {
						setDotByPos(board, x, y, 3);
						fillNonConfWithMines(board, R, C);
						solutionFound = 1;
						break;
					}
				}
				if (solutionFound)
					break;
			}
		}
		
		// Print result
		printf("Case #%d:\n", caseNum);
		if (solutionFound) {
			printBoardConfiguration(R, C, board);
		} else {
			printf("Impossible\n");
		}
	}
	
    return 0;
}

int* readNIntegersInLine(char *line, int n) {
	int *numbers = malloc(n * sizeof(int));
	
	char *subStr = NULL;
	subStr = strtok(line, " ");
	numbers[0] = atoi(subStr);
	
	for (int i = 1; i < n; i++) {
		subStr = strtok(NULL, " ");
		numbers[i] = atoi(subStr);
	}
	
	return numbers;
}

double* readNFloatsInLine(char *line, int n) {
	double *numbers = malloc(n * sizeof(double));
	
	char *subStr = NULL;
	subStr = strtok(line, " ");
	numbers[0] = atof(subStr);
	
	for (int i = 1; i < n; i++) {
		subStr = strtok(NULL, " ");
		numbers[i] = atof(subStr);
	}
	
	return numbers;
}

void printBoardConfiguration(int R, int C, char *board) {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			char dot = board[r * C + c];
			if (dot == 0) {
				printf("n");
			} else if (dot == 1 || dot == 2) {
				printf(".");
			} else if (dot == 9) {
				printf("*");
			} else if (dot == 3) {
				printf("c");
			}
		}
		printf("\n");
	}
}

void process_dot(int x, int y) {
	if (getDotByPos(board_visited, x, y) == 1) {
		return;
	}
	
	if (x < 0 || x >= C || y < 0 || y >= R) {
		return;
	}
	
	setDotByPos(board_visited, x, y, 1);
	
	if (verifyAndSetDot(x, y)) {
//		printBoardConfiguration(R, C, board);
//		printf("\n");
		process_dot(x - 1, y - 1); // Upper left
		process_dot(x - 0, y - 1); // Upper
		process_dot(x + 1, y - 1); // Upper right
		process_dot(x - 1, y - 0); // Left
		process_dot(x + 1, y - 0); // Right
		process_dot(x - 1, y + 1); // Lower left
		process_dot(x - 0, y + 1); // Lower
		process_dot(x + 1, y + 1); // Lower right
	}
}

char verifyAndSetDot(int x, int y) {
	
	if (x < 0 || x >= C || y < 0 || y >= R)
		return 0;
	
	
	int current_clean_dots = countCleanDots(board, R, C);
	int tmp_x = 0, tmp_y = 0;
	
	tmp_x = x - 1; tmp_y = y - 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		if (getDotByPos(board, tmp_x, tmp_y) == 0) {
			current_clean_dots++;
		}
	}
	
	tmp_x = x - 0; tmp_y = y - 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		if (getDotByPos(board, tmp_x, tmp_y) == 0) {
			current_clean_dots++;
		}
	}
	
	tmp_x = x + 1; tmp_y = y - 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		if (getDotByPos(board, tmp_x, tmp_y) == 0) {
			current_clean_dots++;
		}
	}
	
	tmp_x = x - 1; tmp_y = y - 0;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		if (getDotByPos(board, tmp_x, tmp_y) == 0) {
			current_clean_dots++;
		}
	}
	
	tmp_x = x - 0; tmp_y = y - 0;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		if (getDotByPos(board, tmp_x, tmp_y) == 0) {
			current_clean_dots++;
		}
	}
	
	tmp_x = x + 1; tmp_y = y - 0;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		if (getDotByPos(board, tmp_x, tmp_y) == 0) {
			current_clean_dots++;
		}
	}
	
	tmp_x = x - 1; tmp_y = y + 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		if (getDotByPos(board, tmp_x, tmp_y) == 0) {
			current_clean_dots++;
		}
	}
	
	tmp_x = x - 0; tmp_y = y + 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		if (getDotByPos(board, tmp_x, tmp_y) == 0) {
			current_clean_dots++;
		}
	}
	
	tmp_x = x + 1; tmp_y = y + 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		if (getDotByPos(board, tmp_x, tmp_y) == 0) {
			current_clean_dots++;
		}
	}
	
	if ((R * C - current_clean_dots) < M) {
		return 0;
	} else {
		setDotRoundClean(x, y);
		return 1;
	}
}

void setDotRoundClean(int x, int y) {
	int tmp_x = 0, tmp_y = 0;
	
	tmp_x = x - 1; tmp_y = y - 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		setDotByPos(board, tmp_x, tmp_y, 1);
	}
	
	tmp_x = x - 0; tmp_y = y - 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		setDotByPos(board, tmp_x, tmp_y, 1);
	}
	
	tmp_x = x + 1; tmp_y = y - 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		setDotByPos(board, tmp_x, tmp_y, 1);
	}
	
	tmp_x = x - 1; tmp_y = y - 0;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		setDotByPos(board, tmp_x, tmp_y, 1);
	}
	
	tmp_x = x - 0; tmp_y = y - 0;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		setDotByPos(board, tmp_x, tmp_y, 1);
	}
	
	tmp_x = x + 1; tmp_y = y - 0;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		setDotByPos(board, tmp_x, tmp_y, 1);
	}
	
	tmp_x = x - 1; tmp_y = y + 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		setDotByPos(board, tmp_x, tmp_y, 1);
	}
	
	tmp_x = x - 0; tmp_y = y + 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		setDotByPos(board, tmp_x, tmp_y, 1);
	}
	
	tmp_x = x + 1; tmp_y = y + 1;
	if (tmp_x >= 0 && tmp_x < C && tmp_y >= 0 && tmp_y < R) {
		setDotByPos(board, tmp_x, tmp_y, 1);
	}
}

void fillNonConfWithMines(char *board, int R, int C) {
	for (int i = 0; i < R * C; i++) {
		if (board[i] == 0) {
			board[i] = 9;
		}
	}
}

int countCleanDots(char *board, int R, int C) {
	int count = 0;
	for (int i = 0; i < R * C; i++) {
		if (board[i] == 1 || board[i] == 2) {
			count++;
		}
	}
	return count;
}

char getDotByPos(char *boardToSet, int x, int y) {
	return boardToSet[y * C + x];
}

void setDotByPos(char *boardToSet, int x, int y, char value) {
	int i = y * C + x;
	boardToSet[y * C + x] = value;
}
