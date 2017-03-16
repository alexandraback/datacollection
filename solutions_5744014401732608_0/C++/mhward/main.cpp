#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int64_t> dpt(55, 1);
    for (int i = 1; i < 55; ++i) {
        int64_t ans = 0;
        for (int j = i-1; j >= 0; --j) ans += dpt[j];
        dpt[i] = ans;
    }
    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        int64_t B, M;
        cin >> B >> M;
        cout << "Case #" << tc << ": ";
        vector<vector<bool>> adj(B, vector<bool>(B));
        for (int i = 0; i < B; ++i) {
            for (int j = i+1; j < B; ++j) {
                adj[i][j] = true;
            }
        }
        M = dpt[B-1]-M;
        bool fugg = false;
        if (M < 0) fugg = true;
        if (!fugg) {
            for (int64_t bit = 60; bit>=0; --bit)
                if ((((int64_t) 1) << bit) & M) {
                    bool done = false;
                    int64_t val = (1 << bit);
                    for (int i = 0; !done && i<B-2; ++i) {
                        for (int j = B-1; !done && j>i; --j) {
                            if (!adj[i][j]) continue;
                            if (dpt[(B-1)-j]==val) {
                                adj[i][j] = false;
                                done = true;
                            }
                        }
                    }
                    if (!done) {
                        fugg = true;
                        break;
                    }
                    M -= val;
                }
        }
        if (fugg) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            for (int i = 0; i < B; ++i) {
                for (int j = 0; j < B; ++j) {
                    cout << adj[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}