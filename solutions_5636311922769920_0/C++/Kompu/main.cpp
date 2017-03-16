#include <bits/stdc++.h>

using namespace std;
#define DEBUG(x) cerr << #x << " = " << x << endl;
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOR(x, b, e) for(int x = (b); x != (e); x += 1 - 2 * ((b) > (e)))
const int INF = 1000000001;
const double EPS = 10e-9;

#ifndef CATCH_TEST
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(o, t) {
		int k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << o + 1 << ": ";
		REP(x, k) {
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}
#endif