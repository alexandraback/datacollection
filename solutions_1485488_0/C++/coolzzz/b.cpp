#include <stdio.h>

const int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int cs, ct;
int h, n, m;
int c[110][110], f[110][110];
struct {
	int h;
	double t;
} a[110][110];
int mark[110][110];

int check(int x1, int y1, int x2, int y2, int h)
{
	if (f[x1][y1] > c[x2][y2] - 50) return 1;
	if (f[x2][y2] > c[x2][y2] - 50) return 1;
	if (f[x2][y2] > c[x1][y1] - 50) return 1;
	if (h > c[x2][y2] - 50) return 2;
	return 0;
}

int move(int h1, int h2)
{
	if (h1 >= h2 + 20) return 1;
	else return 10;
}

int main()
{
	int i, j, ii, jj, x, y;
	double min;
	scanf("%d", &cs);
	for (ct = 1; ct <= cs; ct++) {
		scanf("%d%d%d", &h, &n, &m);
		for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &c[i][j]);
		for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &f[i][j]);

		for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			a[i][j].t = 1e10;
			a[i][j].h = h;
			mark[i][j] = 0;
		}

		mark[0][0] = 1;
		a[0][0].t = 0;
		while (true) {
			min = 1e10;
			for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			if (mark[i][j] == 1 && a[i][j].t < min) {
				min = a[i][j].t;
				ii = i;
				jj = j;
			}
			if (min == 1e10) break;
			for (i = 0; i < 4; i++) {
				x = ii + dir[i][0];
				y = jj + dir[i][1];
				if (x >= 0 && x < n && y >= 0 && y < m && mark[x][y] == 0) {
					if (check(ii, jj, x, y, h) == 0) {
						a[x][y].t = 0;
						mark[x][y] = 1;
					}
				}
			}
			mark[ii][jj] = 2;
		}
		for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (mark[i][j] == 2) mark[i][j] = 1;

		while (true) {
			min = 1e10;
			for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			if (mark[i][j] == 1 && a[i][j].t < min) {
				min = a[i][j].t;
				ii = i;
				jj = j;
			}
			if (min == 1e10) break;
			for (i = 0; i < 4; i++) {
				x = ii + dir[i][0];
				y = jj + dir[i][1];
				if (x >= 0 && x < n && y >= 0 && y < m && mark[x][y] < 2) {
					int ch = check(ii, jj, x, y, a[ii][jj].h);
					if (ch == 1) continue;
					if (ch == 2) {
						double t = (a[ii][jj].h - (c[x][y] - 50)) / 10.;
						int mv = move(c[x][y] - 50, f[ii][jj]);
						if (a[ii][jj].t + t + mv < a[x][y].t) {
							a[x][y].t = a[ii][jj].t + t + mv;
							a[x][y].h = c[x][y] - 50 - mv * 10;
							if (a[x][y].h < 0) a[x][y].h = 0;
							mark[x][y] = 1;
						}
						continue;
					}
					if (ch == 0) {
						int mv = move(a[ii][jj].h, f[ii][jj]);
						if (a[ii][jj].t + mv < a[x][y].t) {
							a[x][y].t = a[ii][jj].t + mv;
							a[x][y].h = a[ii][jj].h - mv * 10;
							if (a[x][y].h < 0) a[x][y].h = 0;
							mark[x][y] = 1;
						}
					}
				}
			}
			mark[ii][jj] = 2;
		}
		printf("Case #%d: %.6lf\n", ct, a[n - 1][m - 1].t);
	}
	return 0;
}
