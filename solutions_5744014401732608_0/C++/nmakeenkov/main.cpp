#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int c = 0; c < t; ++c) {
        long long b, m;
        cin >> b >> m;
        vector<long long> pw(b);
        vector<vector<int>> ans(b, vector<int>(b, 0));
        pw[b - 1] = 1;
        pw[b - 2] = 1;
        ans[b - 2][b - 1] = 1;
        int r = -1;
        if (m == 1) {
            r = b - 2;
        }
        for (int i = b - 3; i >= 0; --i) {
            pw[i] = pw[i + 1] * 2LL;
            if (pw[i] >= m) {
                r = i;
                break;
            }
            for (int j = i + 1; j < b; ++j) {
                ans[i][j] = 1;
            }
        }
        if (r != -1) {
            if (r != 0) {
                ans[0][r] = 1;
            }
            for (int i = r + 1; i < b; ++i) {
                if (pw[i] <= m) {
                    m -= pw[i];
                    ans[r][i] = 1;
                } else {
                    ans[r][i] = 0;
                }
            }
        }
        cout << "Case #" << c + 1 << ": ";
        if (m == 0) {
            cout << "POSSIBLE\n";
            for (int i = 0; i < b; ++i) {
                for (int j = 0; j < b; ++j) {
                    cout << ans[i][j];
                }
                cout << "\n";
            }
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}