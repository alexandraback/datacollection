#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
    int mask = 0;
    int _n = n;
    while (true) {
        int x = n;
        while (x) {
            mask |= 1 << (x % 10);
            x /= 10;
        }
        if (mask + 1 == (1 << 10)) break;
        n += _n;
    }
    return n;
}

int main() {
    //freopen("A.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int ntest; cin >> ntest;
    for (int it = 1; it <= ntest; ++it) {
        cout << "Case #" << it << ": ";
        int n; cin >> n;
        if (n == 0) {
            cout << "INSOMNIA\n";
            continue;
        }
        cout << solve(n) << endl;
    }
    return 0;
}
