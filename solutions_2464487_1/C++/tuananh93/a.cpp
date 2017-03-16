//Written by technolt~h

#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 #include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
 #include <complex>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
 #define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
 #define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define LL long long
#define PI acos(-1.0)

using namespace std;

int call(long long k, long long r, long long t) {
    if (k == 0) return 1;
    t/=k;
    if (t == 0) return -1;
    t -= 2 * r;
    if (t < 0) return -1;
    t -= -3 + (k + 1) * 2;
    if (t < 0) return -1;

    return 1;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("a2.out", "w", stdout);
    cerr << PI << endl;
    int ntest;
    cin >> ntest;
    LL r, t;
    FOR (test, 1, ntest) {
        cout << "Case #" << test << ": ";
        cin >> r >> t;

        long long res = 0, L, R;
        L = 0; R = t;
        while (L <= R) {

                long long mid = (L + R) / 2;
                if (call(mid, r, t) == 1) {
                    res = mid;
                    L = mid + 1;
                }
                else R = mid - 1;
        }
        cout << res << endl;
    }
    return 0;
}



