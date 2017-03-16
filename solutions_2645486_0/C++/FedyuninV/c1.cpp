#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <utility>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)

int dp[11][7];
int main() {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    forn (test, tests) {
        forn(i, 7)   forn (j, 11) dp[j][i] = -1;
        int e, r, n, a;

        cin >> e >> r >> n;
        dp[0][e] = 0;
        forn (i, n) {
            cin >> a;
            forn (j, e + 1) {
                if (dp[i][j] != -1) {
                    for(int waste = 0; waste <= j; waste++) {
                        dp[i + 1][min(j - waste + r, e)] = max(dp[i + 1][min(j - waste + r, e)], dp[i][j] + a * waste);
                    }
                }
            }
        }
        int ans = 0;
        forn(i, e + 1) {
            ans = max(ans, dp[n][i]);
        }
        cout << "Case #" << test + 1 << ": " << ans << endl;
    }
	return 0;
}
