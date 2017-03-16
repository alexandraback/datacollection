#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
#define N 102

int n, m, H;
map<int, double> memo[N][N];
int c[N][N];
int f[N][N];
double maxH[N][N];

double solve(int y, int x, int h) {
	if (h < 0) h = 0;
	if (y == n - 1 && x == m - 1) return 0;
	if (memo[y][x].find(h) != memo[y][x].end()) return memo[y][x][h];
	if (h <= maxH[y][x]) return 1e20;
	
	maxH[y][x] = h;
	
	double ans = 1e20;
	int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	for (int d = 0; d < 4; d++) {
		int ny = y + dirs[d][0];
		int nx = x + dirs[d][1];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (c[ny][nx] - f[y][x] < 50 || c[y][x] - f[ny][nx] < 50 || c[ny][nx] - f[ny][nx] < 50) 
			continue;
		if (c[ny][nx] - h < 50) {
			int nh = c[ny][nx] - 50;
			if (nh - f[y][x] >= 20) {
				ans = min(ans, 1 + (h -nh) * 0.1 + solve(ny, nx, nh - 10));
			} else {
				ans = min(ans, 10 + (h -nh) * 0.1 + solve(ny, nx, nh - 100));
			}
		} else {
			if (h == H) {
				ans = min(ans, solve(ny, nx, h));
			}
			if (h - f[y][x] >= 20) {
				ans = min(ans, 1 + solve(ny, nx, h - 10));
			} else {
				ans = min(ans, 10 + solve(ny, nx, h - 100));
			}
		}
	}
	return memo[y][x][h] = ans;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; I++) {
		scanf("%d%d%d", &H, &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", c[i] + j);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", f[i] + j);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				memo[i][j].clear();
				maxH[i][j] = -1;
			}
		}
		double ans = solve(0, 0, H);
		printf("Case #%d: %.7lf\n", I + 1, ans);
	}
	return 0;
}
