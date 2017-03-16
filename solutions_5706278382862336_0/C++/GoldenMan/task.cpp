#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

long long gcd(long long a, long long b) {
    return a ? gcd(b % a, a) : b;
}

long long pot(long long x) {
    long long ans = 0;
    long long cur = 1;
    while (cur < x) {
        cur *= 2;
        ++ans;
    }
    return ans;
}

long long pot2(long long x) {
    long long ans = 0;
    long long cur = 1;
    while (cur * 2 <= x) {
        cur *= 2;
        ++ans;
    }
    return ans;
}

bool ispot(long long x) {
    long long cur = 1;
    while (cur < x) {
        cur *= 2;
    }
    return cur == x;
}

int solve(int test) {
    long long a, b;
    scanf("%lld/%lld", &a, &b);
    long long d = gcd(a, b);
    a /= d;
    b /= d;
    bool ok = true;
    int ans = 0;
    long long pw = pot(b);
    long long pw2 = pot2(a);
    if (a > b) {
        ok = false;
        goto lbl;
    }
    if (!ispot(b)) {
        ok = false;
        goto lbl;
    }
    if (a == 0) {
        ok = false;
        goto lbl;
    }
    ans = pw - pw2;
    lbl:;
    if (ok)
        cout << "Case #" << test << ": " << ans << endl;
        else
        cout << "Case #" << test << ": " << "impossible" << endl;
    return 0;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; ++_) {
        solve(_ + 1);
    }
    return 0;
}
