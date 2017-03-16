#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

int low[128][128], hi[128][128];
int H, n, m;
const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

bool can(int x0, int y0, int x1, int y1, int waterLevel)
{
	if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) return false;
	if (max(max(low[y0][x0], waterLevel), low[y1][x1]) > hi[y1][x1] - 50) return false;
	if (low[y1][x1] > hi[y0][x0] - 50) return false;
	return true;
}

int dp[128][128][128]; // time % 128, y, x
int visited[128][128];

void dfs1(int x, int y)
{
	visited[y][x] = 1;
	FOR(i, 4) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (can(x, y, nx, ny, H) && !visited[ny][nx])
			dfs1(nx, ny);
	}
}



void solve(void)
{
	scanf("%d%d%d", &H, &n, &m);
	FOR(i, n) FOR(j, m) scanf("%d", &hi[i][j]);
	FOR(i, n) FOR(j, m) scanf("%d", &low[i][j]);
	memset(dp, 0, sizeof(dp));
	memset(visited, 0, sizeof(visited));
	dfs1(0, 0);
	FOR(i, n) FOR(j, m) if (visited[i][j]) dp[0][i][j] = 1;
	for (int T = 0;; T++) {
		int ct = T%128;
		//
		FOR(y, n) FOR(x, m) if (dp[ct][y][x]) {
			if (y == n - 1 && x == m - 1) {
				printf("%d.%d\n", T/10, T%10);
				return;
			}
			dp[(T + 1) % 128][y][x] = 1;
			FOR(di, 4) {
				int nx = x + dir[di][0];
				int ny = y + dir[di][1];
				if (can(x, y, nx, ny, H - T)) {
					if (H - T - low[y][x] >= 20)
						dp[(T + 10) % 128][ny][nx] = 1;
					else
						dp[(T + 100) % 128][ny][nx] = 1;
				}
			}
			
		}
		//
		memset(dp[ct], 0, sizeof(dp[ct]));
	}
}

int main(void)
{
	//freopen("/home/vesko/gcj/b.in", "rt", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
