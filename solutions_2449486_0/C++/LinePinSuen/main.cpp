#include <stdio.h>

int main(void)
{
    int t = 0;
    int pattern[100][100];

    // t: # of cases
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        int m = 0;

        // n*m pattern
        scanf("%d %d", &n, &m);
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                scanf("%d", &pattern[x][y]);
            }
        }

        // determine property of each a(i,j)
        bool pattern_valid = true;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                bool x_valid = true;
                bool y_valid = true;
                for (int xx = 0; xx < n; xx++)
                {
                    x_valid = x_valid && (pattern[xx][y] <= pattern[x][y]);
                }
                for (int yy = 0; yy < m; yy++)
                {
                    y_valid = y_valid && (pattern[x][yy] <= pattern[x][y]);
                }
                pattern_valid = pattern_valid && (x_valid || y_valid);
            }
        }

        // output
        printf("Case #%d: %s\n", i + 1, pattern_valid ? "YES" : "NO");
    }

    return 0;
}
