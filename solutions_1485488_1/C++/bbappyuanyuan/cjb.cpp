#include <cstdio>
#include <cstring>

const int maxl = 100 + 10;
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int h, n, m;
int ceil[maxl][maxl], floor[maxl][maxl];
int f[maxl][maxl];
int head, tail, queue[maxl * maxl * 5][2];
bool inq[maxl][maxl];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs) {
		scanf("%d%d%d", &h, &n, &m);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d", &ceil[i][j]);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d", &floor[i][j]);
		
		memset(f, 0x7F, sizeof(f));
		memset(inq, 0, sizeof(inq));
		f[1][1] = 0;
		head = 0, tail = 1, queue[1][0] = 1, queue[1][1] = 1;
		inq[1][1] = true;
		while (head != tail) {
			if (++head >= maxl * maxl * 5) head = 1;
			int x = queue[head][0], y = queue[head][1], nx, ny, nh, g;
			inq[x][y] = false;
			//printf("from %d %d %d\n", x, y, f[x][y]);
			for (int k = 0; k < 4; ++k) {
				nx = x + dir[k][0], ny = y + dir[k][1];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && floor[x][y] + 50 <= ceil[nx][ny] && floor[nx][ny] + 50 <= ceil[nx][ny] && floor[nx][ny] + 50 <= ceil[x][y]) {
					nh = h - f[x][y];
					if (nh < 0) nh = 0;
					g = f[x][y];
					if (nh + 50 > ceil[nx][ny]) g += nh - (ceil[nx][ny] - 50), nh = ceil[nx][ny] - 50;
					if (nh - 20 >= floor[x][y]) g += 10; else g += 100;
					if (nh == h) g = 0;
					if (g < f[nx][ny]) {
						f[nx][ny] = g;
						//printf("to %d %d %d\n", nx, ny, g);
						if (!inq[nx][ny]) {
							if (++tail >= maxl * maxl * 5) tail = 1;
							queue[tail][0] = nx, queue[tail][1] = ny;
							inq[nx][ny] = true;
						}
					}
				}
			}
		}
		printf("Case #%d: %.1lf\n", cs, f[n][m] / 10.0);
	}
	
	return 0;
}
