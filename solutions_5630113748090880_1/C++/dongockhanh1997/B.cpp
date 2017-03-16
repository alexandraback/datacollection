#include <bits/stdc++.h>
using namespace std;

int cnt[3000];

int main() {
    ios::sync_with_stdio(false);
    int nt; cin >> nt;
    for (int tc = 1; tc <= nt; ++tc) {
        memset(cnt, 0, sizeof cnt);
        int n; cin >> n;
        for (int i = 0; i < 2 * n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int x; cin >> x;
                ++cnt[x];
            }
        }
        int tmp = 0;
        cout << "Case #" << tc << ":";
        for (int i = 1; i <= 2500; ++i) if (cnt[i] % 2 != 0) {
            cout << ' ' << i;
            ++tmp;
        }
        cout << '\n';
        assert(tmp == n);
    }
    return 0;
}
