#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cassert>
#include <numeric>
#include <sstream>
#include <limits>
using namespace std;

#define REQUIRE(cond, message) \
    do { \
        if (!(cond)) { \
            std::cerr << message << std::endl; \
            assert(false); \
        } \
    } while (false)

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, (v).size())
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef long double ld;

template<typename T>
inline int popcount(T t) {
    if (std::numeric_limits<T>::digits <=
                            std::numeric_limits<unsigned int>::digits) {
        return __builtin_popcount(t);
    } else {
        return __builtin_popcountll(t);
    }
}

const ld EPS = 1e-8;
const ld PI = acosl(0.0) * 2;

ll solveInternal()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = 0;
    int n = 0;
    while (a >= (1LL << n)) ++n;
    while (b >= (1LL << n)) ++n;
    for (int i = n; i >= 0; --i) {
        if (((a >> i) & 1) == 0) continue;
        for (int j = n; j >= 0; --j) {
            if (((b >> j) & 1) == 0) continue;
            ll aa = a ^ (1LL << i);
            ll bb = b ^ (1LL << j);
            int mx = max(i, j);
            ll cc = (aa >> mx) & (bb >> mx);
            if (cc > (k >> mx)) continue;
            if (cc < (k >> mx)) {
                ans += 1LL << (i + j);
                continue;
            }
            ll mul = 1;
            ll add = 1LL << (i + j);
            bool ok = true;
            for (int t = mx - 1; t >= min(i, j); --t) {
                add >>= 1;
                cc = (aa >> t) & (bb >> t);
                if (cc < (k >> t)) {
                    ans += add * mul;
                }
                int cnt = 0;
                if (cc == (k >> t)) ++cnt;
                if (i > j) aa ^= 1LL << t;
                else bb ^= 1LL << t;
                cc = (aa >> t) & (bb >> t);
                if (cc < (k >> t)) {
                    ans += add * mul;
                }
                if (cc == (k >> t)) ++cnt;
                if (cnt == 0) {
                    ok = false;
                    break;
                }
                if (cc != (k >> t)) {
                    if (i > j) aa ^= 1LL << t;
                    else bb ^= 1LL << t;
                }

                mul *= cnt;
            }
            if (ok) {
                int mn = min(i, j);
                for (int t = mn - 1; t >= 0; --t) {
                    if ((k >> t) & 1) {
                        ans += mul * 3 << (t * 2);
                    }
                    else {
                        mul *= 3;
                    }
                }
            }
        }
    }
    return ans;
}

void solve()
{
    int tc;
    cin >> tc;
    forn(it, tc) {
        cout << "Case #" << it + 1 << ": " << solveInternal() << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
