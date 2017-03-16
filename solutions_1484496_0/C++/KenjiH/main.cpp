#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define REP(i, n) for(int i=0; i<(int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i < (int)(e); i++)
const int MAX_V = 3000000;
int x[20];
int dp[MAX_V];

void solve() {
	int T;

	cin >> T;
	REP(t, T) {
		int N;
		cin >> N;

		REP(i, N) cin >> x[i];
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;

		int ans = -1;
		int q = -1;
		REP(i, N) {
			for (int j = MAX_V-1; j >= 0; j--) {
				if (dp[j] == -1)
					continue;
				if (dp[j+x[i]] != -1) {
					ans = j + x[i];
					q = x[i];
					break;
				}
				dp[j+x[i]] = x[i];
			}
			if (ans != -1)
				break;
		}

		cout << "Case #" << t+ 1 << ":" << endl;
		if (ans == -1) {
			puts("Impossible");
			continue;
		}

		bool fg = false;
		for (int v = ans; v > 0; v = v-dp[v]) {
			if (!fg)
				fg = true;
			else
				cout << " ";
			cout << dp[v];
		}
		cout << endl;
		dp[ans] = q;
		fg = false;
		for (int v = ans; v > 0; v = v-dp[v]) {
			if (!fg)
				fg = true;
			else
				cout << " ";
			cout << dp[v];
		}
		cout << endl;
	}


}

#define SUBMIT
int main() {
#ifdef SUBMIT
	freopen("./test.in", "r", stdin);
	freopen("./test.out", "w", stdout);
#endif

	solve();

#ifdef SUBMIT
	fflush(stdout);
	cerr << "all done!" << endl;
#endif
	return 0;
}
