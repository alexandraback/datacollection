#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
 
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
 
typedef long long int64;
 
using namespace std;

int64 reverse(int64 n) {
    if (n % 10 == 0) return n;
    int64 m = 0;
    while (n > 0) {
       m = 10 * m + n % 10;
       n /= 10;
    }
    return m;
}

int64 inf = 1000000000;

void solve() {
    int64 n;
    cin >> n;
    vector<int64> dp(n + 1, inf);
    dp[1] = 1;
    for (int64 i = 2; i <= n; ++i) {
       dp[i] = dp[i - 1] + 1;
       if (reverse(i) < i) {
           dp[i] = min(dp[i], dp[reverse(i)] + 1);
       }
    }
    cout << dp[n] << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    inf *= inf;
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
