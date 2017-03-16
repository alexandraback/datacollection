#include <bits/stdc++.h>

using namespace std;

const int N = 2505;

bool v[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int ntest; cin >> ntest;
    for (int it = 1; it <= ntest; ++it) {
        cout << "Case #" << it << ": ";
        cin >> n;
        memset(v, 0, sizeof v);
        for (int i = 1; i < 2 * n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x; cin >> x;
                v[x] ^= 1;
            }
        }
        int cnt = 0;
        for (int i = 1; i < N; ++i)
            if (v[i]) cout << i << ' ', ++cnt;
        assert(cnt == n);
        cout << endl;
    }
    return 0;
}
