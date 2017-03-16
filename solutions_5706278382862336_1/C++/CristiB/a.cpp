#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

typedef double real;

int solve(ll p, ll q) {
    //cerr << "P = " << p << " Q = " << q << endl;
    ll g = gcd(p, q);
    p /= g;
    q /= g;
    //cerr << "G = " << g << endl;

    real f = (real)p / q;
    //cerr << "F = " << f << endl;
    int best = -1;
    for (int i = 0; i <= 40; ++i) {
        if (f >= 1.0 && best == -1)
            best = i;
        f *= 2;
        //cout << "F = " << f << " best = " << best << endl;
    }

    if (f - floor(f) < 1e-13) {
        return best;
    }

    return -1;
}

int main() {
    int T;

    cin >> T;
    for (int t = 1; t <= T; ++t) {
        ll p, q;
        char c;
        cin >> p >> c >> q;
        int res = solve(p, q);
        if (res == -1)
            cout << "Case #" << t << ": " << "impossible" << endl;
        else
            cout << "Case #" << t << ": " << res << endl;
    }
        
    return 0;
}
