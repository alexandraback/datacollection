#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#define RD(x)      scanf("%d", &x)
#define REP(i, n)  for (int i=0; i<(n); i++)
#define REP1(i, n) for (int i=1; i<=(n); i++)
#define pii        pair<int, int>
#define mp         make_pair
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
#define  N   111
#define  M   22222
#define  eps 1e-9
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFll
#define  mod 1000000007ll
#define  LL  long long
LL n, m, K;
int is[30][30];
bool ontheborder(int i, int j) {
	return i == 0 || i == n-1 || j == 0 || j == m-1;
}
bool in(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int getans() {
	static bool flag[30][30];
	memset(flag, 0, sizeof flag);
	queue<pii> que;
	REP(i, n) REP(j, m) if (ontheborder(i, j) && is[i][j] == 0) {
		flag[i][j] = true;
		que.push(mp(i, j));
	}
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		REP(d, 4) {
			int xx = x + dx[d], yy = y + dy[d];
			if (in(xx, yy) == false)
				continue;
			if (flag[xx][yy] == false && is[xx][yy] == 0) {
				flag[xx][yy] = true;
				que.push(mp(xx, yy));
			}
		}
	}
	int ret = 0;
	REP(i, n) REP(j, m) if (flag[i][j] == false) ret++;
	return ret;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T; cin >> T;
	REP1(TT, T) {
		cin >> n >> m >> K;
		int ans = inf;
		REP(i, 1<<(n*m)) {
			int cnt = 0;
			REP(j, n*m) {
				int y = j % m;
				int x = j / m;
				is[x][y] = (i >> j) & 1;
				if (is[x][y])
					cnt++;
			}
			if (cnt >= ans)
				continue;
			if (getans() >= K)
				ans = min(ans, cnt);
		}
		cout << "Case #" << TT << ": " << ans << endl;
	}

	return 0;
}
