#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    int t, teste;
    int n, m;
    int i, j;
    int mat[110][110];
    int maxx[110];
    int maxy[110];
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%d %d\n", &n, &m);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf("%d", &mat[i][j]);
            }
        }

        for (i = 0; i < n; i++)
        {
            int best = 0;
            for (j = 0; j < m; j++)
            {
                best = max(best, mat[i][j]);
            }
            maxx[i] = best;
        }

        for (j = 0; j < m; j++)
        {
            int best = 0;
            for (i = 0; i < n; i++)
            {
                best = max(best, mat[i][j]);
            }
            maxy[j] = best;
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (mat[i][j] != maxx[i] && mat[i][j] != maxy[j])
                    break;
            }
            if (j < m)
                break;
        }

        if (i < n)
            printf("Case #%d: NO\n", t + 1);
        else
            printf("Case #%d: YES\n", t + 1);
    }
    return 0;
}
