#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int c, int v, vector<int> &arr) {
    vector<bool> dp(v+1); dp[0] = 1;
    int ans = 0;

    for (int d : arr) {
        for (int i=v-d; i>=0; i--) {
            for (int j=1; j<=c; j++) {
                if (dp[i] && i + d*j <= v) {
                    dp[i+d*j] = 1;
                }
            }
        }
    }

    for (int i=1; i<=v; i++) {
        if (!dp[i]) {
            int d = i;
            ans++;
            for (int j=v-d; j>=0; j--) {
                for (int k=1; k<=c; k++) {
                    if (dp[j] && j + d*k <=v) {
                        dp[j+d*k] = 1;
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    int t, c, d, v;
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> c >> d >> v;
        vector<int> arr(d);
        for (int i=0; i<d; i++) cin >> arr[i];
        cout << "Case #" << i << ": " << solve(c, v, arr) << '\n';
    }
    return 0;
}
