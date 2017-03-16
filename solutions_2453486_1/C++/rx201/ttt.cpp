#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int uni(int x, int y) {
	if (x == '.' || y == '.')
		return '.';
	if (x == 'T')
		return y;
	if (y == 'T')
		return x;
	if (x == y)
		return x;
	else
		return '.';
}

char* solve(int board[4][4]) {
	for(int i=0; i<4; i++) {
		int row = board[i][0];
		int col = board[0][i];
		
		int diag0 = board[0][0];
		int diag1 = board[0][3];
		
		for(int j=1; j<4; j++) {
			row = uni(row, board[i][j]);
			col = uni(col, board[j][i]);
			diag0 = uni(diag0, board[j][j]);
			diag1 = uni(diag1, board[j][3-j]);
		}
		if (row == 'X' || col == 'X' || diag0 == 'X' || diag1 == 'X')
			return "X won";
		if (row == 'O' || col == 'O' || diag0 == 'O' || diag1 == 'O')
			return "O won";
	}
	for(int i=0; i<4; i++) 
		for(int j=0; j<4; j++)
			if (board[i][j] == '.')
				return "Game has not completed";
	return "Draw";
}

int main(int argc, char* argv[]) {
	int T;
	int board[4][4];

	setbuf(stdout, NULL);
		
	scanf("%d\n", &T);
	for(int t=0; t<T; t++) {
		char s[6];
		for(int i=0; i<4; i++) {
			gets(s);
			for(int j=0; j<4; j++) board[i][j] = s[j];
		}
		gets(s);
		/*
		for(int i=0; i<4; i++)  {
			for(int j=0; j<4; j++) 
				printf("%c", board[i][j]);
			printf("\n");
		}
		*/
		printf("Case #%d: %s\n", t+1, solve(board));
	}
	
	return 0;
}
