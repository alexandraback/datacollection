#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
#include "queue"
#include "stack"
#include "cmath"
#include "string"
#include "cctype"
#include "map"
#include "iomanip"
#include "set"
#include "utility"
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define ull unsigned long long
const int inf = 1 << 29;
const double dinf = 1e30;
const ll linf = 1LL << 55;
ll r, t;
ll calc(ll r, ll t) {
    return 2 * r * t + t * (2 * t - 1);
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("a-large.out", "w", stdout);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cin >> r >> t;
        ll lo = 0, hi = min(t * 3 / r, (ll)sqrt(t * 3));
        ll ans = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if (calc(r, mid) <= t) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        printf("Case #%d: ", Case++);
        cout << ans << endl;
    }
    return 0;
}
