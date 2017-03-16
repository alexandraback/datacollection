/*
 * a.cpp
 *
 *  Created on: May 6, 2012
 *      Author: lyl
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

const int maxn = 110, maxt = 10010;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int hei, n, m, fl[maxn][maxn], cl[maxn][maxn];
bool dp[maxt][maxn][maxn];

bool onboard(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool pass(int i, int j, int x, int y, int hh) {
	int f1 = fl[i][j];
	int f2 = fl[x][y];
	int c1 = cl[i][j];
	int c2 = cl[x][y];

	if (hh <= c2 - 50 && f1 <= c2 - 50 && f2 <= c2 - 50 &&
			f2 <= c1 - 50)
		return true;
	else
		return false;
}

int qx[maxt], qy[maxt], dist[maxn][maxn];

void bfs() {
	qx[1] = 0;
	qy[1] = 0;
	int op = 1;
	int cl = 0;
	while (op > cl) {
		cl++;
		int x = qx[op];
		int y = qy[op];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (onboard(nx, ny) && pass(x, y, nx, ny, hei) && !dp[0][nx][ny]) {
				dp[0][nx][ny] = true;
				op++;
				qx[op] = nx;
				qy[op] = ny;
			}
		}
	}
}

void shortestpath() {
	qx[1] = n - 1;
	qy[1] = m - 1;
	memset(dist, -1, sizeof(dist));
	dist[n - 1][m - 1] = 0;
	int op = 1;
	int cl = 0;
	while (op > cl) {
		cl++;
		int x = qx[op];
		int y = qy[op];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (onboard(nx, ny) && pass(nx, ny, x, y, hei) && dist[nx][ny] == -1) {
				dist[nx][ny] = dist[x][y] + 100;
				//printf("%d %d %d\n", nx, ny, dist[nx][ny]);
				op++;
				qx[op] = nx;
				qy[op] = ny;
			}
		}
	}
}

int main() {
	int ca;
	cin >> ca;
	for (int tt = 0; tt < ca; tt++) {
		printf("Case #%d: ", tt+1);

		cin >> hei >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> cl[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> fl[i][j];

		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = true;

		bfs();
		shortestpath();

		double ans = 1e20;
		for (int t = 0; t <= hei; t++) {
			if (dp[t][n - 1][m - 1]) {
				ans = min(ans, t * 0.1);
				break;
			}

			int hh = hei - t;
			if (hh < 0)
				hh = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					if (!dp[t][i][j])
						continue;
					dp[t+1][i][j] = true;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k], ny = j + dy[k];
						if (!onboard(nx, ny))
							continue;

	//					printf("!!%d %d %d %d %d\n", fl[i][j], cl[i][j], fl[nx][ny], cl[nx][ny], hh);
						if (pass(i, j, nx, ny, hh)) {
//							if (hh == 50)
//							cout << "here " << t << endl;
//							printf("!!%d %d %d %d %d\n", fl[i][j], cl[i][j], fl[nx][ny], cl[nx][ny], hh);
							int dd = 100;
							if (hh - fl[i][j] >= 20)
								dd = 10;
							if (t + dd <= hei)
								dp[t + dd][nx][ny] = true;
							else {
								if (dist[nx][ny] >= 0)
									ans = min(ans, 0.1 * (t + dd + dist[nx][ny]));
							}
						}
					}
				}
		}

		printf("%.1lf\n", ans);
	}
}
