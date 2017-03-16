#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

const int MX = 22;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

char c[MX][MX];
int res[MX][MX][MX * MX];
int vis[MX][MX], n, m;

void dfs(int x, int y) {
    vis[x][y] = 1;
    REP (i, 4) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || b < 0 || a >= n || b >= m || vis[a][b] || c[a][b]) {
            continue;
        }
        dfs(a, b);
    }
}

int test() {
    int K; scanf("%d%d%d", &n, &m, &K);
    if (res[n][m][K] != -1) {
        return res[n][m][K];
    }
    int N = n * m;
    for (int i = 1; i <= N; ++i) {
        res[n][m][i] = N;
    }
    for (int mask = 1; mask < (1 << N); ++mask) {
        memset(c, 0, sizeof c);
        memset(vis, 0, sizeof vis);
        REP (i, n) {
            REP (j, m) {
                if (mask & (1 << (i * m + j))) {
                    c[i][j] = 1;
                }
            }
        }
        REP (i, n) {
            REP (j, m) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (!c[i][j] && !vis[i][j]) {
                        dfs(i, j);
                    }
                }
            }
        }
        int cnt = 0;
        REP (i, n) {
            REP (j, m) {
                if (!vis[i][j]) {
                    ++cnt;
                }
            }
        }
        res[n][m][cnt] = min(res[n][m][cnt], __builtin_popcount(mask));
    }
    for (int i = N - 1; i > 0; --i) {
        res[n][m][i] = min(res[n][m][i], res[n][m][i + 1]);
    }
    return res[n][m][K];
}
    
int main(void) {
    int T; scanf("%d", &T);
    memset(res, -1, sizeof res);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %d\n", t, test());
    }
    return 0;
}
