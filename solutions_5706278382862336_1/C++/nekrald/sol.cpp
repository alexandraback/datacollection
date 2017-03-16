#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int ntc; cin >> ntc;
    for (int _ = 1; _ <= ntc; ++_) {
        ll p, q; char c;
        cin >> p >> c >>  q;
        ll div = __gcd(p, q);
        p /= div; q /= div;
        ll qcp = q;
        int pow2 = 0;
        while (!(q & 1)) {
            ++pow2;
            q >>= 1;
        }
        bool ok = true;
        if (q != 1 || pow2 > 40) ok = false;

        int add2 = 40 - pow2;
        while (p) {
            ++add2;
            p >>= 1;
        }
        cout << "Case #" << _ << ": ";
        if (ok) {
            cout << 41 - add2 << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
}
