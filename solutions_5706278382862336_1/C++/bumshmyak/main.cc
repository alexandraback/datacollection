#include <iostream>
#include <cmath>
#include <vector>
#include <memory.h>
#include <iterator>
#include <sstream>

using namespace std;

typedef long long ll;

bool is_pow_2(ll x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n_tests;
    cin >> n_tests;
    for (int t = 1; t <= n_tests; ++t) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '/') {
                s[i] = ' ';
            }
        }
        ll p, q;
        stringstream ss(s);
        ss >> p >> q;
        ll g = gcd(p, q);
        p /= g;
        q /= g;

        int ans;
        if (!is_pow_2(q)) {
            ans = -1;
        } else {
            ans = 0;
            while (p < q) {
                p *= 2LL;
                ++ans;
            }
        }

        cout << "Case #" << t << ": ";
        if (ans == -1) {
            cout << "impossible" << endl;
        } else {
            cout << ans << endl;
        }
    }



    return 0;
}

