// New Ryan
// Create @ 19:26 04-13 2013
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

const int maxn = 100 + 10;

int a[maxn][maxn], n, m;
bool vis[maxn][maxn];

bool check() {
    while (true) {
        int mina = 1000, x, y;
        rep (i, n) rep (j, m) {
            if (!vis[i][j] && a[i][j] < mina) {
                x = i, y = j;
                mina = a[i][j];
            }
        }
        if (mina == 1000) {
            break ;
        }
        // try H
        bool can = true;
        rep (i, n) if (!vis[i][y] && a[i][y] > mina) {
            can = false;   
        }
        if (can) {
            rep (i, n) vis[i][y] = true;
            continue ; 
        }
        // try V
        can = true;
        rep (j, m) if (!vis[x][j] && a[x][j] > mina) {
            can = false;   
        }
        if (can) {
            rep (j, m) vis[x][j] = true;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    freopen ("B.out", "w", stdout);
    
    repcase {
        scanf ("%d%d", &n, &m);
        rep (i, n) rep (j, m) {
            scanf ("%d", &a[i][j]);
            vis[i][j] = false;
        }
        printf ("Case #%d: %s\n", Case++, check()? "YES" : "NO");
    }
    return 0;
}

