#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define PROBLEM "A-large"

long long solve(long long n) {
    long long a = 1;
    int l = 0;
    for (; a <= n; a*= 10, ++l);
    long long r = 1, d1 = 9, d2 = 0, r1;
    for (int k = 1; k < l; ++k) {
        r += d1 + (d2 ? d2 + 1 : 0);
        d2 = d1;
        if ((k&1) == 0) { d1 *= 10; d1 += 9; }
    }
    ++d1; ++d2;

    if (n < d1) {
        r += n-1;
    } else if (n/d1 == d2/10) {
        r += n%d1;
    } else {
        r1 = r + n - d1*d2/10;

        if (n%d1 == 0) {
            --n;
            ++r;
        }
        r += n%d1;
        n /= d1;
        for (d2 /= 10; n; d2 /= 10) {
            r += (n % 10) * d2;
            n /= 10;
        }
        r = min(r, r1);
    }

    return r;
}

int main() {
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }

    return 0;
}
