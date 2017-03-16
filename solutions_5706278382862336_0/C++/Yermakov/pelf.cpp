#include <iostream>
#include <cstdio>

using namespace std;

long long gcd(long long a, long long b) {
    while (a > 0 && b > 0)
        if (a > b) a %= b;
        else b %= a;
    return a + b;
}

main () {
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long x, y;
        scanf ("%lld/%lld", &x, &y);
        long long g = gcd(x, y);
        x /= g;
        y /= g;
        long long z = y;
        while (z % 2 == 0) {
            z /= 2;
        }
        cout << "Case #" << t << ": ";
        if (z > 1) cout << "impossible";
        else {
            long long k = 0;
            while (y > x) {
                y /= 2;
                ++k;
            }
            cout << k;
        }
        cout << "\n";
    }
}
