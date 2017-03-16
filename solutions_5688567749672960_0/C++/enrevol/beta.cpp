#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1000010;

int dp[MAX];
int pred[MAX];

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 1;
    for (int i = 1; i + 1 < MAX; ++i) {
        if (dp[i + 1] > dp[i] + 1) {
            dp[i + 1] = dp[i] + 1;
            pred[i + 1] = i;
        }
        string s = to_string(i);
        reverse(s.begin(), s.end());
        int j = stoi(s);
        if (j < MAX) {
            if (dp[j] > dp[i] + 1) {
                dp[j] = dp[i] + 1;
                pred[j] = i;
            }
        }
    }
    int tt;
    cin >> tt;
    for (int ti = 1; ti <= tt; ++ti) {
        long long n;
        cin >> n;
        cout << "Case #" << ti << ": " << dp[n] << '\n';
    }
}
