#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define VAL(x) #x << " = " << (x) << "   "
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAXN = 1 * 1000 + 10;

int cnt[9][9];

int main () {
	ios::sync_with_stdio(false);

	int tc; cin >> tc;
	for (int o = 0; o < tc; o ++) {
		int a, b, c, k; cin >> a >> b >> c >> k;
		vector<vector<int> > tot;

		FOR(i1, a) FOR(i2, b) FOR(i3, c) {
			vector<int> tmp;
			tmp.pb(i1); tmp.pb(i2); tmp.pb(i3);
			tot.pb(tmp);
		}

		int n = SZ(tot), ans = 0, ans_mask = 0;
		for (int mask = 0; mask < (1 << n); mask ++) {	
			if (__builtin_popcount(mask) <= ans) continue;

			bool bad = false;
			FOR(i, n) if (mask & (1 << i)) {
				FOR(x, 3) FOR(y, x) {
					int i1 = tot[i][x] + x*3, i2 = tot[i][y] + y*3;
					cnt[i1][i2] ++;
					if (cnt[i1][i2] > k) bad = true;
				}
			}
			if (!bad) {
				int cur = __builtin_popcount(mask);
				if (cur > ans) {
					ans = cur;
					ans_mask = mask;
				}
			}

			FOR(i, 9) FOR(j, 9) cnt[i][j] = 0;
		}

		cout << "Case #" << o + 1 << ": ";
		cout << ans << endl;
		FOR(i, n) if (ans_mask & (1 << i)) {
			FOR(j, 3) cout << tot[i][j] + 1 << ' ';
			cout << endl;
		}
	}
	return 0;
}

