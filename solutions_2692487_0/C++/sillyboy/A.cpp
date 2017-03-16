//written by HTTPs - Ho Sy Viet Anh
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
#define ll long long
#define PII pair <int, int>

using namespace std;

#define maxn 100011

ll A;
int a[maxn];
int ntest;
int n;

void process() {
    sort(a + 1, a + n + 1);
    if (A == 1) {
        cout << n << endl;
        return;
    }
    int i = 1;
    int res = 1000;
    int d = 0;
    while(i <= n) {
        res = min(res, d + n - i + 1);
        if (A <= a[i]) {
            d++;
            A = 2 * A - 1;
        } else {
            A += a[i];
            i++;
        }
    }
    res = min(res, d);
    cout << res << endl;
}

int main () {
    freopen("A-small.in", "r", stdin);
    freopen("A.out", "w", stdout);
    cin >> ntest;
    FOR(test, 1, ntest) {
        cin >> A >> n;
        FOR(i, 1, n) scanf("%d", a + i);
        cout << "Case #" << test << ": ";
        process();
    }
    return 0;
}
