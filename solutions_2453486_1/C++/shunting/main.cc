#include <stdio.h>

char board[100][100];

bool
check(char x) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (board[i][j] != x && board[i][j] != 'T') {
				break;
			}
		}
		if (j == 4) 
			return true;
	}
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {
			if (board[i][j] != x && board[i][j] != 'T') {
				break;
			}
		}
		if (i == 4) 
			return true;
	}
	for (i = 0; i < 4; i++) {
		j = i;
		if (board[i][j] != x && board[i][j] != 'T') 
			break;
	}
	if (i == 4)
		return true;
	
	for (i = 0; i < 4; i++) {
		j = 3 - i;
		if (board[i][j] != x && board[i][j] != 'T') 
			break;
	}
	return i == 4;
}

int 
nempty() {
	int nem = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			nem += (board[i][j] == '.');
		}
	}
	return nem;
}

int
main(void) {
	int T, seq;

	scanf("%d", &T);
	for (seq = 1; seq <= T; seq++) {
		for (int i = 0; i < 4; i++) {
			scanf("%s", board[i]);
		}
		printf("Case #%d: ", seq);
		if (check('X')) {
			printf("X won");
		} else if (check('O')) {
			printf("O won");
		} else if (nempty() == 0) {
			printf("Draw");
		} else {
			printf("Game has not completed");
		}
		printf("\n");
	}
	return 0;
}
