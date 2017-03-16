#include <stdio.h>
#include <algorithm>

using namespace std;

char board[60][60];
char board_back[60][60];
int R, C;

int removalCount(int i, int j) {
	int count = 0;
	for(int dr = -1; dr <= 1; dr++) {
		for(int dc = -1; dc <= 1; dc++) {
			int nr  = i+dr, nc = j+dc;
			if (nr < 0 || nr >= R) continue;
			if (nc < 0 || nc >= C) continue;
			if (board[nr][nc] == '*') count++;
		}
	}
	return count;
}

int removeMines(int i, int j) {
	int count = 0;
	for(int dr = -1; dr <= 1; dr++) {
		for(int dc = -1; dc <= 1; dc++) {
			int nr  = i+dr, nc = j+dc;
			if (nr < 0 || nr >= R) continue;
			if (nc < 0 || nc >= C) continue;
			if (board[nr][nc] == '*') count++;
			board[nr][nc] = '.';
		}
	}
	return count;
}

int tryAllocation(int empty) {
	for(int i = 0; i < max(R,C); i++) {
		if (i < R && removalCount(i, 0) <= empty) {
			empty -= removeMines(i, 0);
		}
		if (i < C && removalCount(0, i) <= empty) {
			empty -= removeMines(0, i);
		}
	}
	for(int i = 1; i < R; i++) {
		for(int j = 1; j < C; j++) {
			if (removalCount(i, j) <= empty) {
				empty -= removeMines(i, j);
			}
		}
	}
	return empty;
}

void printBoard() {
	board[0][0] = 'c';
	for(int i = 0; i < R; i++) {
		puts(board[i]);
	}
}

int main() {
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		int M;
		printf("Case #%d:\n", testcase);
		scanf("%d%d%d",&R,&C,&M);
		int empty = R*C-M;

		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				board[i][j] = '*';
			}
			board[i][C] = '\0';
		}

		if (empty == 1) {
			printBoard();
			continue;
		}

		empty = tryAllocation(empty);
		if (empty != 0) {
			puts("Impossible");
			continue;
		}
		printBoard();
	}
	return 0;
}
