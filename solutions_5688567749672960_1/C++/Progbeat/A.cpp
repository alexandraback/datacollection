#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

long reverse(long x) {
    if (x % 10 == 0)
        return x;
    long y = 0;
    for (; x; x /= 10)
        y = y * 10 + (x % 10);
    return y;
}

int log10(long x) {
    int k = 1;
    for (; x >= 10; x /= 10)
        ++k;
    return k;
}

long solve(long n) {
    if (n < 10)
        return n;
    if (n % 10 == 0)
        return solve(n - 1) + 1;
    int f = log10(n);
    long z = 1;
    REP (i, (f + 1) / 2)
        z *= 10;
    long r = n % z;
    if (r != 1) {
        --r;
        return solve(n - r) + r;
    }
    long y = reverse(n);
    if (n != y)
        return solve(y) + 1;
    return solve(n - 2) + 2;
}

int main() {
    int tests, tc = 0;
    for (cin >> tests; tc ++< tests; ) {
        long n;
        cin >> n;
        cout << "Case #" << tc << ": " << solve(n) << endl;
    }
    return 0;
}
