#include<queue>
#include<cstdio>
#include<vector>
#include<cassert>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int L = 55;

char map[L][L];

bool solve(int n, int m, int k) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			map[i][j] = '.';
		}
		map[i][m] = '\0';
	}

	if (k == n * m - 1) {
		// c***
		// ****
		// ****
		// ****
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				map[i][j] = '*';
			}
		}
		map[0][0] = 'c';
		return true;
	}
	
	if (n == 1) {
		// c...***
		for (int i = 0; i < k; ++i) {
			map[0][m - 1 - i] = '*';
		}
		map[0][0] = 'c';
		return true;
	}

	if (n * m - k < 4) {
		return false;
	}

	if (n == 2) {
		// c...*
		// ....*
		if (k % 2 == 1) {
			return false;
		}
		for (int i = 0; i < k / 2; ++i) {
			map[0][m - 1 - i] = map[1][m - 1 - i] = '*';
		}
		map[0][0] = 'c';
		return true;
	}

	for (int r = 2; r <= n; ++r) {
		for (int c = 2; c <= m; ++c) {
			if (n * m - r * c == k) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < m; ++j) {
						if (i >= r || j >= c) {
							map[i][j] = '*';
						}
					}
				}
				map[0][0] = 'c';
				return true;
			}
			if (n * m - r * c > k) {
				int empty = n * m - r * c - k;
				if (empty != 1 && empty < c && r < n) {
					for (int i = 0; i < n; ++i) {
						for (int j = 0; j < m; ++j) {
							if (i >= r || j >= c) {
								map[i][j] = '*';
							}
							if (i == r && j < empty) {
								map[i][j] = '.';
							}
						}
					}
					map[0][0] = 'c';
					return true;
				}
				if (empty != 1 && empty < r && c < m) {
					for (int i = 0; i < n; ++i) {
						for (int j = 0; j < m; ++j) {
							if (i >= r || j >= c) {
								map[i][j] = '*';
							}
							if (i < empty && j == c) {
								map[i][j] = '.';
							}
						}
					}
					map[0][0] = 'c';
					return true;
				}
			}
			if ((n - r) * (m - c) >= k) {
				int cnt = 0, blank = (n - r) * (m - c) - k;
				for (int i = r; i < n; ++i) {
					for (int j = c; j < m; ++j) {
						if (cnt >= blank) {
							map[i][j] = '*';
						}
						++cnt;
					}
				}
				map[0][0] = 'c';
				return true;
			}
		}
	}

	return false;
}

char tmp[L][L];

void flip(int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			tmp[j][i] = map[i][j];
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			map[i][j] = tmp[i][j];
		}
		map[i][n] = '\0';
	}
}

const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, 
		  dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

int num[L][L];
bool vis[L][L];

bool self_check(int n, int m, int k) {
	int cx = -1, cy = -1, cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '*') {
				++cnt;
				continue;
			} else {
				num[i][j] = 0;
				for (int d = 0; d < 8; ++d) {
					int tx = i + dx[d], ty = j + dy[d];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
						num[i][j] += map[tx][ty] == '*';
					}
				}
				if (map[i][j] == 'c') {
					cx = i, cy = j;
				}
			}
		}
	}
	if (cnt != k || cx == -1) {
		return false;
	}
	queue<pair<int, int> > q;
	memset(vis, 0, sizeof(vis));
	if (num[cx][cy] == 0) {
		q.push(make_pair(cx, cy));
	}
	vis[cx][cy] = true;
	while (q.size()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (num[x][y] != 0) {
			continue;
		}
		for (int d = 0; d < 8; ++d) {
			int tx = x + dx[d], ty = y + dy[d];
			if (tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty]) {
				vis[tx][ty] = true;
				if (num[tx][ty] == 0) {
					q.push(make_pair(tx, ty));
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '*' && vis[i][j] || map[i][j] != '*' && !vis[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		static int id = 0;
		printf("Case #%d:\n", ++id);
		bool reverse = n > m;
		if (reverse) {
			swap(n, m);
		}
		bool succ = solve(n, m, k);
		if (!succ) {
			printf("Impossible\n");
		} else {
			if (reverse) {
				flip(n, m);
				swap(n, m);
			}
			if (self_check(n, m, k)) {
				for (int i = 0; i < n; ++i) {
					printf("%s\n", map[i]);
				}
			} else {
				printf("Constructon Error!\n");
				printf("%d %d %d\n", n, m, k);
				for (int i = 0; i < n; ++i) {
					printf("%s\n", map[i]);
				}
				assert(false);
			}
		}
	}
	return 0;
}
