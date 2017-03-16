// Rain Dreamer MODEL
// Create @ 16:59 05-11 2014
// Comment - 

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define all(x) (x).begin(), (x).end()
#define RD(x) freopen (x, "r", stdin)
#define WT(x) freopen (x, "w", stdout)
#define clz(x) memset (x, 0, sizeof(x))
#define cln(x) memset (x, -1, sizeof(x))
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

const int LIM = 40;

int main() {
    WT ("A.out");
    
    int64 a, b;
    repcase {
        printf ("Case #%d: ", Case++);
        scanf ("%I64d/%I64d", &a, &b);
        int64 _g = __gcd(a, b);
        a /= _g, b /= _g;
        int64 base = 2LL;
        int ans = 1;
        while (true) {
            if (base % b == 0 || ans > LIM) {
                break;
            }
            base <<= 1;
            ans += 1;
        }
        if (ans > LIM) {
            puts ("impossible");
            continue ;
        }
        int64 cof = base / b;
        a *= cof;
        base = 1LL;
        while (a >= base) {
            base <<= 1;
            ans -= 1;
        }
        printf ("%d\n", ans + 1);
    }
    return 0;
}

