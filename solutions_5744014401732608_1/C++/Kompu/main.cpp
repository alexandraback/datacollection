#include <bits/stdc++.h>

using namespace std;
typedef long long int64;
#define DEBUG(x) cerr << #x << " = " << x << endl;
#define REP(x, n) for(__typeof(n) x = 0; x < (n); ++x)
#define FOR(x, b, e) for(__typeof(b) x = (b); x != (e); x += 1 - 2 * ((b) > (e)))
const int INF = 1000000001;
const double EPS = 10e-9;

#ifndef CATCH_TEST
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(o, t) {
		int64 n;
		int64 m;
		cin >> n >> m;
		vector<int64> edge(n, 0);

		for (int64 x = 1; x < n - 1; ++x) {
			for (int64 y = x + 1; y < n; ++y) {
				int64 v = 1ll << y;
				edge[x] += v;
			}
		}

		cout << "Case #" << o + 1 << ": ";
		if (m > (1ll << (n - 2))) {
			cout << "IMPOSSIBLE\n";
		} else {
			if (m == (1ll << (n - 2))) {
				--m;
				edge[0] += 1ll << (n - 1);
			}
			for (int64 x = 1; x < n; ++x) {
				int64 val = 1ll << (n - x - 1);
				if (m & val) {
					m -= val;
					int64 v = 1ll << (x - 1);
					edge[0] += v;
				}
			}
			
			cout << "POSSIBLE\n";
			for (auto it : edge) {
				for (int64 x = 0; x < n; ++x) {
					int64 v = 1ll << x;
					if (it & v) {
						cout << "1";
					} else {
						cout << "0";
					}
				}
				cout << "\n";
			}
		}		
	}
	return 0;
}
#endif