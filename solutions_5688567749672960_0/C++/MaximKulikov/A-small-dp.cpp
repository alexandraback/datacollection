#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define PROBLEM "A-small-attempt2"

int dp[1 << 20];

int rev(int a) {
    int r = 0;
    while(a) {
        r *= 10;
        r += a%10;
        a /= 10;
    }
    return r;
}

void init() {
    memset(dp, 0x7f, sizeof(dp));
    dp[1] = 1;
    for (int i = 1; i < 1000000; ++i) {
        dp[i+1] = min(dp[i+1], dp[i] + 1);
        int a = rev(i);
        dp[a] = min(dp[a], dp[i] + 1);
    }
}

int solve(int n) {
    return dp[n];
}

int main() {
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);

    init();

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }

    return 0;
}
