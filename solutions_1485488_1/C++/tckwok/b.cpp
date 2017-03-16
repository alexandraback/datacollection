#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define pb push
#define mp make_pair
#define x first
#define y second

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int T, h, n, m, ch[100][100], fh[100][100], ans[100][100], tx, ty, tt, nx, ny, ft;
priority_queue <pair <int, int> > q;
pair <int, int> t;

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d:", r);
		scanf("%d%d%d", &h, &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", ch[i] + j);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", fh[i] + j);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ans[i][j] = 1 << 24;
		q.pb(mp(0, 0));
		while (ans[n - 1][m - 1] == 1 << 24) {
			t = q.top(); q.pop();
			tt = -t.x; tx = t.y/m; ty = t.y%m;
			if (ans[tx][ty] != 1 << 24) continue;
			ans[tx][ty] = tt;
			for (int dir = 0; dir < 4; ++dir) {
				nx = tx + dx[dir]; ny = ty + dy[dir];
				if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
				if (ch[nx][ny] - fh[nx][ny] < 50) continue;
				if (ch[nx][ny] - fh[tx][ty] < 50) continue;
				if (ch[tx][ty] - fh[nx][ny] < 50) continue;
				ft = tt;
				if (ch[nx][ny] - (h - ft) < 50) ft = -ch[nx][ny] + h + 50;
				if (ft == 0) q.pb(mp(0, nx*m + ny));
				else if ((h - ft) - fh[tx][ty] < 20) q.pb(mp(-ft - 100, nx*m + ny));
				else q.pb(mp(-ft - 10, nx*m + ny));
			}
		}
		while (!q.empty()) q.pop();
		printf(" %.1lf\n", .1*ans[n - 1][m - 1]);
	}
	return 0;
}
