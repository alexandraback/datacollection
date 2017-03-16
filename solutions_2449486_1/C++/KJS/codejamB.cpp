#include <stdio.h>

const int M = 100;
const int N = 100;

int Map[N][M];

int main()
{   freopen("B-large.in", "r", stdin);
    freopen("out_B_large.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d", &Map[i][j]);

        int possible = 1;
        for (int i = 0; i < n && possible; ++i)
            for (int j = 0; j < m && possible; ++j) {
                    int row_possible = 1;
                    for (int k = 0; k < m && row_possible; ++k)
                        if (Map[i][k] > Map[i][j])
                            row_possible = 0;

                    int col_possible = 1;
                    for (int k = 0; k < n && col_possible; ++k)
                        if (Map[k][j] > Map[i][j])
                            col_possible = 0;

                    if (!row_possible && !col_possible)
                        possible = 0;

            }

        printf("Case #%d: ", t);
        if (possible)   puts("YES");
        else            puts("NO");
    }
    return 0;
}
