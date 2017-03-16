#include <iostream>
#include <fstream>
#define ll long long
#include <string>
#include <vector>

using namespace std;

ll a, b, c, d, e, l, n;

string s;

int main() {
    //freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    cin >> a;
    cin >> l >> n;
    cout << "Case #1:\n";
    for (ll i = (1LL << (l - 1)) + 1; i < (1LL << l) && n; i += 2) {
        bool f = 1;
        vector<ll> ans;
        for (ll q = 2; q <= 10 && f; ++q) {
            ll pr = 0;
            ll tmp = i;
            while (tmp) {
                pr *= q;
                pr += (tmp & 1);
                tmp /= 2;
            }
            bool fl = 0;
            for (ll q = 2; q * q <= pr && q < 1000000 && !fl; ++q)
                if (pr % q == 0) fl = 1, ans.push_back(q);
            if (!fl) f = 0;
        }
        if (f) {
            //cout << n << "\n";
            ll tmp = i;
            while (tmp) cout << tmp % 2, tmp /= 2;
            for (int i = 0; i < ans.size(); ++i)
                cout << ' ' << ans[i];
            cout << "\n";
            --n;
        }
    }
}