#include <stdio.h>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, j, p, s, k;
int a[9];
int c[19][19][19];
int mx;

int q[19][19], w[19][19], e[19][19];
int d[19][19][19];

// A B
// A C
// B C

void recall(int jj, int pp, int ss, int lev) {
	if (jj > j) {
		if (mx < lev) {
			mx = lev;
			for (int i = 1; i <= 10; i++) {
				for (int jjj = 1; jjj <= 10; jjj++) {
					for (int kk = 1; kk <= 10; kk++) {
						c[i][jjj][kk] = d[i][jjj][kk];
					}
				}
			}
		}
	}
	else if (ss > s) {
		recall(jj, pp + 1, 1, lev);
	}
	else if (pp > p) {
		recall(jj + 1, 1, 1, lev);
	}
	else {
		if (q[jj][pp] < k && w[jj][ss] < k && e[pp][ss] < k) {
			q[jj][pp]++;
			w[jj][ss]++;
			e[pp][ss]++;
			d[jj][pp][ss] = 1;
			recall(jj, pp, ss + 1, lev + 1);
			d[jj][pp][ss] = 0;
			q[jj][pp]--;
			w[jj][ss]--;
			e[pp][ss]--;
		}
		recall(jj, pp, ss + 1, lev);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int tt = 1; tt <= n; tt++) {
		scanf("%d %d %d %d", &j, &p, &s, &k);

		mx = 0;
		for (int i = 1; i <= 10; i++) {
			for (int jj = 1; jj <= 10; jj++) {
				q[i][jj] = w[i][jj] = e[i][jj] = 0;
				for (int kk = 1; kk <= 10; kk++) {
					c[i][jj][kk] = 0;
				}
			}
		}

		recall(1, 1, 1, 0);

		/*
		scanf("%d %d %d %d", &j, &p, &s, &k);

		for (int i = 1; i <= j; i++) {
			for (int j = 1; j <= p; j++) {
				for (int k = 1; k <= s; k++) {
					c[i][j][k] = 0;
				}
			}
		}

		for (int i = 1; i <= j; i++) {
			for (int j = 1; j <= p; j++) {
				for (int k = 1; k <= s; k++) {
					c[i][j][k] = 0;
				}
			}
		}*/

		printf("Case #%d: %d\n", tt, mx);
		for (int i = 1; i <= 10; i++) {
			for (int jj = 1; jj <= 10; jj++) {
				for (int kk = 1; kk <= 10; kk++) {
					if (c[i][jj][kk] > 0) {
						printf("%d %d %d\n", i, jj, kk);
					}
				}
			}
		}
	}

	return 0;
}