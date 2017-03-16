#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll binpow(ll x, ll deg) {
    if (deg == 0LL) return 1LL;
    if (deg & 1LL) return x * binpow(x, deg - 1LL);
    x = binpow(x, deg >> 1LL);
    return x * x;
}

ll k, c, s, t;

int main()
{
    //freopen("D-small-attempt0.in", "r", stdin);
    //freopen("D-small-attempt0.out", "w", stdout);

    cin >> t;
    for (int ttt = 1; ttt <= t; ++ttt) {
        cin >> k >> c >> s;
        if (k > s * c) {
            cout << "Case #" << ttt << ": IMPOSSIBLE\n";
        } else {
            cout << "Case #" << ttt << ":";
            ll curidx = 0;
            ll cur, step;
            for (int i = 0; i < s && curidx < k; ++i) {
                cur = 0, step = binpow(k, c - 1);
                for (int j = 0; j < c; ++j) {
                    cur += min(curidx, k - 1) * step;
                    step /= k;
                    ++curidx;
                }
                cout << " " << cur + 1;
            }
            cout << "\n";
        }
    }

    return 0;
}
