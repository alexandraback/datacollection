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

const ll mod = 1e9 + 7;

const int nmax = 2000;

string s[nmax];
int cnt[10];

int getType(string s, char ch) {
	// check if whole
	bool kpyto = true;
	rep(i, sz(s))
		if (s[i] != ch)
			kpyto = false;
	if (kpyto)
		return 1;
	// check if none
	kpyto = true;
	rep(i, sz(s))
		if (s[i] == ch)
			kpyto = false;
	if (kpyto)
		return 0;
	// check if left
	kpyto = true;
	rep(i, sz(s))
		if (i && s[i] == ch && s[i - 1] != ch)
			kpyto = false;
	if (kpyto)
		re 2;
	// check if right
	kpyto = true;
	rep(i, sz(s))
		if (i < sz(s) - 1 && s[i] == ch && s[i + 1] != ch)
			kpyto = false;
	if (kpyto)
		re 3;
	// check segment
	int l, r, cnt;	
	l = 10000;
	r = -1;
	cnt = 0;
	rep(i, sz(s))
		if (s[i] == ch) {
			cnt++;
			r = i;
			l = min(l, i);
		}
	if (r - l + 1 == cnt)
		return 4;
	return -1;
}

vi g[nmax], gg[nmax];
int type[nmax];
int was[nmax];

void dfs(int u) {
	was[u] = 1;
	rep(i, sz(g[u]))
		if (was[g[u][i]] == 0)
			dfs(g[u][i]);
}

bool dfsCycles(int u) {
	was[u] = 1;
	rep(i, sz(gg[u])) {
		int v = gg[u][i];
		if (was[v] == 0)
			if (dfsCycles(v))
				re true;
		if (was[v] == 1)
			re true;
	}
	was[u] = 2;
	re false;
}

int main() {
	int T;
	cin >> T;
	rep(I, T) {
		int n;
		cin >> n;
		rep(i, nmax) {
			g[i].clear();
			gg[i].clear();
		}
		rep(i, n) {
			cin >> s[i];
		}
		ll ans = 1;
		int neg = 0;
		/*rep(i, n)
			cerr << s[i] << ' ';
		cerr << endl;*/
		for (char ch = 'a'; ch <= 'z'; ch++) {
			fill(cnt, 0);
			rep(i, n) {
				type[i] = getType(s[i], ch);
				if (type[i] == -1) {
					ans = 0;
					break;
				}
				cnt[type[i]]++;
			}
			//cerr << ch << ":";
			rep(i, n) {
				//cerr << " " << type[i];
				rep(j, n) {
					if (type[i] == 3 && type[j] == 2) {
						gg[i].pb(j);
					}
					if (type[i] == 3 && (type[j] == 1 || type[j] == 2)) {
						g[i].pb(j);
						g[j].pb(i);
					}
					if (type[i] == 1) {
						if (type[j] == 1) {
							g[i].pb(j);
							g[j].pb(i);
						}
						if (type[j] == 2) {
							g[i].pb(j);
							g[j].pb(i);
						}
					}
				}
			}
			//cerr << endl;
			if (cnt[2] > 1 || cnt[3] > 1)
				ans = 0;
			if (cnt[4] > 0 && cnt[0] != n - 1)
				ans = 0;
			rep(i, cnt[1])
				ans = ans * (ll)(i + 1) % mod;
		}
		/*rep(i, n) {
			cerr << i << ": ";
			rep(j, sz(g[i]))
				cerr << g[i][j] << ' ';
			cerr << endl;
		}*/
		int cmp = 0;
		fill(was, 0);
		rep(i, n)
			if (was[i] == 0) {
				dfs(i);
				ans = ans * (ll)(++cmp) % mod;
			}
		fill(was, 0);
		rep(i, n)
			if (was[i] == 0 && dfsCycles(i)) {
				ans = 0;
			}
		cout << "Case #" << I + 1 << ": " << ans << endl;
	}
	return 0;
}
