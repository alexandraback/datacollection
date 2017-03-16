#include <stdlib.h>
#include <stdio.h>

#define MAX_N 200

int main()
{
    int t, n;
    int score[MAX_N];
    double sum;
    double ave, ptg;
    double total;
    int weak;
    double votes;
    int i, k;
    
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    
    scanf("%d", &t);
    for (k = 0; k < t; k++)
    {
        scanf("%d", &n);
        sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &score[i]);
            sum += score[i];
        }
        printf("Case #%d:", k + 1);
        ave = 2.0 / n;
        total = 2.0;
        weak = n;
        for (i = 0; i < n; i++)
        {
            ptg = score[i] / sum;
            if (ptg > ave)
            {
                total -= ptg;
                weak--;
            }
        }
        for (i = 0; i < n; i++)
        {
            ptg = score[i] / sum;
            if (ptg > ave)
            {
                votes = 0;
            }
            else
            {
                votes = (total / weak - ptg) * 100;
            }
            printf(" %.6f", votes);
        }
        printf("\n");
    }
    
    freopen("CON", "r", stdin);
    freopen("CON", "r", stdin);
    getchar();
    return 0;
}
