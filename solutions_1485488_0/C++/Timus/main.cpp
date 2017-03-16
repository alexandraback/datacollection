#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cassert>

using namespace std;

int h, n, m;
int c[105][105], f[105][105];
double d[105][105];
int u[105][105];

const int inf = 1e9;
//const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
//const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && c[x][y] - f[x][y] >= 50;
}

void findZ(int x, int y) {
	d[x][y] = 0;
//	cerr << x << " " << y << endl;
	for (int k = 0; k < 8; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (valid(nx, ny) && d[nx][ny] != 0 && c[nx][ny] - max(h, max(f[x][y], f[nx][ny])) >= 50 && c[x][y] - f[nx][ny] >= 50)
			findZ(nx, ny);
	}
}
void findAns() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			d[i][j] = inf;
	memset(u, 0, sizeof(u));
	d[0][0] = 0;
	findZ(0, 0);
	for (int it = 0; it < n * m; ++it) {
		int mx = -1, my = -1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (u[i][j] == 0 && (mx == -1 || d[mx][my] > d[i][j]))
					mx = i, my =j;

		if (mx == -1)
			break;
		if (mx == n - 1 && my == m - 1)
			break;
		u[mx][my] = 1;
//		cerr << mx << " " << my << "@" << endl;
		for (int k = 0; k < 4; ++k) {
			int nx = mx + dx[k];
			int ny = my + dy[k];
			if (!valid(nx, ny))
				continue;
			if (c[nx][ny] - max(f[mx][my], f[nx][ny]) < 50 || c[mx][my] - f[nx][ny] < 50)
				continue;
			double nh = h - d[mx][my] * 10;
			double diff = c[nx][ny] - max(nh, 1.0 * max(f[mx][my], f[nx][ny]));
			double addt = 0;
			if (diff < 50)
				addt = (50 - diff) / 10, nh = nh - addt * 10;
			double tmp = nh - f[mx][my];
			if (tmp >= 20)
				addt += 1;
			else addt += 10;
//			cerr << "(" << mx << ";" << my << ")" << "->" << "(" << nx << ";" << ny << ")" << endl;
			if (d[nx][ny] > d[mx][my] + addt)
				d[nx][ny] = d[mx][my] + addt;
		}
	}
//	cout << d[n - 1][m - 1] << endl;
	printf("%.7f\n", d[n - 1][m - 1]);
}

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int tests;
	cin >> tests;
	for (int testnum = 1; testnum <= tests; ++testnum) {
		cerr << testnum << endl;
		printf("Case #%d: ", testnum);
		cin >> h >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> c[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> f[i][j];
		findAns();
	}
}
