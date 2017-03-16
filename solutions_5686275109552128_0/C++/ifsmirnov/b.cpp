#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 1050;
int n, a[maxn];

int solve() {
    cin >> n;
    forn(i, n) cin >> a[i];
    int mn = inf;
    fore(t, 1, 1000) {
        int res = t;
        forn(i, n) res += (a[i]+t-1)/t - 1;
        mn = min(mn, res);
    }
    return mn;
}

int main() {
#ifdef HOME
//     freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    fore(i, 1, t) {
        cout << "Case #" << i << ": " << solve() << endl;
    }

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
