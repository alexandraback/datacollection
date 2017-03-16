#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int board[100][100];
int maxrow[100], maxcol[100];

int main() {
    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        int n, m;
        scanf("%d %d", &n, &m);

        memset(maxrow, 0, sizeof maxrow);
        memset(maxcol, 0, sizeof maxcol);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                scanf("%d", &board[i][j]);
                maxrow[i] = max(maxrow[i], board[i][j]);
                maxcol[j] = max(maxcol[j], board[i][j]);
            }

        bool ok = true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] < maxrow[i] && board[i][j] < maxcol[j])
                    ok = false;

        printf("Case #%d: ", z);
        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
