#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mypow(ll a, ll b) {
    if (b == 1) return a;
    if (b % 2 == 0) {
        ll x = mypow(a, b / 2);
        return x * x;
    } else {
        return a * mypow(a, b - 1);
    }
}

int main() {
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        ll k, c, s;
        cin >> k >> c >> s;
        cout << "Case #" << z << ":";
        for (int i = 1; i <= k; i++) {
            cout << " " << i;
        }
        cout << endl;
        continue;
        if (k == 1) {
            cout << " 1" << endl;
            continue;
        }
        if (c * s < k) {
            cout << " IMPOSSIBLE" << endl;
            continue;
        }
        if (c == 1) {
            for (int i = 1; i <= k; i++) {
                cout << " " << i;
            }
            cout << endl;
            continue;
        }
        ll qnt = 0;
        c = min(c, k);
        for (ll i = 0; i * c < k; i++) {
            ll x = mypow(k, c - 1);
            ll p = 0;
            while (x) {
                    //cout << "x = " << x << " " << x * qnt << endl;
                p += (x * (qnt++));
                x /= k;
                if (qnt == k) break;
            }
            cout << " " << ++p;
        }
        cout << endl;
    }
    return 0;
}
