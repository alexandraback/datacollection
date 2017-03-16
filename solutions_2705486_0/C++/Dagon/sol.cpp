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

vs dict;

void getdict() {
	FILE *f = fopen("garbled_email_dictionary.txt", "r");
	char s[10000];
	while (1) {
		if (fscanf(f, "%s", s) == EOF)
			break;
		dict.pb(string(s));
	}
	fclose(f);
}

int dp[4001][6];

ii match(string &s, string &t, int pos, int &change) {
	vi p;
	change = 0;
	rep(i, sz(t)) {
		if (s[pos + i] != t[i]) {
			if (sz(p) && i < p.back() + 5)
				re mp(-1, -1);
			p.pb(i);
		}
	}
	change = sz(p);
	if (sz(p)) {
		re mp(p[0], p.back());
	}
	re mp(100500, -100500);
}

int main() {
	getdict();	
	int T;
	cin >> T;
	rep(I, T) {
		rep(i, 4001) {
			rep(j, 6)
				dp[i][j] = 1e4;
		}
		dp[0][5] = 0;
		string s;
		cin >> s;
		rep(i, sz(s)) {
			rep(j, sz(dict)) {
				string &t = dict[j];
				if (sz(dict[j]) <= i + 1) {
					int w;
					ii tmp = match(s, t, i + 1 - sz(t), w);
					if (tmp.fi < 0) {
						continue;	
					} else if (tmp.fi > tmp.se) {
						for (int k = 0; k < 6; k++) {
							dp[i + 1][min(5, k + sz(t))] = min(dp[i + 1][min(5, k + sz(t))], w + dp[i + 1 - sz(t)][k]);
						}
					} else {
						//cerr << i + 1 - sz(t) << ' ' << s <<' ' << t << endl;
						//cerr << tmp.fi << ' ' << tmp.se << endl;
						//if (sz(t) - 1 - tmp.se >= 4) {
						//	cerr << i + 1 - sz(t) << ' ' << s <<' ' << t << endl;
						//}
						for (int k = 0; k < 6; k++) {
							if (k + 1 + tmp.fi >= 5)
								dp[i + 1][min(5, sz(t) - 1 - tmp.se)] = min(dp[i + 1][min(5, sz(t) - 1 - tmp.se)], w + dp[i + 1 - sz(t)][k]);
						}
					}
				}
			}
			/*rep(k, 6) {
				cerr << dp[i + 1][k] << ' ';
			}
			cerr << endl;*/
		}
		int ans = 1e4;
		rep(i, 6) {
			ans = min(ans, dp[sz(s)][i]);
		}
		cout << "Case #" << I + 1 << ": " << ans << endl;
		//re 0;
	}
	return 0;
}
