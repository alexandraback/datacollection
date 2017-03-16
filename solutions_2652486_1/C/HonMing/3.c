#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    int ii,jj,kk;
    int res;
    int mm;
    int end, xw, ow;
    int r, n, m, k;
    int max;
    unsigned int v[20];
    unsigned int factor[20][10];
    unsigned int result[10];

    scanf("%d", &mm);

    for(ii = 1; ii <= mm; ii++)
    {
        scanf("%d%d%d%d", &r, &n, &m, &k);
        printf("Case #1:\n");

        for(jj = 0; jj < r; jj++)
        {
            memset(factor, 0, sizeof(factor));
            memset(result, 0, sizeof(result));
            for(i = 0; i < k; i++)
            {
                scanf("%d", &v[i]);

                if(v[i] > 1)
                {
                    for(j = 2; j <= m; j++)
                    {
                        int temp = v[i];
                        while(temp % j == 0)
                        {
                            factor[i][j]++;
                            temp /= j;
                        }
                    }
                }
            }
    
            for(i = 0; i < k; i++)
            {
                int nc;
                nc = (factor[i][3] - factor[i][6]) + factor[i][5] + factor[i][7];
                for(j = 2; j <= m; j++)
                {
                    if(j == 8 || j == 4 || j == 2)
                    {
                        if(factor[i][2] + nc > n)
                        {
                            result[4] = n - (factor[i][2] + nc);
                        }
                        continue;
                    }
                    if(j == 3)
                    {
                        continue;
                    }
                    if(j == 6)
                    {
                        if(factor[i][3] > factor[i][6])
                        {
                            if(factor[i][3] - factor[i][6] > result[3])
                                result[3] = factor[i][3] - factor[i][6];
                        }

                    }
                    if(j == 5 || j == 7)
                    {
                        if(factor[i][j] > result[j])
                            result[j] = factor[i][j];
                    }
                }
            }
            kk = 0;
            for(j = m ; j >= 2; j--)
            {
                for(i = 0; i < result[j] && kk < n; i++)
                {
                    printf("%d", j);
                    kk++;
                }
            }
            for(i = kk ; i < n; i++)
            {
                printf("2");
            }
            printf("\n");
        }
    }
}
