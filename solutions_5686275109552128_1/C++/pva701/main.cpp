#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef double db;
const int N = 1000;
int dp[N + 5][N + 5];

int solve(const vector <int>& a) {
    int mx = 0;
    for (int i = 0; i < a.size(); ++i)
        mx = max(mx, a[i]);
    int ans = mx;
    for (int t = 1; t <= mx; ++t) {
        int sm = 0;
        for (int i = 0; i < a.size(); ++i)
            sm += dp[a[i]][t];
        ans = min(ans, sm + t);
    }
    return ans;
}

void precalc() {
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j < i; ++j) dp[i][j] = N;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j < i; ++j) {
            for (int k = 1; k < i; ++k)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
        }
}

int main() {
    precalc();
    cerr << "finished" << endl;
    freopen("inputB-l.in", "r", stdin);
    freopen("outputB.out", "w", stdout);
    int t;
    cin >> t;
    for (int it = 1; it <= t; ++it) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        printf("Case #%d: %d\n", it, solve(a));
    }
    return 0;
}
