#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 40;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll pows[N + 1];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    pows[0] = 1;
    for (int i = 1; i <= N; i++)
        pows[i] = pows[i - 1] * 2;
    int t;
    cin >> t;
    for (int l = 0; l < t; l++) {
        cout << "Case #" << l + 1 << ": ";
        ll p, q;
        scanf("%lld/%lld", &p, &q);
        ll g = gcd(p, q);
        p /= g, q /= g;
        bool ok = 0;
        for (int i = 1; i <= N; i++) {
            if (pows[40] % q == 0) {
                double d = p * 1.0 * (pows[N] / q);
                if (d > 1e18)
                    continue;
                ll s = p * (pows[N] / q) - pows[N - i];
                if (s >= 0 && s <= pows[N - 1]) {
                    ok = 1;
                    cout << i;
                    break;
                }
            }
        }
        if (!ok)
            cout << "impossible";
        cout << endl;
    }
    return 0;
}
