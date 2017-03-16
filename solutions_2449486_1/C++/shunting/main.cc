#include <stdio.h>
#include <algorithm>

int board[100][100];
int rlist[100];
int clist[100];

int
main(void) {
	int T, seq;
	scanf("%d", &T);
	
	int R, C;
	for (seq = 1; seq <= T; seq++) {
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				scanf("%d", &board[i][j]);
			}
		}

		int maxv, minv;
		for (int i = 0; i < R; i++) {
			maxv = 0;
			for (int j = 0; j < C; j++) {
				if (board[i][j] > maxv) 
					maxv = board[i][j];
			}
			rlist[i] = maxv;
		}

		for (int j = 0; j < C; j++) {
			maxv = 0;
			for (int i = 0; i < R; i++) {
				if (board[i][j] > maxv)
					maxv = board[i][j];
			}
			clist[j] = maxv;
		}

		printf("Case #%d: ", seq);
		int valid = true;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (std::min(rlist[i], clist[j]) != board[i][j]) {
					valid = false;
					goto out;
				}
			}
		}
	out:
		printf("%s\n", valid ? "YES" : "NO");
	}
	return 0;
}
