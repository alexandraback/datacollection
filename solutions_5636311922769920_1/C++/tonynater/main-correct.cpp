#include <bits/stdc++.h>
using namespace std;

int n, d, q;

long long pos(int b, int x) {
    b = min(b, n - 1);
    if (x == 1) {
        return b;
    } else {
        long long scale = 1;
        for (int i = 1; i < x; i++) {
            scale = scale * n;
        }
        long long ret = b * scale + pos(b + 1, x - 1);
        return ret;
    }
}

void solve() {
    cin >> n >> d >> q;
    if (d * q < n) {
        cout << " IMPOSSIBLE";
        return;
    }

    for (int i = 0; i * d < n; i++) {
        cout << ' ' << pos(i * d, d) + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++) {
        cout << "Case #" << i << ":";
        solve();
        cout << '\n';
    }
    return 0;
}
