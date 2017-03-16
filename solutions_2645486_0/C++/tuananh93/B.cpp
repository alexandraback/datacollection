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

int R, E, N, f[20][20], V[100];

int call(int work, int energy) {
    if (f[work][energy] != -1) return f[work][energy];
    if (work > N) {
        f[work][energy] = 0;
        return 0;
    }

    f[work][energy] = 0;

    FOR (i, 0, energy)
        f[work][energy] = max(f[work][energy], V[work] * i + call(work + 1, min(E, energy - i + R)));

    return f[work][energy];
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int ntest;
    cin >> ntest;
    LL r, t;
    FOR (test, 1, ntest) {
        cout << "Case #" << test << ": ";
        cin >> E >> R >> N;
        FOR (i, 1, N) cin >> V[i];

        RESET (f, -1);

        int res = call(1, E);

        cout << res << endl;
    }
    return 0;
}



