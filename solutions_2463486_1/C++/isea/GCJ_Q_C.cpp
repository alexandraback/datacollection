// New Ryan
// Create @ 20:12 04-13 2013
// Comment - 

#include <cmath>
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
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<double, double> pdd;

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

const int64 all[39] = 
{   
    1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 
    4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 
    400080004, 404090404, 10000200001LL, 10221412201LL, 12102420121LL, 12345654321LL, 40000800004LL, 
    1000002000001LL, 1002003002001LL, 1004006004001LL, 1020304030201LL, 1022325232201LL, 1024348434201LL, 
    1210024200121LL, 1212225222121LL, 1214428244121LL, 1232346432321LL, 1234567654321LL, 4000008000004LL, 4004009004004LL
};


int main() {
    freopen ("C.out", "w", stdout);
    
    repcase {
        int64 a, b;
        scanf ("%I64d%I64d", &a, &b);
        int ans = 0;
        rep (i, 39) {
            if (all[i] >= a && all[i] <= b) {
                ++ans;
            }
        }
        printf ("Case #%d: %d\n", Case++, ans);
    }
    return 0;
}

