#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"


const int MAXN = 30 + 10;
const ll INF = 2e18;

char s[MAXN];
char t[MAXN];
int n;

bool read() {
	if  (scanf("%s %s\n", s, t) < 2) {
		return false;
	}
	n = strlen(s);
	return true;
}

ll dp[30][3];
ll min_s[30][3];
ll min_t[30][3];

void output(ll x, int len) {
	vi d;
	forn(it, len) {
		d.pb(x % 10);
		x /= 10;
	}
	ford(i, sz(d)) {
		printf("%d", d[i]);
	}
}

void solve() {
	forn(i, n + 1) forn(q, 3) {
		dp[i][q] = INF;
		min_s[i][q] = INF;
		min_t[i][q] = INF;
	}

	dp[0][0] = 0;
	min_s[0][0] = 0;
	min_t[0][0] = 0;
	forn(i, n) forn(q, 3) {
		if  (dp[i][q] >= INF) {
			continue;
		}
		forn(cs, 10) {
			if  (s[i] != '?' && s[i] != '0' + cs) {
				continue;
			}
			forn(ct, 10) {
				if  (t[i] != '?' && t[i] != '0' + ct) {
					continue;
				}
				int nq = q;
				if  (q == 0 && cs != ct) {
					nq = cs < ct ? 1 : 2;
				}
				ll new_dp = dp[i][q] * 10 + (nq == 1 ? (ct - cs) : (cs - ct));
				ll new_min_s = min_s[i][q] * 10 + cs;
				ll new_min_t = min_t[i][q] * 10 + ct;
				if  (new_dp < dp[i + 1][nq] || (new_dp == dp[i + 1][nq] && new_min_s < min_s[i + 1][nq]) || (new_dp == dp[i + 1][nq] && new_min_s == min_s[i + 1][nq] && new_min_t < min_t[i + 1][nq])) {
					dp[i + 1][nq] = new_dp;
					min_s[i + 1][nq] = new_min_s;
					min_t[i + 1][nq] = new_min_t;
				}
			}
		}
	}

	ll min_diff = INF;
	ll best_s = INF;
	ll best_t = INF;
	forn(q, 3) {
		if  (dp[n][q] >= INF) {
			continue;
		}
		if  (dp[n][q] < min_diff || (dp[n][q] == min_diff && min_s[n][q] < best_s) || (dp[n][q] == min_diff && min_s[n][q] == best_s && min_t[n][q] < best_t)) {
			min_diff = dp[n][q];
			best_s = min_s[n][q];
			best_t = min_t[n][q];
		}
	}

	output(best_s, n);
	printf(" ");
	output(best_t, n);
	puts("");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
#endif

	int T;
	scanf("%d\n", &T);
	forn(tt, T) {
		printf("Case #%d: ", tt + 1);
		assert(read());
		solve();
		cerr << tt << endl;
	}

	return 0;
}
