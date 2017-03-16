#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#include <queue>

#define sqr(x) ((x) * (x))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define y0 ywuerosdfhgjkls
#define y1 hdsfjkhgjlsdfhgsdf
#define j1 j924
#define j0 j2834
#define sqrt(x) (sqrt(abs(x)))
#define re return
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = ((n) - 1); i >= 0; i--)
#define fill(a, x) memset(a, x, sizeof(a))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef double D;
typedef vector <string> vs;

template <class T> inline T abs(T a) {
	return a > 0 ? a : -a;
}

int n;
int m;

int h;
int c[100][100];
int f[100][100];

const int tmax = 100001;


bool d[100][100][tmax + 1];

int dd[100][100];

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

inline bool gom(int h, int f1, int c1, int f2, int c2) {
	if (f1 > c2 - 50 || h > c2 - 50 || f2 > c2 - 50)
		re false;
	if (f2 > c1 - 50)
		re false;
	re true;
}

int main() {
	int T;
	cin >> T;
	rep(I, T) {
		cerr << I << endl;
		cin >> h >> n >> m;
		rep(i, n)
			rep(j, m)
				cin >> c[i][j];
		rep(i, n)
			rep(j, m)
				cin >> f[i][j];
		vii q;
		bool w[100][100];
		fill(w, false);
		q.pb(mp(0, 0));
		w[0][0] = true;
		rep(cur, sz(q)) {
			int x = q[cur].fi;
			int y = q[cur].se;
			rep(i, 4) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (0 <= xx && xx < n && 0 <= yy && yy < m) {
					if (gom(h, f[x][y], c[x][y], f[xx][yy], c[xx][yy]) && !w[xx][yy]) {
						q.pb(mp(xx, yy));
						w[xx][yy] = true;
					}
				}
			}
		}
		
		deque <pair <ii, int> > qq;
		fill(d, true);
		rep(i, n) {
			rep(j, m)
				if (w[i][j]) {
					qq.pb(mp(mp(i, j), 0));
					d[i][j][0] = 0;
					dd[i][j] = 1e9;
				}
		}
		int ans = 1e9;
		while (sz(qq)) {
			int x, y, t;
			x = qq[0].fi.fi;
			y = qq[0].fi.se;
			t = qq[0].se;
			qq.pop_front();
			if (x == n - 1 && y == m - 1) {
				ans = min(ans, t);
			}

			if (t > ans)
				continue;
			int hh = max(0, h - t);
			rep(i, 4) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				int tt = t;
				if (hh >= f[x][y] + 20)
					tt += 10;
				else
					tt += 100;
				if (0 <= xx && xx < n && 0 <= yy && yy < m) {
					if (gom(hh, f[x][y], c[x][y], f[xx][yy], c[xx][yy])) {
						if (tt < tmax) {
							if (d[xx][yy][tt]) {
								qq.pb(mp(mp(xx, yy), tt));
								d[xx][yy][tt] = 0;
							}
						} else {
							dd[xx][yy] = min(dd[xx][yy], tt);
						}
					}
				}
			}

			//stay
			int tt = t + 1;
			if (tt < tmax) {
				if (d[x][y][tt]) {
					qq.pb(mp(mp(x, y), tt));
					d[x][y][tt] = 0;
				}
			} else {
				dd[x][y] = min(dd[x][y], tt);
			}
		}
		rep(i, tmax + 1) {
			if (d[n - 1][m - 1][i] == 0) {
				ans = i;
				break;
			}
		}
		if (ans > 1e8) {
			vector <ii> q;
			rep(i, n)
				rep(j, m)
					if (dd[i][j] < 1e9)
						q.pb(mp(i, j));
			rep(cur, sz(q)) {
				int x = q[cur].fi;
				int y = q[cur].se;
				rep(i, 4) {
					int xx = x + dx[i];
					int yy = y + dy[i];
					if (0 <= xx && xx < n && 0 <= yy && yy < m) {
						if (gom(-1, f[x][y], c[x][y], f[xx][yy], c[xx][yy]) && dd[xx][yy] > dd[x][y] + 100) {
							dd[xx][yy] = dd[x][y] + 100;
							q.pb(mp(xx, yy));
						}
					}
				}
			}
			ans = dd[n - 1][m - 1];
		}
		cout << "Case #" << I + 1 << ": ";
		printf("%.10lf\n", (double)ans / 10.0);
	}
	return 0;
}
