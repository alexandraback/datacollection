#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define spc(i,n) " \n"[i == n - 1]

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template<class T> T abs(T x) { return x > 0 ? x : -x;}

vector<vii> g;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void go(int k, vii v) {
	if (k == 0) {
		g.pb(v);
		re;
	}
	rep(i, sz(v)) {
		int x = v[i].fi;
		int y = v[i].se;
		rep(o, 4) {
			int nx = x + dx[o];
			int ny = y + dy[o];
			ii z = mp(nx, ny);
			if (z > mp(0,0) && count(all(v), z) == 0) {
				v.pb(z);
				go(k - 1, v);
				v.pop_back();
			}
		}
	}
}

int matr[20][20];
int gn, gm;
int zt;

bool apply(vii v, int x, int y) {
	zt++;
	rep(i, sz(v)) {
		int cx = v[i].fi + x;
		int cy = v[i].se + y;
		if (cx < 0 || cy < 0 || cx >= gn || cy >= gm)
			re 0;
		matr[cx][cy] = zt;
	}
	re 1;
}

vector<vii> gen(int k) {
	vii v;
	v.pb(mp(0, 0));
	g.clear();
	go(k - 1, v);
	re g;
}

int ct;
int w[30][30];
int k;

int gogo(int x, int y) {
	w[x][y] = ct;
	int ans = 1;
	rep(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < gn && ny >= 0 && ny < gm) {
			if (w[nx][ny] != ct && matr[nx][ny] != zt)
				ans += gogo(nx, ny);
		}
	}
	re ans;
}

int check(int n, int m, vii v) {
	gn = n;
	gm = m;

	if (n * m % k)
		re 0;

	if (n >= k + 1 && m >= k + 1)
		re 1;

	rep(i, n) rep(j, m) {
		if (apply(v, i, j)) {
			ct++;
			int g = 1;
			rep(i, n) rep(j, m) {
				if (w[i][j] != ct && matr[i][j] != zt) {
					int c = gogo(i, j);
					if (c % k) {
						g = 0;
					}
				}
			}
			if (g)
				re 1;
		}
	}
	re 0;
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	int n, m;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		cin >> k >> n >> m;

		if (k >= 7) {
			cout << "RICHARD" << endl;
			continue;
		}

		vector<vii> v = gen(k);
		int f = 0;

		/*
		rep(i, sz(v)) {
			apply(v[i], 5, 5);
			rep(x, n) rep(y, m)
					cout << matr[x][y] << spc(y, m);
			cout << endl;
		}*/

		rep(i, sz(v))
			if (!check(n, m, v[i]) && !check(m, n, v[i])) {
				f = 1;
				break;
			}
		//if (k == 2)
			cout << (f ? "RICHARD" : "GABRIEL") << endl;
	}

	re 0;
}
