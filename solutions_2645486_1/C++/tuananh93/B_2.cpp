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

#define maxn 10011

long long R, E, V[maxn];
int N;

int main() {
    freopen("B-large.in", "r", stdin);
    //freopen("a.in", "r", stdin);
    freopen("b2.out", "w", stdout);

    int ntest;
    cin >> ntest;
    LL r, t;
    cerr << ntest << endl;
    FOR (test, 1, ntest) {
        cout << "Case #" << test << ": ";
        cin >> E >> R >> N;
        FOR (i, 1, N) cin >> V[i];

        long long EN = E;
        long long res = 0;
       FOR (i, 1, N) {
            long long t = 1;
            FOR (j, i + 1, N)
                if (V[j] < V[i]) t++;
                else break;

            if (i + t - 1 == N) t = E;

            long long spen = min((long long) EN, EN + (long long)R * t - E );
            if (spen < 0) spen = 0;
            res += spen * V[i];
            //cerr << spen << " ";
            EN = min(EN - spen + R, E);
       }

        cout << res << endl;
    }
    return 0;
}



