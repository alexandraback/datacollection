#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T, D;
vector<int> v;
int K;

int getCnt(int val, int k) {
    if (val <= k) return 0;
    int res = val / k;
    if (val % k != 0) ++res;
    return res - 1;
}

void solve() {
    int res = K, cnt;
    for (int k = 1; k <= K; ++k) {
        cnt = 0;
        for (int i = 0; i < D; ++i) {
            cnt += getCnt(v[i], k);
        }
        res = min(res, cnt + k);
    }
    cout << res << endl;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        cin >> D; 
        v.resize(D);
        K = 0;
        for (int i = 0; i < D; ++i) {
            cin >> v[i];
            K = max(K, v[i]);
        }
        solve();
    }
    return 0;
}
