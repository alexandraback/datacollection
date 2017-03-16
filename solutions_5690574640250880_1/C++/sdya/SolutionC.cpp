#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 60;
int a[maxN][maxN], b[maxN][maxN];
bool used[maxN][maxN];
int n, m, k;

bool isMine(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	return a[x][y] == 1;
}

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
	if (used[x][y]) {
		return ;
	}

	if (isMine(x, y)) {
		return ;
	}

	used[x][y] = true;

	if (b[x][y] == 0) {
		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) {
				if (isValid(x + dx, y + dy)) {
					dfs(x + dx, y + dy);
				}
			}
		}
	}
}

bool checkInitial(int x, int y) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			used[i][j] = false;
		}
	}

	dfs(x, y);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 1) {
				continue;
			}
			if (!used[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool check(int& x, int& y) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			b[i][j] = 0;
			for (int dx = -1; dx <= 1; ++dx) {
				for (int dy = -1; dy <= 1; ++dy) {
					if (isMine(i + dx, j + dy)) {
						++b[i][j];
					}
				}
			}
		}
	}

	x = y = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 0 && checkInitial(i, j)) {
				x = i;
				y = j;
				return true;
			}
		}
	}
	return false;
}

bool have_answer = false;
bool no_answer = false;
int start_time;
int iters;

void rec(int filled, int mines) {
	++iters;
	if (iters % 10000 == 0) {
		if ((double)(clock() - start_time) / (double)(CLOCKS_PER_SEC) > 5.0) {
			no_answer = true;
		}
	}
	if (have_answer || no_answer) {
		return ;
	}
	if (filled == n * m) {
		if (mines < k) {
			return ;
		}
		int x, y;
		have_answer |= check(x, y);
		if (have_answer) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (a[i][j] == 1) {
						printf("*");
					} else if (i == x && j == y) {
						printf("c");
					} else {
						printf(".");
					}
				}
				printf("\n");
			}
			return ;
		}
		return ;
	}

	int x = filled / m;
	int y = filled % m;

	if (mines < k) {
		a[x][y] = 1;
		//int u, v;
		//if (check(u, v)) {
			rec(filled + 1, mines + 1);
		//}
		a[x][y] = 0;
	}

	rec(filled + 1, mines);
}

void solve(int test) {
	printf("Case #%d:\n", test);
	have_answer = false;

	scanf("%d%d%d", &n, &m, &k);

	int sx = -1, sy = -1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= m; ++j) {
			if (i * j + k == n * m) {
				sx = i;
				sy = j;
			}
		}
	}

	if (sx != -1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 && j == 0) {
					printf("c");
				} else if (i < sx && j < sy) {
					printf(".");
				} else {
					printf("*");
				}
			}
			printf("\n");
		}
		return ;
	}

	/*if (n >= 2 && m >= 2 && k <= (n - 2) * (m - 2)) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int index = i * (m - 2) + j;
				if (i < (n - 2) && j < (m - 2) && index < k) {
					printf("*");
				} else if (i == 0 && j == m - 1) {
					printf("c");
				} else {
					printf(".");
				}
			}
			printf("\n");
		}
		return ;
	}*/

	start_time = clock();
	iters = 0;
	no_answer = false;
	rec(0, 0);
	if (!have_answer) {
		printf("Impossible\n");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}