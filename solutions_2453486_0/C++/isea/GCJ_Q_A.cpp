// New Ryan
// Create @ 19:48 04-13 2013
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
    
bool checkFull(string b[]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (b[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

bool check(string b[], char ch) {
    for (int i = 0; i < 4; ++i) {
        bool ok = true;
        for (int j = 0; j < 4; ++j) {
            if (b[i][j] != ch && b[i][j] != 'T') {
                ok = false;
            }
        }
        if (ok) return true;
    }
    for (int i = 0; i < 4; ++i) {
        bool ok = true;
        for (int j = 0; j < 4; ++j) {
            if (b[j][i] != ch && b[j][i] != 'T') {
                ok = false;
            }
        }
        if (ok) return true;
    }
    bool ok = true;
    for (int j = 0; j < 4; ++j) {
        if (b[j][j] != ch && b[j][j] != 'T') {
            ok = false;
        }
    }
    if (ok) return true;
    ok = true;
    for (int j = 0; j < 4; ++j) {
        if (b[j][3 - j] != ch && b[j][3 - j] != 'T') {
            ok = false;
        }
    }
    return ok;
}

int main() {
    freopen ("A.out", "w", stdout);
    
    repcase {
        string board[4];
        for (int i = 0; i < 4; ++i) {
            cin >> board[i];
        }
        printf ("Case #%d: ", Case++);
        if (check(board, 'X')) {
            puts ("X won");
        } else if (check(board, 'O')) {
            puts ("O won");
        } else if (checkFull(board)) {
            puts ("Draw");
        } else {
            puts ("Game has not completed");
        }
    }
    return 0;
}
