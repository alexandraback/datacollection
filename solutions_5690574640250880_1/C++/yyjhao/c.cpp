#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

short dp[2500][50][50];
int m, r, c;

pair<int, pair<int, int> > p[2500][51][51];

bool isPossible(int left, int cc, int len) {
    if (left < 0) return false;
    if (cc > c) return false;
    if (dp[left][cc][len] != -1) return dp[left][cc][len];
    if (len == 1 && r != 1) return dp[left][cc][len] = false;
    if (left == 0){
        if (cc > 1 || c == 1) {
            return dp[left][cc][len] = true;
        } else {
            return dp[left][cc][len] = false;
        }
    }
    if (cc == 1) {
        if (isPossible(left - len, cc + 1, len)) {
            p[left][cc][len] = make_pair(left - len, make_pair(cc + 1, len));
            return dp[left][cc][len] = true;
        }
        return dp[left][cc][len] = false;
    }
    for (int i = min(left, len); i >= 1; i--) {
        if (isPossible(left - i, cc + 1, i)) {
            p[left][cc][len] = make_pair(left - i, make_pair(cc + 1, i));
            return dp[left][cc][len] = true;
        }
    }
    return dp[left][c][len] = false;
}

int main() {
    int t;
    scanf("%d", &t);
    char grid[100][100];
    for(int ca = 0; ca < t; ca++) {
        int left;
        scanf("%d %d %d", &r, &c, &m);
        bool possible = true;
        left = r * c - m;
        int w, h, add;
        int sl = max(r, c), ll = min(r, c);
        printf("Case #%d:\n", ca + 1);
        if (left == 1) {
            possible = true;
        } else {
            for (int i = 0; i <= left; i++)for(int j = 0; j <= c; j++)for(int k = 0; k <= r; k++) {
                dp[i][j][k] = -1;
            }
            possible = isPossible(left, 0, r);
        }

        if (!possible) {
            // printf("%d %d %d\n", r, c, m);
            printf("Impossible\n");
        } else {
            // continue;
            for (int i = 0; i < r; i++)for (int j = 0; j < c; j++) {
                grid[i][j] = '*';
            }
            if (left == 1) {

            } else {
                pair<int, pair<int, int> > cur = p[left][0][r];
                while (1) {
                    int len = cur.second.second;
                    int cc = cur.second.first - 1;
                    for (int i = 0; i < len; i++) {
                        grid[i][cc] = '.';
                    }
                    if (cur.first == 0) {
                        break;
                    }
                    cur = p[cur.first][cur.second.first][cur.second.second];
                }
            }
            grid[0][0] = 'c';
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    printf("%c", grid[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}