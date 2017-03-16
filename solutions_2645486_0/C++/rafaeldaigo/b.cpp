#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    int t, teste;
    int e, r, n;
    int i, j, k;
    int value[11000];
    int mat[20][20];
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%d %d %d\n", &e, &r, &n);
        if (r > e)
            r = e;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &value[i]);
        }
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= e; j++)
            {
                mat[i][j] = 0;
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= e; j++)
            {
                for (k = 0; k <= j; k++)
                {
                    int cand = mat[i][j] + k * value[i];
                    if (mat[i + 1][j - k + r] < cand)
                        mat[i + 1][j - k + r] = cand;
                }
            }
            mat[i][0] = 0;
        }
        printf("Case #%d: %d\n", t+1, mat[n][r]);
    }
    return 0;
}
