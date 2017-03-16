#include <stdio.h>

int t, b;
long long m;
int edge[50][50];

int main()
{
    freopen("/Users/IohcEjnim/Downloads/B-large.in.txt", "r", stdin);
    freopen("/Users/IohcEjnim/Downloads/result.txt", "w", stdout);
    int tn, i, j;
    long long max;
    scanf("%d", &t);
    
    for (tn = 1; tn <= t; tn++)
    {
        scanf("%d %lld", &b, &m);
        for (i = 1; i <= b; i++)
            for (j = 1; j <= b; j++)
                edge[i][j] = 0;
        for (i = 1; i < b; i++)
            for (j = i+1; j < b; j++)
                edge[i][j] = 1;

        printf("Case #%d: ", tn);
        max = 1;
        for (i = 3; i <= b; i++) max *= 2;
        if (m > max)
        {
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
        if (m == max)
        {
            for (i = 1; i < b; i++)
                edge[i][b] = 1;
            for (i = 1; i <= b; i++)
            {
                for (j = 1; j <= b; j++)
                    printf("%d", edge[i][j]);
                puts("");
            }
            continue;
        }
        
        for (i = 2; i < b; i++)
        {
            edge[i][b] = m%2;
            m /= 2;
        }
        for (i = 1; i <= b; i++)
        {
            for (j = 1; j <= b; j++)
                printf("%d", edge[i][j]);
            puts("");
        }
    }
}