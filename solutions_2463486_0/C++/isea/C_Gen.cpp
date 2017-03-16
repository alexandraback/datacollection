// New Ryan
// Create @ 20:01 04-13 2013
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

bool isP(int64 x) {
    char buf[16];
    sprintf (buf, "%I64d", x);
    int len = strlen(buf);
    for (int i = 0; i < len - 1 - i; ++i) {
        if (buf[i] != buf[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen ("GCJ_Q_C.cpp", "w", stdout);
    int cnt = 0;
    for (int i = 1; i <= 10000000; ++i) {
        if (isP(i)) {
            //printf ("i %d\n", i);
            int64 x = (int64)i * i;
            if (isP(x)) {
                printf ("%I64d, ", x);
                ++cnt;
                //printf ("yes %I64d with %d\n", x, i);
            }
        }
    }
    out(cnt);
    return 0;
}

