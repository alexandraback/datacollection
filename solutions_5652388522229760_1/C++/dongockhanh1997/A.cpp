#include <bits/stdc++.h>
using namespace std;

int main() {
    int nt; cin >> nt;
    for (int tc = 1; tc <= nt; ++tc) {
        int n; cin >> n;
        cout << "Case #" << tc << ": ";
        if (n == 0) {
            cout << "INSOMNIA\n";
        } else {
            int mask = 0;
            for (long long mul = 1; ; ++mul) {
                long long x = mul * n;
                while (x > 0) {
                    mask |= 1 << (x % 10);
                    x /= 10;
                }
                if (mask == 1023) {
                    cout << mul * n << '\n';
                    break;
                }
            }
        }
    }
}
