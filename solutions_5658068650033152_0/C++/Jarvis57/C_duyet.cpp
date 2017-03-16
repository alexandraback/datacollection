#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
using namespace std;

#define TWO(x) (1<<(x))
#define CONTAIN(S,x) (S & TWO(x))
;

int board[22][22];
int f[22][22][444];
bool visited[22][22];
int first, last;
int qu[22], qv[22];
int m, n;

const int di[] = {-1,1,0,0};
const int dj[] = {0,0,-1,1};

void bfs(int u, int v) {
    first = last = 1;
    qu[1] = u; qv[1] = v;
    visited[u][v] = true;
    while (first <= last) {
        u = qu[first], v = qv[first]; ++first;
        REP(dir,4) {
            int uu = u + di[dir], vv = v + dj[dir];
            if (uu > 0 && uu <= m && vv > 0 && vv <= n) {
                if (board[uu][vv] == 0 && !visited[uu][vv]) {
                    visited[uu][vv] = true;
                    ++last;
                    qu[last] = uu;
                    qv[last] = vv;
                }
            }
        }
    }
}

int main() {
    ios :: sync_with_stdio(false);
    FOR(m,1,20) FOR(n,1,20) if (m*n <= 20) {
        ::m = m; ::n = n;
        memset(f[m][n], -1, sizeof f[m][n]);
        REP(mask,TWO(m*n)) {
            // Generate config
            int cur = 0;
            FOR(i,1,m) FOR(j,1,n) {
                if (CONTAIN(mask,cur)) board[i][j] = 1;
                else board[i][j] = 0;
                cur++;
            }
            // Count captured
            int cnt = m*n;
            FOR(i,1,m) FOR(j,1,n) visited[i][j] = false;
            FOR(i,1,m) FOR(j,1,n)
            if (i == 1 || i == m || j == 1 || j == n)
            if (!board[i][j] && !visited[i][j]) {
                bfs(i, j);
                cnt -= last;
            }
            // Update result
            if (f[m][n][cnt] < 0) f[m][n][cnt] = __builtin_popcount(mask);
            else f[m][n][cnt] = min(f[m][n][cnt], __builtin_popcount(mask));
        }

        cerr << m << ' ' << n << endl;
        FOR(i,0,m*n) {
            cout << m << ' ' << n << ' ' << i << ' ' << f[m][n][i] << endl;
        }
    }
    return 0;
}
