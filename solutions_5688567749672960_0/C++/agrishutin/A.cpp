#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<int> dp;

int revert(int num) {
    int ans = 0, tmp = num;
    while (tmp > 0) {
        ans *= 10;
        ans += (tmp % 10);
        tmp /= 10;
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(revert(10) == 1);
    assert(revert(179) == 971);
    assert(revert(1) == 1);

    cin >> t;
    for (int t_c=0; t_c < t; t_c++) {
        cin >> n;
        dp.assign(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i > 0; i--) {
            int reverted = revert(i);
            dp[i] = dp[i + 1] + 1;
            if (i < reverted && reverted <= n) {
                dp[i] = min(dp[i], dp[reverted] + 1);
            }
            //cerr << i << " reverted is " << reverted << " ans is " <<  dp[i] << "\n";
        }
        printf("Case #%d: %d\n", t_c + 1, dp[1]);
    }
    return 0;
}
