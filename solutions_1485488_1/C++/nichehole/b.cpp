#include <cstdio>
#include <cstring>

int H, n, m;
int hi[105][105], lo[105][105];
double d[105][105];
int Qx[100000], Qy[100000];
bool v[105][105];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int f(int fx, int fy, int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return 0;
	if (hi[x][y] - lo[fx][fy] < 50) return 0;
	if (hi[x][y] - lo[x][y] < 50) return 0;
	if (hi[fx][fy] - lo[x][y] < 50) return 0;
	return 1;
}
double g(int cx, int cy, int nx, int ny, double dd) {
	if (hi[nx][ny] - (H - dd * 10) >= 50) {
		if (dd == 0) return 0;
		if (H - dd * 10 - lo[cx][cy] >= 20.0) return 1.0;
		return 10.0;
	} 
	double tmp = (50 - (hi[nx][ny] - (H - dd * 10))) * 1. / 10;
	//printf("%.6f\n", tmp);
	if (H - (tmp + dd) * 10 - lo[cx][cy] >= 20.0) return tmp + 1.0;
	return tmp + 10.0;
}

void solve() {
	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[i][j] = 1e50;
		}
	}
	d[0][0] = 0; int h = 0;
	Qx[h] = 0; Qy[h] = 0; ++h;
	v[0][0] = 1;
	for (int t = 0; t < h; ++t) {
		//printf("t: %d\n", t);
		int cx = Qx[t], cy = Qy[t];
		v[cx][cy] = 0;
		for (int i = 0; i < 4; ++i) {
			int nx = Qx[t] + dx[i];
			int ny = Qy[t] + dy[i];
			if (!f(cx, cy, nx, ny)) continue;
			//printf("from %d %d to %d %d\n", cx, cy, nx, ny);
			if (d[cx][cy] + g(cx, cy, nx, ny, d[cx][cy]) < d[nx][ny]) {
				d[nx][ny] = d[cx][cy] + g(cx, cy, nx, ny, d[cx][cy]);
				//if (nx == n - 1 && ny == m - 1) return;
				if (!v[nx][ny]) {
					//printf("push %d %d\n", nx, ny);
					v[nx][ny] = 1;
					Qx[h] = nx;
					Qy[h] = ny;
					++h;
				}
			}
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	int cas = 0;
	while (T--) {
		scanf("%d%d%d", &H, &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &hi[i][j]);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &lo[i][j]);
			}
		}
		solve();
		/*
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (d[i][j] > 1e5) printf("oo "); else printf("%.6f ", d[i][j]);
			} puts("");
		}
		*/
		printf("Case #%d: ", ++cas);
		printf("%.6f\n", d[n-1][m-1]);
	}
	return 0;
}
