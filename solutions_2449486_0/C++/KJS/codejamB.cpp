#include <stdio.h>

const int M = 100;
const int N = 100;

int Map[N][M];

int main()
{   freopen("B-small-attempt0.in", "r", stdin);
    freopen("out_B.txt", "w", stdout);

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
            for (int j = 0; j < m && possible; ++j)
                if (Map[i][j] == 1) {
                    int row_possible = 1;
                    for (int k = 0; k < m && row_possible; ++k)
                        if (Map[i][k] != 1)
                            row_possible = 0;

                    int col_possible = 1;
                    for (int k = 0; k < n && col_possible; ++k)
                        if (Map[k][j] != 1)
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
