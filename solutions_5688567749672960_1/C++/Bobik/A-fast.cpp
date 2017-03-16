// {{{
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define FOR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))
#define DEBUG(x) { cerr << #x << ": " << (x) << endl; }
#define SQR(x) ((x) * (x))
#define INF 1023456789
using namespace std;

template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os;
}

template<typename T> ostream& operator << (ostream& os, const vector<T>& v) {
    os << "["; FORE(i, v) { if (i != v.begin()) os << ", "; os << *i; } os << "]"; return os;
}

typedef long long LL;
typedef pair<int, int> PI;
typedef pair<int, PI> TRI;
typedef vector<int> VI;
typedef vector<VI> VVI;
// }}}

LL reverse(LL x) {
    LL res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

LL solve(LL n, LL b) {
    if (n == b)
        return 0;
    if (b == 1)
        return n - b;

    LL res2 = n - b;

    LL w = 1, t = b;
    while (t > 1) {
        w *= 10;
        t /= 100;
    }

    LL res = 0;
    if (n % w == 0) {
        --n;
        ++res;
    }
    res += n % w - 1;
    ++res;
    res += reverse(n / w);

    return min(res, res2);
}

int main() {
    int t;
    scanf("%d", &t);
    FOR(ti, 1, t) {
        LL n;
        scanf("%lld", &n);

        LL x = 1;
        while (10 * x <= n)
            x *= 10;
        LL res = solve(n, x);
        while (x > 1) {
            res += solve(x - 1, x / 10) + 1;
            x /= 10;
        }

        printf("Case #%d: %lld\n", ti, res + 1);
    }
}
