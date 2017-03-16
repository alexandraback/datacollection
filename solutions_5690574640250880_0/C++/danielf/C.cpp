#include <stdio.h>
#include <string.h>

char tab[60][60];

const int dir[][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void ff(int i, int j, int R, int C) {
	if (tab[i][j] != '.') return;
	tab[i][j] = 'F';
	for (int d = 0; d < 8; d++) {
		int ii = i + dir[d][0];
		int jj = j + dir[d][1];
		if (ii < 0 || ii >= R || jj < 0 || jj >= C) continue;
		if (tab[ii][jj] == '*') return;
	}
	for (int d = 0; d < 8; d++) {
		int ii = i + dir[d][0];
		int jj = j + dir[d][1];
		ff(ii, jj, R, C);
	}
}
int t[60][60];
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		printf("Case #%d:\n", t+1);
		int R, C, M;
		scanf("%d %d %d", &R, &C, &M);
		memset(tab, '.', sizeof(tab));
		int r = R;
		int c = C;
		int m = M;
		if (r == 1) {
			printf("c");
			for (int i = 0; i < (c-1) - m; i++) printf(".");
			for (int i = 0; i < m; i++) printf("*");
			printf("\n");
		} else if (c == 1) {
			printf("c\n");
			for (int i = 0; i < (r-1) - m; i++) printf(".\n");
			for (int i = 0; i < m; i++) printf("*\n");
		} else if (m == c*r - 1) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (i == 0 && j == 0) printf("c");
					else printf("*");
				}
				printf("\n");
			}
		} else {
			while (m) {
				if ( (r == 2 || c == 2) && m == 1) {
					tab[0][0] = '*';
					break;
				}
				if (r >= c) {
					if (m >= c) {
						for (int i = 0; i < c; i++) tab[r-1][i] = '*';
						m -= c;
						r--;
					} else {
						for (int i = c-1; i >= 2; i--) {
							if (!m) break;
							tab[r-1][i] = '*';
							m--;
						}
						r--;
					}
				} else {

					if (m >= r) {
						for (int i = 0; i < r; i++) tab[i][c-1] = '*';
						m -= r;
						c--;
					} else {
						for (int i = r-1; i >= 2; i--) {
							if (!m) break;
							tab[i][c-1] = '*';
							m--;
						}
						c--;
					}
				}
			}
			ff(0,0,R,C);
			bool valid = true;
			for (int i = 0; i < R; i++) for (int j = 0; j < C; j++)
				if (tab[i][j] == '.') valid = false;
			if (!valid) printf("Impossible\n");
			else {
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						if (i == 0 && j == 0) printf("c");
						else printf("%c", (tab[i][j] == '*')?'*':'.');
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}
