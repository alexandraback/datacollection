#include <iostream>
#include <fstream>
#define ll long long
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

ll a, b, c, d, e, l, n;

string s;

ll MOD = (1 << 31);

class lll {
public:
    ll a, b, c;
    lll(int x) : a(0), b(0), c(x) {}
    void fix() {
        b += c / MOD;
        c %= MOD;
        a += b / MOD;
        b %= MOD;
    }
    void operator *=(int x) { c *= x; b *= x; a *= x; fix();  }
    void operator +=(ll x) { c += x; fix(); }
    ll operator %(ll x) { lll tmp = *this; tmp.b += tmp.a % x * MOD;
    tmp.c += tmp.b % x * MOD; return tmp.c % x;
    }
};

int main() {
    //freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    cin >> a;
    cin >> l >> n;
    cout << "Case #1:\n";
    for (ll i = (1LL << (l - 1)) + 1; i < (1LL << l) && n; i += 2) {
        bool f = 1;
       //  __int128_t
        vector<ll> ans;
        for (ll q = 2; q <= 10 && f; ++q) {
            lll pr(0);
            ll tmp = i;
            while (tmp) {
                pr *= q;
                pr += (tmp & 1);
                tmp /= 2;
            }
            bool fl = 0;
            for (ll q = 2; q < 10000 && !fl; ++q)
                if (pr % q == 0) fl = 1, ans.push_back(q);
            if (!fl) f = 0;
        }
        if (f) {
            cerr << n << "\n";
            ll tmp = i;
            while (tmp) cout << tmp % 2, tmp /= 2;
            for (int i = 0; i < ans.size(); ++i)
                cout << ' ' << ans[i];
            cout << "\n";
            --n;
        }
    }
}