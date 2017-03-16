#include <complex>
#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
using namespace std;

void smain();
clock_t start;
int main(){
    ios_base::sync_with_stdio(0);
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/C-small-attempt0.in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    start = clock();
#endif
    cout.precision(12); cout << fixed;
    smain();
#ifdef TASK
    cerr << "\nTotal Execution Time: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
#ifndef M_PI
#define M_PI 3.14159265358979311599796346854418516
#endif
#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define int long long
#define LL long long
#define mp(a,b) make_pair(a,b)
#define INF 2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-12
#define N 20
/* --------- END TEMPLATE CODE --------- */
#define BIT(m, i) (((m) >> (i)) & 1)

int n;
string a[N], b[N];

int naive() {
    int res = 0;
    int mm = 1 << n;
    forn(mask, mm) {
        int v = __builtin_popcount(mask);
        int x = mask;
        for (;;) {
            bool ok = false;
            forn(i, n) if (!BIT(x, i)) {
                bool f = 0;
                forn(j, n) if (!f && BIT(x, j)) {
                    forn(k, j) if (!f && BIT(x, k)) {
                        if (a[j] == a[i] && b[k] == b[i]) f = 1;
                        else if (b[j] == b[i] && a[k] == a[i]) f = 1;
                    }
                }
                if (f) {
                    ok = true;
                    x |= 1 << i;
                    break;
                }
            }
            if (!ok) break;
        }
        if (x == mm - 1) {
            res = max(res, n - v);
        }
    }
    return res;
}

void smain() {
    cin >> n;
    for (int cas = 1; cin >> n; ++cas) {
        forn(i, n) cin >> a[i] >> b[i];
        int res = naive();
        cout << "Case #" << cas << ": " << res << '\n';
        cerr << "Case #" << cas << ": " << res << '\n';
    }
}
