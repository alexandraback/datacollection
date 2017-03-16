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

ll A, B;
ll str_int(string s) {
    istringstream is(s);
    ll x;
    is >> x;
    return x;
}

void analyze(string s) {
    int p = s.find("/");
    string s1, s2;
    s1 = s.substr(0, p);
    s2 = s.substr(p + 1);
    A = str_int(s1);
    B = str_int(s2);
    ll x = __gcd(A, B);
    A /= x;
    B /= x;
}

void sub(ll &A, ll &B, ll C, ll D) {
    while (B < D) {
        A *= 2;
        B *= 2;
    }
    while (D < B) {
        C *= 2;
        D *= 2;
    }
    ll AA = A - C;
    ll BB = B;
    A = AA/__gcd(AA, BB);
    B = BB/__gcd(AA, BB);
}

void solve2() {
    ll j = 1;
    for(int i = 0; i <= 40; i++, j*=2) {
        if (A * j % B == 0) {
            int res = 0;
            ll jj = j;
            for (int ii = i; ii >= 1; ii--, jj/=2) {
//                add(A, B, 1, jj);
                res++;
                if (A == B) break;
            }
            cout << res << endl;
            return;
        }
    }

    cout << "impossible" << endl;
}

bool ok(ll A, ll j, ll B) {
    if (A == 0) return true;
    B/= __gcd(A, B);
    B/= __gcd(j, B);
    return B == 1;
}

void solve() {
    ll j = 1;
    ll jj = 0;
    bool found = false;
    for(int i = 0; i <= 40; i++, j*=2) {
        if (ok(A, j, B)) {
            found = true;
            jj = j;
            break;
        }
    }

    if (!found) {
        cout << "impossible" << endl;
        return;
    }
    j = 2;
    for (int i = 1; i <= 40; i++, j*=2) {
        ll AA = A, BB = B;
        sub(A, B, 1, j);
        if (A >= 0 && B >= 0 && A <= B && ok(A, jj, B)) {
            cout << i << endl;
            return;
        }
        A = AA;
        B = BB;
    }
}
int main() {
    freopen("A-large.in","r",stdin);
    freopen("a.out", "w", stdout);
    ios::sync_with_stdio(false);
    int _;
    cin >> _;
    FOR(test, 1, _) {
        cout << "Case #" << test << ": ";
        string s;
        cin >> s;
        analyze(s);
        solve();
    }
    return 0;
}
