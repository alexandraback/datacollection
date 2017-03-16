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

char vis[1000][1000];
int px[1000][1000];
int py[1000][1000];
int jump[1000][1000];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string dir = "NESW";

void solve() {
    int x, y;
    cin >> x >> y;
    x += 500;
    y += 500;

    REP (i, 1000) REP (j, 1000) vis[i][j] = '?';

    queue<pair<int, int> > Q;
    Q.push(make_pair(500, 500));
    jump[500][500] = 0;
    vis[500][500] = 'X';

    while (!Q.empty()) {
        int x1 = Q.front().first;
        int y1 = Q.front().second;
        
        Q.pop();
        if (vis[x][y] != '?')
            break;
        
        int jp = jump[x1][y1] + 1;
        REP (i, 4) {
            int x2 = x1 + dx[i] * jp;
            int y2 = y1 + dy[i] * jp;

            if (vis[x2][y2] == '?') {
                jump[x2][y2] = jp;
                vis[x2][y2] = dir[i];
                px[x2][y2] = x1;
                py[x2][y2] = y1;
                Q.push(make_pair(x2, y2));
            }
        }
    }

    string ret;
    while (vis[x][y] != 'X') {
        string tmp;
        tmp += vis[x][y];
        ret = tmp + ret;
        int nx = px[x][y];
        int ny = py[x][y];
        x = nx;
        y = ny;
    }

    cout << ret << endl;

}

int main() {
    int T;
    cin >> T;
    REP (i, T) {
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
