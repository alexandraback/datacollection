#include <stdio.h>
#include <stdlib.h>

int fieldCheck(char**, int, int, int, int, int);

int main (void) {
	int a, b;
	
	int cases;
	int currentCase;
	
	int R;
	int C;
	int M;
	int possible;
	
	char** board;

	scanf("%d", &cases);
	for (currentCase = 1; currentCase <= cases; currentCase++) {
		scanf("%d %d %d", &R, &C, &M);

		board = (char **) malloc (R*sizeof(char*));
		for (a = 0; a < R; a++) {
			board[a] = (char *) malloc (C*sizeof(char*));
		}
		
		for (a = 0; a < R; a++) {
			for (b = 0; b < C; b++) {
				board[a][b] = '.';
			}
		}
		board[R-1][C-1] = 'c';
		
		possible = fieldCheck(board, R, C, M, 0, 0);
		
		printf("Case #%d:\n", currentCase);
		if (possible == 1) {
			printf("Impossible\n");
		}
		else if (possible == 0) {
			for (a = 0; a < R; a++) {
				for (b = 0; b < C; b++) {
					printf("%c", board[a][b]);
				}
				printf("\n");
			}
		}
		
		for (a = 0; a < R; a++) {
			free(board[a]);
		}
		free(board);
	}
	return 0;
}

int fieldCheck(char** board, int R, int C, int M, int curR, int curC) {
	int a;
	
	int possible = 0;
	
	if (M == 0) {
		return possible;
	}
	
	else if (M == R*C) {
		return 1;
	}
	
	else if (M == 3 && R-curR == 2 && C-curC == 2) {
		board[curR][curC] = '*';
		board[curR][curC+1] = '*';
		board[curR+1][curC] = '*';
		return possible;
	}
	
	else if (M < 3 && R-curR == 2 && C-curC == 2) {
		return 1;
	}
	
	else if (R - curR >= C - curC) {
		if (M >= C - curC) {
			for (a = curC; a < C; a++) {
				board[curR][a] = '*';
				M--;
			}
			curR++;
			possible = fieldCheck(board, R, C, M, curR, curC);
			return possible;
		}
		
		else if (M < C - curC) {
			if (C - curC > 3) {
				for (a = curC; M > 0; a++) {
					if (a != C-2) {
						board[curR][a] = '*';
						M--;
					}
					else {
						board[curR+1][curC] = '*';
						M--;
					}
				}
				return possible;
			}
			
			else if (C - curC == 3) {
				for (a = curC; M > 0; a++) {
					if (a != C-2) {
						board[curR][a] = '*';
						M--;
					}
					else {
						if (curR+1 != R-2) {
							board[curR+1][curC] = '*';
							M--;
						}
						else {
							return 1;
						}
					}
				}
				return possible;
			}
			
			else if (C - curC == 2) {
				return 1;
			}
		}
	}
	
	else if (R - curR < C - curC) {
		if (M >= R - curR) {
			for (a = curR; a < R; a++) {
				board[a][curC] = '*';
				M--;
			}
			curC++;
			possible = fieldCheck(board, R, C, M, curR, curC);
			return possible;
		}
		
		else if (M < R - curR) {
			if (R - curR > 3) {
				for (a = curR; M > 0; a++) {
					if (a != R-2) {
						board[a][curC] = '*';
						M--;
					}
					else {
						board[curR][curC+1] = '*';
						M--;
					}
				}
				return possible;
			}
			
			else if (R - curR == 3) {
				for (a = curR; M > 0; a++) {
					if (a != R-2) {
						board[a][curC] = '*';
						M--;
					}
					else {
						if (curC+1 != C-2) {
							board[curR][curC+1] = '*';
							M--;
						}
						else {
							return 1;
						}
					}
				}
				return possible;
			}
			
			else if (R - curR == 2) {
				return 1;
			}
		}
	}
	
	return possible;
}