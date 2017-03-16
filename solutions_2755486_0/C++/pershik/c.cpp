#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <queue>
#include <deque>
#include <memory.h>
#include <complex>
#include <numeric>

#ifdef _GEANY
    #include "/home/pershik/debug_lib/debug.h"
#endif

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define INF (1000000000)
#define LINF (1000000000000000000ll)
#define EPS (1e-9)

#define MOD 1000000007

#define NAME "c_small"
#ifndef NAME
    #error Write problem name!
#endif

using namespace std;

typedef long long li;
typedef unsigned long long uli;

li gcd(li x, li y){
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

li lcm(li x, li y){
    return x / gcd(x, y) * y;
}

li binpow(li a, li p){
    if (!p)
        return 1;
    li g = binpow(a, p >> 1);
    if (p % 2 == 0)
        return (g * g) % MOD;
    else
        return (((g * g) % MOD) * a) % MOD;
}

li rev(li n){
    return binpow(n, (li)MOD - 2LL);
}

void solve(int test_number);

int main() {
#ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    freopen(NAME ".out", "w", stdout);
#endif
    cout.setf(ios::fixed);
    cout.precision(20);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve(i + 1);
}

const int SHIFT = 10000;

struct tribe {
    int s, ds;
    int d, dd;
    int n;
    int w, e, dp;
};

tribe a[1010];
int wall[100100];
priority_queue<pair<int, int> > q;
int n;
vector<pair<pair<int, int>, pair<int, int> > > b;

inline int attack(int l, int r, int s){
    //cerr << l - SHIFT << ' ' << r - SHIFT << ' ' << s << ' ';
    for (int i = l; i < r; i++)
        if (wall[i] < s){
            //cerr << 1 << endl;
            return 1;
        }
    //cerr << 0 << endl;
    return 0;
}

inline void update(int l, int r, int s){
    for (int i = l; i < r; ++i)
        wall[i] = max(wall[i], s);
}

void solve(int test_number) {
    memset(wall, 0, sizeof(wall));
    int res = 0;
    int i;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i].d >> a[i].n >> a[i].w >> a[i].e >> a[i].s >> 
            a[i].dd >> a[i].dp >> a[i].ds;
        a[i].w += SHIFT, a[i].e += SHIFT;
        q.push(mp(-a[i].d, i));
    }
    while (!q.empty()){
        b.clear();
        pair<int, int> g = q.top();
        q.pop();
        res += attack(a[g.se].w, a[g.se].e, a[g.se].s);
        b.pb(mp(mp(a[g.se].w, a[g.se].e), mp(a[g.se].s, g.se)));
        while (!q.empty() && q.top().fi == g.fi){
            g = q.top();
            q.pop();
            res += attack(a[g.se].w, a[g.se].e, a[g.se].s);
            b.pb(mp(mp(a[g.se].w, a[g.se].e), mp(a[g.se].s, g.se)));
        }
        for (i = 0; i < (int)b.size(); ++i){
            update(b[i].fi.fi, b[i].fi.se, b[i].se.fi);
            int ii = b[i].se.se;
            a[ii].d += a[ii].dd;
            a[ii].e += a[ii].dp;
            a[ii].w += a[ii].dp;
            a[ii].s += a[ii].ds;
            a[ii].n--;
            if (a[ii].n > 0){
                q.push(mp(-a[ii].d, ii));
            }
        }
    }
    cout << "Case #" << test_number << ": " << res << endl;
}

