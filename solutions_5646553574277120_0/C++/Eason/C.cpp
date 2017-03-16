#include <bits/stdc++.h>
using namespace std;

int T;
int C, D, V;
vector<int> v;
vector<bool> dp;

void solve() {
    int cnt = 0;
    dp[0] = true;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = V; j >= v[i]; --j) {
            if (dp[j-v[i]]) dp[j] = true;
        }
    }
    for (int i = 1; i <= V; ++i) {
        if (!dp[i]) {
            ++cnt;
            for (int j = V; j >= i; --j) {
                if (dp[j-i]) dp[j] = true;
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    //freopen("c.in", "r", stdin);
    cin >> T;
    for (int caseID = 1; caseID <= T; ++caseID) {
        cin >> C >> D >> V;
        v.resize(D);
        dp.assign(V + 1, false);
        for (int i = 0; i < D; ++i) {
            cin >> v[i];
        }
        cout << "Case #" << caseID << ": ";
        solve();
    }
    return 0;
}
