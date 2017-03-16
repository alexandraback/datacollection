#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

#define TASKNAME ""

void solve(int test_number);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i);
    }
}

const int MAX_N = 105;

void solve(int test_number) {
    cout << "Case #" << test_number + 1 << ": ";
    string s;
    cin >> s;
    int dp[MAX_N][2];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = (s[0] == '+');
    dp[0][1] = (s[0] == '-');
    // 0 minus 1 plus
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '-') {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][0] + 1;
        } else {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = dp[i - 1][1];
        }
    }
    cout << dp[s.size() - 1][1] << endl;
}
