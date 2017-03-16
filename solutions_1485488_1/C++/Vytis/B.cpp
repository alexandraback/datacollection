#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define FILE_IN  "B-large.in"
#define FILE_OUT "B-large.out"

#define MAXN 102

#define PASS 50
#define GOH 20
#define GO 10
#define DRAG 100

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef set<pipii> spipii;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int h, n, m;
int c[MAXN][MAXN];
int f[MAXN][MAXN];

int e[MAXN][MAXN];

void solve() {
	scanf("%d%d%d", &h, &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d\n", &c[i][j]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d\n", &f[i][j]);
	fill(e[0], e[MAXN], -1);
	e[0][0] = 0;
	spipii S;
	S.insert(pipii(0, pii(0, 0)));
	while (!S.empty()) {
		pii xy = S.begin()->second;
		int x = xy.first, y = xy.second;
		S.erase(S.begin());
		for (int d = 0; d < 4; ++d) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m)
				continue;
			if (c[xx][yy] - f[xx][yy] < PASS)
				continue;
			if (c[x][y] - f[xx][yy] < PASS || c[xx][yy] - f[x][y] < PASS)
				continue;
			int go = max(h - (c[xx][yy] - 50), e[x][y]);
			int hh = h - go;
			int t = hh - f[x][y] < GOH ? DRAG : GO;
			if (go == 0)
				t = 0;
			if (e[xx][yy] < 0 || e[xx][yy] > go + t) {
				S.erase(pipii(e[xx][yy], pii(xx, yy)));
				e[xx][yy] = go + t;
				S.insert(pipii(e[xx][yy], pii(xx, yy)));
			}
		}
	}
	printf("%.1lf\n", e[n-1][m-1] / 10.0);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
