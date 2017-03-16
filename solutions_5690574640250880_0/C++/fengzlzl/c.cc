#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n, m, mine;
        scanf("%d%d%d", &n, &m, &mine);
        printf("Case #%d:\n", cas);
        if (mine >= m * n) {
            printf("Impossible\n");
            continue;
        }
        vector<string> board(n, string(m, '.'));
        if (mine + 1 == n * m) {
            board.assign(n, string(m, '*'));
            mine = 0;
        } else if (n == 1 || m == 1) {
            for (int i = 0; i < n && mine > 0; i++)
                for (int j = 0; j < m && mine > 0; j++)
                    board[i][j] = '*', mine--;
        } else {
            for (int i = 0; i < n - 2 && mine > 0; i++)
                for (int j = 0; j < m - 2 && mine > 0; j++)
                    board[i][j] = '*', mine--;
            int reserve = 2;
            if (mine & 1) {
                if (n == 2 || m == 2) {
                    printf("Impossible\n");
                    continue;
                }
                reserve = 3;
                board[n - 3][m - 3] = '.';
                mine++;
            }
            for (int i = 0; i < n - reserve && mine > 0; i++)
                board[i][m - 1] = board[i][m - 2] = '*', mine -= 2;

            for (int j = 0; j < m - reserve && mine >= 2; j++)
                board[n - 1][j] = board[n - 2][j] = '*', mine -= 2;
        }
        if (mine > 0) {
            printf("Impossible\n");
            continue;
        }
        board[n - 1][m - 1] = 'c';
        for (int i = 0; i <board.size(); i++)
            printf("%s\n", board[i].c_str());
    }
    return 0;
}
