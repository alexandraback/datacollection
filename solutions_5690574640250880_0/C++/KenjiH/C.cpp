#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

int r, c, m;
int bd[5][5];
int vis[5][5];
const int dx[] = {-1,-1,-1,0,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,0,1,-1,0,1};

bool isZero(int x, int y) {
    REP (k, 9) {
        int xt = x + dx[k];
        int yt = y + dy[k];
        if (xt < 0 || xt >= r) continue;
        if (yt < 0 || yt >= c) continue;
        if (!bd[xt][yt])
            return false;
    }
    return true;
}


void dfs(int x, int y) {
    vis[x][y] = 1;

    if (!isZero(x, y))
        return;

    REP (k, 9) {
        int xt = x + dx[k];
        int yt = y + dy[k];

        if (xt < 0 || xt >= r) continue;
        if (yt < 0 || yt >= c) continue;
        if (!vis[xt][yt]) dfs(xt, yt);
    }
}

bool check() {
    REP (i, r) REP (j, c) if (bd[i][j] != vis[i][j]) return false;
    return true;
}

void disp(int x, int y) {
    REP (i, r) {
        REP (j, c) {
            if (i == x && j == y)
                cout << "c";
            else if (bd[i][j])
                cout << ".";
            else
                cout << "*";
        }
        cout << endl;
    }
}

void solve() {
    cin >> r >> c >> m;
    m = r * c - m;   // m is # of empty cells

    if (m == 1) {
        memset(bd, 0, sizeof(bd));
        disp(0, 0);
        return;
    }

    REP (k, 1<<r*c) {
        if (__builtin_popcountll(k) != m)
            continue;

        memset(bd, 0, sizeof(bd));
        REP (i, r) REP (j, c) if (k & 1<<(i*c+j)) bd[i][j] = 1;
        
        int x = -1, y = -1;
        REP (i, r) REP (j, c) {
            if (isZero(i, j)) {
                x = i;
                y = j;
                break;
            }
        }

        if (x == -1 || y == -1) continue;
        
        memset(vis, 0, sizeof(vis));
        dfs(x, y);

        if (check()) {
            disp(x, y);
            return;
        }

    }

    cout << "Impossible" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int T;
    cin >> T;

    REP (i, T) {
        cerr << "Solving Case #" << (i+1) << "..." << endl;
        cout << "Case #" << (i+1) << ":" << endl;
        solve();
    }

    return 0;
}
