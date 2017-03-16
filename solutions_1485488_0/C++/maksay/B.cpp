#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#define L(s) (int)((s).size())
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define x first
#define y second
#define inf 1000000000
#define all(s) (s).begin(), (s).end()
#define ll long long
#define VI vector<int>
#define ull unsigned ll
int t, num, n, m, h;
int f[111][111], c[111][111];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
double st[111][111][4];
inline bool ok(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
inline bool can(int c1, int f1, int c2, int f2, double wh) {
	if (c2 - wh < 50) return 0;
	if (c2 - f1 < 50) return 0;
	if (c2 - f2 < 50) return 0;
	if (c1 - f2 < 50) return 0;
	return 1;
}
double best[111][111];
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for(int num = 1; num <= t; ++num) {
		cerr << num << endl;
		scanf("%d%d%d", &h, &n, &m);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d", &c[i][j]);
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d", &f[i][j]);
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				for(int w = 0; w < 4; ++w) {
					int ni = i + dx[w];
					int nj = j + dy[w];
					if (!ok(ni, nj)) continue;
					double low = 0, high = 10000;
					if (!can(c[i][j], f[i][j], c[ni][nj], f[ni][nj], 0)) {
						st[i][j][w] = inf;
					}
					for(int iter = 0; iter < 100; ++iter) {
						double mid = (high + low) / 2.;
						if (can(c[i][j], f[i][j], c[ni][nj], f[ni][nj], max(0., h - 10. * mid))) {
							high = mid;
						} else low = mid;
					}
					st[i][j][w] = high;
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				best[i][j] = 1e100;
			}
		}
		best[0][0] = 0;
		queue<pii> q;
		q.push(mp(0, 0));
		while(!q.empty()) {
			pii cur = q.front();
			q.pop();
			double now = best[cur.x][cur.y];
			for(int w = 0; w < 4; ++w) {
				int ni = cur.x + dx[w];
				int nj = cur.y + dy[w];
				if (!ok(ni, nj)) continue;
				if (!can(c[cur.x][cur.y], f[cur.x][cur.y], c[ni][nj], f[ni][nj], 0))
					continue;
//				cerr << now << " " << st[cur.x][cur.y][w] << endl;
				double when = max(now, st[cur.x][cur.y][w]);
				if (abs(when) > 1e-9) {
	//				cerr << when << endl;
					if (h - 10 * when - f[cur.x][cur.y] < 20) {
						when += 10;
					} else {
						when += 1;
					}
				}
//				cerr << "!" << when << endl;
				if (best[ni][nj] > when) {
					best[ni][nj] = when;
					q.push(mp(ni, nj));
				}
			}
		}
//		cerr << st[0][0][1] << endl;
//		cerr << best[0][1] << endl;
//		cerr << best[1][1] << endl;
//		cerr << best[2][1] << endl;
//		cerr << st[1][1][2] << endl;
//		exit(0);
		printf("Case #%d: %0.15lf\n", num, best[n - 1][m - 1]);
	}
}
