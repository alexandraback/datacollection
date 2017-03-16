#include <bits/stdc++.h>

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;

bool ok(int num, int D, const vector<int>& p) {
    for (int i = 0; i < num; i++) {
        // 最初のi回dinnerを移してnum-i回でdinnerを食えるか
        // 要するにすべての要素をnum-i以下にすれば良い
        vector<int> q = p;
        int cnt = 0;
        for (int j = 0; j < D; j++) {
            if (q[j] > num-i) {
                while (cnt <= i && q[j] > num-i) {
                    cnt++;
                    q[j] -= num-i;
                }
                if (cnt > i) break;
            }
        }
        if (cnt <= i) return true;
    }
    return false;
}

int solve(int D, const vector<int>& p) {
    int low = 0, high = 1000;
    while (high - low > 1) {
        int med = (high + low) / 2;
        if (ok(med, D, p)) high = med;
        else low = med;
    }
    return high;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int D;
        cin >> D;
        vector<int> v(D);
        for (int i = 0; i < D; i++) cin >> v[i];
        printf("Case #%d: %d\n", t, solve(D, v));
    }
    return 0;
}
