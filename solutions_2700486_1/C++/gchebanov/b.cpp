#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>

#define fore(i,a,b) for(int i = (int)(a); i <= (int)(b); ++i)
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long i64;
typedef long double ld;

const int maxn = 5000;

ld p[maxn][maxn];

void init() {
    p[0][0] = 1;
    forn(s, maxn) if(s) {
        p[0][s] = p[s][0] = p[0][s-1] / 2;
        forn(i, s) if(i)
            p[i][s-i] = (p[i-1][s-i] + p[i][s-i-1]) / 2;
    }
}

ld f(int a, int b, int l, bool& flag) {
    //return C_(a+b)^b / 2^(a+b)
    if ( a < 2 * l && b < 2 * l ) {
        assert(a < maxn && b < maxn && a + b < maxn );
        return p[a][b];
    } else if ( a == 2 * l || b == 2 * l ) {
        ld res = 0;
        fore(i, 2 * l, a + b) res += p[a + b - i][i];
        return res;
    } else {
        flag = 1;
        return p[a][b];
    }
}

ld solve(int n, int x, int y) {
    if( x < 0 ) x = -x;
    int l = (x + y) / 2;
    int s0 = 0;
    forn(i, l) {
        s0 += 4*i + 1;
    }
    if( n <= s0 ) return 0.;
    n -= s0;
    if( n >= 4 * l + 1 ) return 1.;
    if( y == 2* l ) return 0;
    if( y + 1 <= n - 2 * l ) return 1.;
    ld ans = 0;
    ld ansp = 1;
//  cerr << n << ' ' << y + 1 << ' ' << 2 * l + 1 << '\n';
    fore(i, 0, 2 * l ) {
        bool flag = 0;
//      cerr << i << ' '  << n - i << ' ' << l << ':' << f(i,n-1,l) << '\n'
        ld t = f( i, n - i, l, flag);
        //cerr << flag << ' ' << t << '\n';
        if( flag ) {
            ansp -= t; 
        } else {
            if (i >= y + 1) ans += t;
        }
    }
    //cerr << ans << ' ' << ansp << '\n';
//    ans /= ansp;
    return ans;
}


int main() {
    init();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    cout << fixed;
    cout.precision(8);
    forn(_t, T) {
        int n, x, y;
        cin >> n >> x >> y;
        cout << "Case #" << _t + 1 << ": " << solve(n, x , y) << '\n';
    }
    return 0;
}
