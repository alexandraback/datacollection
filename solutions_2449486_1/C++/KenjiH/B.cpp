#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  

int n, m;
int h[128][128];
int g[128][128];

string solve() {
    cin >> n >> m;
    REP (i, n) REP (j, m) cin >> h[i][j];
    REP (i, n) REP (j, m) g[i][j] = 100;

    // horizontal cut
    REP (i, n) {
        int x = 0;
        REP (j, m)
            x = max(x, h[i][j]);
        REP (j, m)
            g[i][j] = min(g[i][j], x);
    }

    // vertical cut
    REP (i, m) {
        int x = 0;
        REP (j, n)
            x = max(x, h[j][i]);
        REP (j, n)
            g[j][i] = min(g[j][i], x);
    }

    REP (i, n) REP (j, m) if (h[i][j] != g[i][j]) return "NO";

    return "YES";
}

int main() {
    int T;
    cin >> T;
    
    REP (i, T) {
        string ret = solve();
        printf("Case #%d: %s\n", i+1, ret.c_str());
    }

    return 0;
}
