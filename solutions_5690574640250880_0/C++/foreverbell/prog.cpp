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

int n, m, boom, sz[1 << 25];
bool mine[6][6], vis[6][6];
int num[6][6];

bool in(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

void init() {
	for (int i = 0; i < (1 << 25); ++i) {
		int cnt = 0, tmp = i;
		while (tmp) {
			if (tmp & 1) ++cnt;
			tmp >>= 1;
		}
		sz[i] = cnt;
	}
}

queue<pair<int, int> > Q;
bool check(int mask, int cx, int cy) {
	if (sz[mask] != boom) return false;
	memset(mine, 0, sizeof(mine));
	int tmp = mask;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (tmp & 1) {
				mine[i][j] = true;
				if (cx == i && cy == j) return false;
			}
			tmp >>= 1;
		}			
	}
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

bool work() {
	int lim = n * m; lim = 1 << lim;
	for (int mask = 0; mask < lim; ++mask) {
		for (int x = 1; x <= n; ++x) {
			for (int y = 1; y <= m; ++y) {
				if (check(mask, x, y)) {
					for (int i = 1; i <= n; ++i) {
						for (int j = 1; j <= m; ++j) {
							if (mine[i][j]) printf("*");
							else {
								if (i == x && j == y) printf("c");
								else printf(".");
							}
						}
						printf("\n");
					}
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	init();
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		scanf("%d%d%d", &n, &m, &boom);
		printf("Case #%d:\n", tt);
		if (!work()) puts("Impossible");
	}
	return 0;
}
