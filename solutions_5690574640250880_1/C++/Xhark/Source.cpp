#include <stdio.h>
#include <algorithm>
using namespace std;
char board[64][64];
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		int R, C, M, nM, minRC;
		scanf("%d %d %d", &R, &C, &M);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				board[i][j] = '*';
			}
			board[i][C] = '\0';
		}
		nM = R*C - M;
		minRC = min(R, C);
		bool possible = false;
		
		if (minRC == 1 || minRC == 2 || nM == 1) {
			if (minRC == 1 || nM % 2 == 0 && nM > 2 || nM == 1) {
				possible = true;

				if (R == 2) {
					for (int j = 0; j < C; j++) {
						for (int i = 0; i < R; i++) {
							if (nM>0) {
								board[i][j] = '.';
								nM--;
							}
						}
					}
				}
				else {
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							if (nM>0) {
								board[i][j] = '.';
								nM--;
							}
						}
					}
				}
			}
		}
		else {
			if (nM > 2 && nM % 2 == 0) {
				possible = true;
				nM -= 4;
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						board[i][j] = '.';
					}
				}
			}
			else if (nM > 8 && nM % 2 == 1) {
				possible = true;
				nM -= 9;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						board[i][j] = '.';
					}
				}
			}

			if (possible) {
				for (int j = 0; j < C; j++) {
					if (nM > 0 && board[0][j] == '*' && board[1][j] == '*') {
						board[0][j] = board[1][j] = '.';
						nM -= 2;
					}
				}

				for (int i = 0; i < R; i++) {
					if (nM > 0 && board[i][0] == '*' && board[i][1] == '*') {
						board[i][0] = board[i][1] = '.';
						nM -= 2;
					}
				}
				
				for (int s = 0; s <= R + C; s++) {
					for (int i = 0; i < R; i++) {
						int j = s - i;
						if (0 <= j && j < C) {
							if (nM > 0 && board[i][j] == '*') {
								board[i][j] = '.';
								nM--;
							}
						}
					}
				}
			}
		}
		static int cs = 1;
		printf("Case #%d:\n", cs++);
		if (possible) {
			board[0][0] = 'c';
			for (int i = 0; i < R; i++)
				printf("%s\n", board[i]);
		}
		else {
			printf("Impossible\n");
		}
	}
	return 0;
}