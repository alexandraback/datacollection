#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

int n, m, h;
int f[110][110];
int c[110][110];

char d[110][110][11000];
int used[110][110];

int is_in(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < m);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
	if (used[x][y]) return;

	used[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		if (is_in(x + dx[i], y + dy[i])) {
			int tx = x + dx[i];
			int ty = y + dy[i];

			int cl = c[x][y];
			int fl = max(f[x][y], h);
			if (c[tx][ty] - f[tx][ty] >= 50) {
				if (c[tx][ty] - fl >= 50 && cl - f[tx][ty] >= 50) {
					dfs(tx, ty);
				}
			}
		}
	}
}

int current[110][110];

void solve(int testcase) {
	printf("Case #%d: ", testcase);

	scanf("%d%d%d", &h, &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &c[i][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &f[i][j]);
		}
	}

	memset(d, 0, sizeof(d));
	memset(used, 0, sizeof(used));
	dfs(0, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[i][j][0] = used[i][j];
		}
	}

	int lv = h;
	for (int iter = 0; iter < lv + 100; ++iter) {
		if (d[n - 1][m - 1][iter]) {
			printf("%d.%d\n", iter / 10, iter % 10);
			return;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (d[i][j][iter]) {
					d[i][j][iter + 1] = 1;
					for (int k = 0; k < 4; ++k) {
						if (is_in(i + dx[k], j + dy[k])) {
							int tx = i + dx[k];
							int ty = j + dy[k];

							int cl = c[i][j];
							int fl = max(f[i][j], h);
							if (c[tx][ty] - f[tx][ty] >= 50) {
								if (c[tx][ty] - fl >= 50 && cl - f[tx][ty] >= 50) {
									if (h - f[i][j] >= 20) {
										d[tx][ty][iter + 10] = 1;
									} else {
										d[tx][ty][iter + 100] = 1;
									}
								}
							}
						}
					}
				}
			}
		}
		--h;
	}

	memset(current, -1, sizeof(current));

	queue <pair<int, int> > q;
	vector <pair<int, pair<int, int> > > pos;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = lv; k < lv + 100; ++k) {
				if (d[i][j][k]) {
					pos.push_back(make_pair(k, make_pair(i, j)));
					current[i][j] = k;
					break;
				}
			}
		}
	}
	sort(pos.begin(), pos.end());
	for (int i = 0; i < pos.size(); ++i) {
		q.push(pos[i].second);
	}

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k) {
			if (is_in(i + dx[k], j + dy[k])) {
				int tx = i + dx[k];
				int ty = j + dy[k];
				if (current[tx][ty] != -1) continue;

				int cl = c[i][j];
				int fl = max(f[i][j], -1);
				if (c[tx][ty] - f[tx][ty] >= 50) {
					if (c[tx][ty] - fl >= 50 && cl - f[tx][ty] >= 50) {
						current[tx][ty] = current[i][j] + 100;
						q.push(make_pair(tx, ty));
					}
				}
			}
		}
	}

	printf("%d.%d\n", current[n - 1][m - 1] / 10, current[n - 1][m - 1] % 10);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;

	cin >> tests;

	for (int t = 1; t <= tests; ++t) {
		solve(t);
		cerr << t << endl;
	}

	return 0;
}