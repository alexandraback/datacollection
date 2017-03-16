/* 12:52 */
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int 
stridesize(int base) {
	return base * 2 + 1;
}

// check (y = x + base & y = -x + base)
int 
inside(int base, int X, int Y) {
	return Y <= X + base && Y <= -X + base;
}

double mat[100][100];

int 
main(void) {
	int T, seq;
	int N;
	int X, Y;
	int base;
	int rest;
	int ss;
	double ans;

	scanf("%d", &T);
	for (seq = 1; seq <= T; seq++) {
		scanf("%d%d%d", &N, &X, &Y);
		base = 0;
		rest = N;

		while (rest >= (ss = stridesize(base))) {
			rest -= ss;
			base += 2;
		}

		if (N == 1) {
			if (X == 0 && Y == 0) {
				ans = 1;
			} else {
				ans = 0;
			}
			goto end;
		}

		// check (y = x + base & y = -x + base)
		if (inside(base - 2, X, Y)) {
			ans = 1;
		} else if (!inside(base, X, Y)) {
			ans = 0;
		} else { 
			int need = Y + 1;
			int limit = base;

			if (need > rest) {
				ans = 0;
				goto end;
			}

			memset(mat, 0, sizeof(mat));
			mat[0][0] = 1;
			for (int i = 1; i <= rest; i++) {
				for (int j = 0; j <= i && j <= limit; j++) {
					int k = i - j;
					if (k > limit) {
						continue;
					}
					// calc (j, k)
					double p = 0;
					if (j > 0) {
						double t = mat[i - 1][j - 1];
						if (k == limit) {
						} else {
							t = t / 2;	
						}
						p += t;
					}
					if (k > 0) {
						double t = mat[i - 1][j];
						if (j == limit) {
						} else {
							t = t / 2;
						}
						p += t;
					}
					mat[i][j] = p;
				}
			}
			// HERE
			ans = 0;
			for (int i = need; i <= limit; i++) {
				ans += mat[rest][i];
			}

			if (ans > 1) {
				printf("N %d X %d Y %d\n", N, X, Y);
				printf("Base %d rest %d\n", base, rest);
				for (int i = need; i <= limit; i++) {
					printf("i %d %f\n", i, mat[rest][i]);
				}
				printf("Err %f\n", ans); exit(1); // TODO
			}
		}
	end:
		printf("Case #%d: %f\n", seq, ans);
	}

	return 0;
}
