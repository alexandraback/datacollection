#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cassert>

typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);

using namespace std;

int n, m, boom; 
bool in(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool mine[60][60], vis[60][60];
int num[60][60];

bool check(int cx, int cy) {
	queue<pair<int, int> > Q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			num[i][j] = 0;
			for (int dx = -1; dx <= 1; ++dx) {
				for (int dy = -1; dy <= 1; ++dy) {
					int x = i + dx, y = j + dy;
					if (in(x, y) && mine[x][y]) ++num[i][j];
				}
			}
		}
	}
	int tot = n * m - boom;
	memset(vis, 0, sizeof vis); 
	vis[cx][cy] = true;
	Q.push(make_pair(cx, cy));
	while (!Q.empty()) {
		pair<int, int> t = Q.front();
		Q.pop(); --tot;
		int i = t.first, j = t.second;
		if (num[i][j]) continue;
		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) {
				int x = i + dx, y = j + dy;
				if (x == i && y == j) continue;
				if (in(x, y) && !vis[x][y] && !mine[x][y]) {
					vis[x][y] = true;
					Q.push(make_pair(x, y));
				}
			}
		}
	}
	return tot == 0;
}

bool construct1(int cnt, int n2, int m2) {
	int level = 1;
	if (n2 * m2 < cnt) return false;
	memset(mine, 0, sizeof(mine));
	while (true) {
		if (n < m) {
			for (int i = level; i <= n2 && cnt; ++i) {
				mine[i][level] = true;
				--cnt;
			}
			for (int i = level + 1; i <= m2 && cnt; ++i) {
				mine[level][i] = true;
				--cnt;
			}
		} else {
			for (int i = level; i <= m2 && cnt; ++i) {
				mine[level][i] = true;
				--cnt;
			}
			for (int i = level + 1; i <= n2 && cnt; ++i) {
				mine[i][level] = true;
				--cnt;
			}
		}
		++level;
		if (cnt == 0) break;
	}
	return check(n, m);
}

bool construct2(int cnt, int n2, int m2) {
	if (n2 * m2 < cnt) return false;
	memset(mine, 0, sizeof(mine));
	for (int i = 1; i <= n2 && cnt; ++i) {
		for (int j = 1; j <= m2 && cnt; ++j) {
			mine[i][j] = true;
			--cnt;
		}
	}
	return check(n, m);
}

bool construct3(int cnt, int n2, int m2) {
	if (n2 * m2 < cnt) return false;
	memset(mine, 0, sizeof(mine));
	for (int j = 1; j <= m2 && cnt; ++j) {
		for (int i = 1; i <= n2 && cnt; ++i) {
			mine[i][j] = true;
			--cnt;
		}
	}
	return check(n, m);
}

bool construct4(int cnt) {
	int x = 0;
	for (int i = 2; i <= n; ++i) {
		if (i * i == n * m - cnt) {
			x = i;
			break;
		}
	}
	if (x == 0) return false;
	memset(mine, 0, sizeof(mine));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) mine[i][j] = true;
	}
	for (int i = n; i >= n - x + 1; --i) {
		for (int j = m; j >= m - x + 1; --j) {
			mine[i][j] = false;
		}
	}
	return check(n, m);
}

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		scanf("%d%d%d", &n, &m, &boom);
		printf("Case #%d:\n", tt);
		bool found = false;
		for (int n2 = n - 2; n2 <= n; n2 += 2) {
			for (int m2 = m - 2; m2 <= m; m2 += 2) {
				if (n2 >= 1 && m2 >= 1) {
					if (construct1(boom, n2, m2)) {
						found = true;
						break;
					}
					if (construct2(boom, n2, m2)) {
						found = true;
						break;
					}
					if (construct3(boom, n2, m2)) {
						found = true;
						break;
					}
				}
			}
		}
		if (!found) found = construct4(boom);
		if (!found) puts("Impossible");
		else {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					if (mine[i][j]) printf("*");
					else {
						if (i == n && j == m) printf("c");
						else printf(".");
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
