#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#pragma comment(linker, "/STACK:16000000")

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;
const double EPS = 1e-8;
const double PI = 2 * acos(0.);
const int T = (1 << 25) - 1;

int q[T + 1][2];
bool inq[120][120];
int u[120][120];
int d[120][120];
int dist[120][120];
int dd[2][4] = {1, -1, 0, 0, 0, 0, 1, -1};

void solve() {
	int H, n, m;
	scanf("%d%d%d", &H, &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &u[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &d[i][j]);
		}
	}
	memset(dist, 0xf0, sizeof(dist));
	memset(inq, 0, sizeof(inq));
	dist[0][0] = H;
	int l = 0;
	int r = 1;
	q[0][0] = q[0][1] = 0;
	inq[0][0] = 1;
	while (l != r) {
		int x = q[l][0];
		int y = q[l][1];
		inq[x][y] = 0;
		l = (l + 1) & T;
		int h = dist[x][y];
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dd[0][dir];
			int ny = y + dd[1][dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			int diff = min(u[x][y], u[nx][ny]) - max(d[x][y], d[nx][ny]);
//			cerr << diff << endl;
			if (diff < 50) continue;
			int hh = min(h, min(u[x][y], u[nx][ny]) - 50);
			if (hh == H) {
				if (hh > dist[nx][ny]) {
					dist[nx][ny] = hh;
					if (!inq[nx][ny]) {
						q[r][0] = nx;
						q[r][1] = ny;
						r = (r + 1) & T;
						inq[nx][ny] = 1;
					}
				}
			} else {
				if (hh - d[x][y] >= 20)
					hh -= 10;
				else
					hh -= 100;
				if (hh > dist[nx][ny]) {
					dist[nx][ny] = hh;
					if (!inq[nx][ny]) {
						q[r][0] = nx;
						q[r][1] = ny;
						++r;
						inq[nx][ny] = 1;
					}
				}
			}
		}
	}
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			printf("%d ", dist[i][j]);
//		}
//		puts("");
//	}
	printf("%.10lf\n", (H - dist[n - 1][m - 1]) * .1);
}

int main() {
#ifdef _DBG1
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}