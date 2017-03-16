#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
const int M = 10010;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

int n, m, H;
int c[N][N], f[N][N], vis[N][N], d[N][N];
int canM[N][N][4], speed[N][N][4];

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
} Q[M];

int main() {
	int tt;
	scanf("%d", &tt);
	for (int cas = 1; cas <= tt; cas++) {
		scanf("%d%d%d", &H, &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &c[i][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &f[i][j]);
		memset(canM, -1, sizeof(canM));
		memset(speed, -1, sizeof(speed));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < 1 || x > n) continue;
					if (y < 1 || y > m) continue;
					if (c[i][j] - f[i][j] < 50) continue;
					if (c[x][y] - f[x][y] < 50) continue;
					if (c[x][y] - f[i][j] < 50) continue;
					if (c[i][j] - f[x][y] < 50) continue;
					canM[i][j][k] = max(0, H - (min(c[x][y], c[i][j]) - 50));
					speed[i][j][k] = max(-1, H - (f[i][j] + 20));
				}
		memset(vis, 0, sizeof(vis));
		int front = 0, back = 1;
		Q[front] = Point(1, 1);
		vis[1][1] = 1;
		while (front < back) {
			Point pt = Q[front++];
			for (int k = 0; k < 4; k++) {
				if (canM[pt.x][pt.y][k] != 0) continue;
				int x = pt.x + dx[k];
				int y = pt.y + dy[k];
				if (vis[x][y]) continue;
				vis[x][y] = 1;
				Q[back++] = Point(x, y);
			}
		}
		memset(vis, 0, sizeof(vis));
		memset(d, -1, sizeof(d));
		front = 0;
		for (int i = 0; i < back; i++) {
			d[Q[i].x][Q[i].y] = 0;
			vis[Q[i].x][Q[i].y] = 1;
		}
		while (front != back) {
			Point pt = Q[front++];
			int cur = d[pt.x][pt.y];
			for (int k = 0; k < 4; k++) {
				int mm = canM[pt.x][pt.y][k];
				if (mm == -1) continue;
				mm = max(mm, cur);
				int cost = (mm <= speed[pt.x][pt.y][k] ? 10 : 100);
				int x = pt.x + dx[k];
				int y = pt.y + dy[k];
				if (d[x][y] == -1 || mm + cost < d[x][y]) {
					d[x][y] = mm + cost;
					if (vis[x][y]) continue;
					Q[back++] = Point(x, y);
					vis[x][y] = 1;
					if (back == M) back = 0;
				}
			}
			vis[pt.x][pt.y] = 0;
			if (front == M) front = 0;
		}
		int ans = d[n][m];
		printf("Case #%d: %d.%d\n", cas, ans / 10, ans % 10);
	}
	return 0;
}
