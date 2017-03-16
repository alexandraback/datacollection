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
#define SZ(a) ((int)a.size())
using namespace std;

const double PI = 2.0 * acos (0.0);

typedef pair <int, int> PII;

template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }


bool cmp(double x, double y) {
    return x > y;
}

int main() {
    freopen("D-large.in","r",stdin);
    freopen("D-large.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    FOR(test, 1, ntest) {
        cout << "Case #" << test << ": ";
        vector<double> A;
        vector<double> B;
        int n;
        cin >> n;
        FOR(i, 1, n) {
            double x;
            cin >> x;
            A.PB(x);
        }
        sort(A.begin(), A.end());
        FOR(i, 1, n) {
            double x;
            cin >> x;
            B.PB(x);
        }
        vector<double> AA = A;
        sort(AA.begin(), AA.end(), cmp);
        sort(B.begin(), B.end(), cmp);
        int res1 = 0;
        REP(i, n) {
            bool ok = true;
            REP(j, AA.size()) if (AA[j] < B[i + j]) {
                ok = false;break;
            }
            if (ok) {
                res1 = n - i;
                break;
            } else {
                AA.pop_back();
            }
        }
        int res2 = 0;
        REP(i, n) {
            while (B.size() && B[B.size() - 1] < A[i]) B.pop_back();
            if (B.size() == 0) res2++; else B.pop_back();
        }
        cout << res1 << ' ' << res2 << endl;
    }
    return 0;
}
