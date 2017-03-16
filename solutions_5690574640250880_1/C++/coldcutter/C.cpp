/* Author: coldcutter
 * Problem: C. Minesweeper Master
 * Tags:
 */
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
using namespace std;

const int N = 55;

int n, m, k, c[N];
char a[N][N];

bool check(int t, int r, int low, int high) {
	for (int i = 1; i <= t; ++i) {
		c[i] = r / t;
	}
	r -= c[1] * t;
	for (int i = 1; r > 0; ) {
		++c[i];
		--r;
		i = (i == t ? 1 : i + 1);
	}
	return 1;
}

void solve() {
	bool find = 0;
	if (k == n * m - 1) {
		find = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				a[i][j] = '*';
			}
		}
	}
	if (m == 1) {
		find = 1;
		for (int i = 1; i <= n; ++i) {
			a[i][1] = (i <= k ? '*' : '.');
		}
	} else if (n == 1) {
		find = 1;
		for (int j = 1; j <= m; ++j) {
			a[1][j] = (j <= k ? '*' : '.');
		}
	} else {
		for (int i = 0; i <= n - 2 && !find; ++i) {
			for (int j = 0; j <= m - 2 && !find; ++j) {
				int r = k - i * m - 2 * j;
				if (r < 0) {
					break;
				}
				if (j * (n - i - 2) <= r && r <= (m - 2) * (n - i - 2)) {
					if (check(n - i - 2, r, j, m - 2)) {
						find = 1;
						for (int x = 1; x <= n; ++x) {
							for (int y = 1; y <= m; ++y) {
								if (x <= i) {
									a[x][y] = '*';
								} else if (x <= n - 2) {
									a[x][y] = (y <= c[x - i] ? '*' : '.');
								} else {
									a[x][y] = (y <= j ? '*' : '.');
								}
							}
						}
					}
				}
			}
		}
	}
	if (!find) {
		puts("Impossible");
	} else {
		a[n][m] = 'c';
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				printf("%c", a[i][j]);
			}
			puts("");
		}
	}
}

int main() {
//	freopen("C.in", "r", stdin);
	int test;
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase) {
		printf("Case #%d:\n", kase);
		scanf("%d %d %d", &n, &m, &k);
		solve();
	}
	return 0;
}

