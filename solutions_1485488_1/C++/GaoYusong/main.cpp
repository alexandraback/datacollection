#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <list>

using namespace std;

//GyS Loves Algorithm
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define mk(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define rep(x, n) for (int x = 0; x < n; x++)
#define range(x, a, b)for (int x = a; x <= b; x++)
#define sz(x) x.size()
#define setv(x, y) memset(x, y, sizeof(x))
#define repi(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pl() printf("\n")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

double dp[110][110];
int up[110][110], down[110][110];
const double inf = 1e100;
int H, n, m;
bool inq[110][110];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
const double E = 1e-12;
bool vis[110][110];

inline
int dblcmp(double x)
{
	if (x > -E && x < E)
		return 0;
	return x > 0 ? 1 : -1;
}

double SPFA()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = inf;
		}
	}

	queue<pii> que;
	dp[0][0] = 0;
	memset(inq, false, sizeof(inq));
	memset(vis, false, sizeof(vis));
	inq[0][0] = true;
	que.push(mk(0, 0));
	vis[0][0] = true;

	while (!que.empty()) {
		pii xx = que.front();
		int x = xx.X, y = xx.Y;
		inq[x][y] = false;
		que.pop();
		double level = H;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (up[nx][ny] - down[nx][ny] >= 50) {
					double curr = level;
					double t = 0;
					if (dblcmp(up[nx][ny] - level - 50.0) >= 0) {
						if (up[nx][ny] - down[x][y] >= 50
								&& up[x][y] - down[nx][ny] >= 50) {
							if (dp[nx][ny] > dp[x][y] + t) {
								dp[nx][ny] = dp[x][y] + t;
								vis[nx][ny] = true;
								if (!inq[nx][ny]) {
									inq[nx][ny] = true;
									que.push(mk(nx, ny));
								}
							}
						}
					}
				}
				/*
				if (!inq[nx][ny]) {
					inq[nx][ny] = true;
					que.pb(mk(nx, ny));
				}
				*/
			}
		}
	}
	memset(inq, false, sizeof(inq));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) {
				que.push(mk(i, j));
				inq[i][j] = true;
			}
		}
	}

	while (!que.empty()) {
		pii xx = que.front();
		int x = xx.X, y = xx.Y;
		inq[x][y] = false;
		que.pop();
		double level = max(H - dp[x][y] * 10, 0.0);
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				double t = 0;
				if (up[nx][ny] - down[nx][ny] >= 50) {
					double curr = level;
					if (dblcmp(up[nx][ny] - level - 50.0) < 0) {
						t += (level - (up[nx][ny] - 50)) / 10.0;
						curr = up[nx][ny] - 50;
					}
					if (up[nx][ny] - down[x][y] >= 50
							&& up[x][y] - down[nx][ny] >= 50) {
						if (dblcmp(curr - down[x][y] - 20) >= 0) {
							t += 1;
						} else {
							t += 10;
						}
						if (dp[nx][ny] > dp[x][y] + t) {
							dp[nx][ny] = dp[x][y] + t;
							if (!inq[nx][ny]) {
								inq[nx][ny] = true;
								que.push(mk(nx, ny));
							}
						}
					}
				}
				/*
				if (!inq[nx][ny]) {
					inq[nx][ny] = true;
					que.pb(mk(nx, ny));
				}
				*/
			}
		}
	}
	return dp[n - 1][m - 1];
}

int main()
{
	int T, cn = 0;

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &H, &n, &m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &up[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &down[i][j]);
			}
		}
		double ret = SPFA();
		printf("Case #%d: %.10f\n", ++cn, ret);
	}
	return 0;
}
