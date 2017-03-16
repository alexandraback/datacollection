#include <bits/stdc++.h>
using namespace std;

int main() {
    int nt; cin >> nt;
    for (int tc = 1; tc <= nt; ++tc) {
        cout << "Case #" << tc << ":\n";
        int n; cin >> n;
        int j; cin >> j;
        int x = (1 << n) - 1;
        for (int mask = 0; mask < j; ++mask) {
            int foo = x;
            for (int i = 0; i < (n - 4) / 2; ++i) {
                if ((mask & 1 << i) != 0) {
                    foo &= ~(3 << (2 * i + 2));
                }
            }
            for (int i = n - 1; i >= 0; --i) cout << (foo >> i & 1);
            for (int i = 2; i <= 10; ++i) cout << ' ' << i + 1;
            cout << '\n';
        }
    }
    return 0;
}
