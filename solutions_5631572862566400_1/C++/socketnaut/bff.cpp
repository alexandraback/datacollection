#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        vector<int> bff(N);

        for (int i = 0; i < N; i++) {
            cin >> bff[i];
            bff[i]--;
        }

        map<int, int> lc;

        int ans = 0;

        for (int sp = 0; sp < N; sp++) {
            vector<int> idx(N, -1);

            int val = sp, bef = -1;

            for (int i = 0; idx[val] == -1; i++) {
                idx[val] = i;
                bef = val;
                val = bff[val];
            }

            int cyc = idx[bef] - idx[val] + 1;

            if (cyc > 2) {
                ans = max(ans, cyc);
            } else {
                lc[val] = max(lc[val], idx[val]);
            }
        }

        int tot = 0;

        for (auto p : lc) {
            tot += p.second + 1;
        }

        cout << "Case #" << tc << ": " << max(ans, tot) << "\n";
    }

    return 0;
}

