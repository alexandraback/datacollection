#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))

int n, m, k;
int board[20][20];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int chk() {
/*    fill(board[0], board[20], 0);
    board[0][1] = board[0][2] = 1;
    board[1][0] = board[1][3] = 1;
    board[2][1] = board[2][2] = 1;
    */
    int c[20] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0 && i < n - 1 && j > 0 && j < m - 1) {
                continue;
            }
            int idx = i * m + j;
            if (c[idx] || board[i][j]) {
                continue;
            }
            queue<pair<int, int> > q;
            q.push(make_pair(i, j));
            c[idx] = 1;
            while (!q.empty()) {
                pair<int, int> t = q.front(); q.pop();
                for (int p = 0; p < 4; ++p) {
                    int y = dy[p] + t.first;
                    int x = dx[p] + t.second;
                    if (y < 0 || y >= n || x < 0 || x >= m || c[y * m + x] || board[y][x]) {
                        continue;
                    }
                    c[y * m + x] = 1;
                    q.push(make_pair(y, x));
                }
            }
        }
    }
    int cnt = 0;
/*    printf("\n");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (c[i * m + j] == 0) {
                cnt++;
            }
        }
    }
    return cnt >= k;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case #%d: ", cs);
        scanf("%d %d %d", &n, &m, &k);

        int ans = k;
        for (int i = 1; i < (1 << (n * m)); ++i) {
            int cnt = 0;
            int t = 0;
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < m; ++c) {
                    board[r][c] = (i & (1 << cnt)) ? 1 : 0;
                    t += board[r][c];
                    cnt++;
                }
            }
            if (t >= ans) {
                continue;
            }
            if (chk()) {
               ans = t; 
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


