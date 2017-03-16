#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int D;
vector<int> P;

int solve() {
    int p_max = *max_element(P.begin(), P.end());
    int ans = -1;
    for (int p = 1; p <= p_max; p++) {
        int split = 0;
        for (int i = 0; i < D; i++) {
            split += (P[i] + p - 1) / p - 1;
        }
        if (ans < 0 || ans > split + p) {
            ans = split + p;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> D;
        P.clear();
        for (int i = 0; i < D; i++) {
            int p;
            cin >> p;
            P.push_back(p);
        }
        int ans = solve();

        cout << "Case #" << testcase << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
