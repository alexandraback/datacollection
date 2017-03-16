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

const int tmax = 10001;


int d[100][100][tmax + 1];

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

bool gom(int h, int f1, int c1, int f2, int c2) {
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
		
		vector <pair <ii, int> > qq;
		fill(d, -1);
		rep(i, n) {
			rep(j, m)
				if (w[i][j]) {
					qq.pb(mp(mp(i, j), 0));
					d[i][j][0] = 0;
				}
		}
		rep(cur, sz(qq)) {
			int x, y, t;
			x = qq[cur].fi.fi;
			y = qq[cur].fi.se;
			t = qq[cur].se;
			//cerr << x << ' ' << y << ' ' << t << endl;
			int hh = max(0, h - t);
			rep(i, 4) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				int tt = t;
				if (hh >= f[x][y] + 20)
					tt += 10;
				else
					tt += 100;
				tt = min(tmax, tt);
				if (0 <= xx && xx < n && 0 <= yy && yy < m) {
					if (gom(hh, f[x][y], c[x][y], f[xx][yy], c[xx][yy])) {
						if (d[xx][yy][tt] < 0 || (d[xx][yy][tt] > tt)) {
							qq.pb(mp(mp(xx, yy), tt));
							d[xx][yy][tt] = tt;
						}
					}
				}
			}

			//stay
			int tt = min(t + 1, tmax);
			if (d[x][y][tt] < 0 || (d[x][y][tt] > tt)) {
				qq.pb(mp(mp(x, y), tt));
				d[x][y][tt] = tt;
			}
		}
		double ans = 1e20;
		rep(i, tmax + 1) {
			if (d[n - 1][m - 1][i] >= 0) {
				ans = i;
				break;
			}
		}
		cout << "Case #" << I + 1 << ": ";
		printf("%.10lf\n", ans / 10.0);
	}
	return 0;
}
