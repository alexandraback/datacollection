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
		int n;
		long long count = 0;
		vector<bool>seen(10, false);
		int notSeen = 10;
		cin >> n;

		cout << "Case #" << o + 1 << ": ";
		if (n == 0) {
			cout << "INSOMNIA\n";
		} else {
			while(notSeen > 0) {
				count += n;
				long long tmp = count;
				while(tmp > 0) {
					int num = tmp % 10;
					if (!seen[num]) {
						seen[num] = true;
						--notSeen;
					}
					tmp /= 10;
				}
			}
			cout << count << "\n";
		}
	}

	return 0;
}
#endif