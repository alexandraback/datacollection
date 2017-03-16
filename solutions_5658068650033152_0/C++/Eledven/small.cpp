#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int INF = 1 << 28;
const int dx[4] = {1, 0, -1,  0};
const int dy[4] = {0, 1,  0, -1};


int n, m;
int a[22][22];
int u[22][22];

void go(int x, int y) {
    if (a[x][y] == 1) {
        return;
    }
    u[x][y] = 1;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !u[nx][ny]) {
            go(nx, ny);
        }
    }
}

int main() {
    int nt;
    assert(scanf("%d", &nt) == 1);
    for (int tt = 1; tt <= nt; tt++) {
        int k;
        assert(scanf("%d%d%d", &n, &m, &k) == 3);
        int res = INF;
        eprintf("test %d\n", tt);
        for (int mask = 0; mask < (1 << (n * m)); mask++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    u[i][j] = 0;
                    a[i][j] = (mask >> (i * m + j)) & 1;  
                }
            }
            for (int i = 0; i < n; i++) {
                go(i, 0);
                go(i, m - 1);
            }
            for (int j = 0; j < m; j++) {
                go(0, j);
                go(n - 1, j);
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cnt += u[i][j] == 0;
                }
            }
            if (cnt >= k) {
                res = min(res, __builtin_popcount(mask));
            }
        }
        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
