#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <deque>
using namespace std;
#define MAXN 110
#define MAXH 1010

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int c[MAXN][MAXN], f[MAXN][MAXN];
int d[MAXN][MAXN], inqueue[MAXN][MAXN];
int n, m, h;


int pass(int x, int y, int d, int t) {
	int nx, ny, cost = 0;
	if (t > h) t = h;
	nx = x + dx[d];
	ny = y + dy[d];
	if (nx < 0 || ny < 0 || nx >=n || ny >=m) return -1;
	if (min(c[nx][ny], c[x][y]) - max(f[nx][ny], f[x][y]) < 50) return -1;
	if (min(c[nx][ny], c[x][y]) - 50 < h - t) {
		cost += h - t - (min(c[nx][ny], c[x][y]) - 50);
	}
	if (h - t - cost >= f[x][y] + 20) {
		cost += 10;
	} else {
		cost += 100;
	}
	return cost;
}

int passInit(int x, int y, int d) {
	int nx, ny, cost = 0;
	nx = x + dx[d];
	ny = y + dy[d];
	if (nx < 0 || ny < 0 || nx >=n || ny >=m) return -1;
	if (min(c[nx][ny], c[x][y]) - max(h, max(f[nx][ny], f[x][y])) < 50) return -1;
	return 0;
}


void dfsStart(int x, int y) {
	d[x][y] = 0;
	int i, j, nx, ny;
	for (i=0;i<4;++i) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (passInit(x,y,i) >= 0 && d[nx][ny] == -1) {
			dfsStart(nx, ny);
		}
	}
}

void init() {
	memset(d, -1, sizeof(d));
	dfsStart(0, 0);
}

deque<pair<int,int> > queue;

void solve() {
	int i, j;
	memset(inqueue, 0, sizeof(inqueue));
	queue.clear();
	for (i=0;i<n;++i) {
		for (j=0;j<m;++j) {
			if (d[i][j] != -1) {
				queue.push_back(make_pair(i,j));
				inqueue[i][j] = true;
			}
		}
	}

	while (!queue.empty()) {
		int x, y, t, nx, ny, cost, tp;
		
		pair<int,int> u = queue.front();
		queue.pop_front();
		x = u.first;
		y = u.second;
		inqueue[x][y] = false;

		for (i=0;i<4;++i) {
			nx = x + dx[i];
			ny = y + dy[i];
			cost = pass(x, y, i, d[x][y]);
			if (cost >= 0 && (d[nx][ny] == -1 || d[x][y] + cost < d[nx][ny])) {
				d[nx][ny] = d[x][y] + cost;
				if (!inqueue[nx][ny]) {
					queue.push_back(make_pair(nx,ny));
					inqueue[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	int i, j, t, ca = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &h, &n, &m);
		for (i=0;i<n;++i) {
			for (j=0;j<m;++j) {
				scanf("%d", &c[i][j]);
			}
		}
		for (i=0;i<n;++i) {
			for (j=0;j<m;++j) {
				scanf("%d", &f[i][j]);
			}
		}
		init();
		solve();
		printf("Case #%d: %.1lf\n", ++ca, d[n-1][m-1] / 10.0);
	}
	return 0;
}