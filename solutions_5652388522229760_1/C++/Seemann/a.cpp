#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e5;

void solve() {
    ll n;
    cin >> n;
    if (n == 0) {
        printf("INSOMNIA\n");
        return;
    }
    bitset<10> digits, full;
    full.flip();
    ll cur = n;
    while (true) {
        ll w = cur;
        while (w > 0) {
            ll d = w % 10;
            digits[d] = true;
            w /= 10;
        }
        if (digits == full) {
            break;
        }
        cur += n;
    }
    cout << cur << '\n';
}
int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int T;
    cin >> T;
    forn(test, T) {
        printf("Case #%d: ", test + 1);
        solve();
    }
    return 0;
}

