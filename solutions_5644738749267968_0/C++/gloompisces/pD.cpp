#include <stdio.h>
#include <stdlib.h>

int comp(const void *x, const void *y)
{
    return (*(int*)x) - (*(int*)y);
}

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    
    int x[1005], y[1005], N;
    double tmp;
    
    int cases;
    scanf("%d", &cases);
    for (int case_index = 1; case_index <= cases; case_index++)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%lf", &tmp);
            x[i] = (int)(tmp * 100000 + 0.5);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%lf", &tmp);
            y[i] = (int)(tmp * 100000 + 0.5);
        }
        
        qsort(x, N, sizeof(int), comp);
        qsort(y, N, sizeof(int), comp);
        
        int ans1 = 0, ans2 = 0;
        int nx = 0, ny = 0;
        for (;;)
        {
            if (nx >= N) break;
            if (x[nx] > y[ny])
            {
                ans1++;
                nx++;
                ny++;
            }
            else
            {
                nx++;
            }
        }
        
        nx = 0;
        ny = 0;
        for (;;)
        {
            if (ny >= N) break;
            if (x[nx] < y[ny])
            {
                ans2++;
                nx++;
                ny++;
            }
            else
            {
                ny++;
            }
        }
        
        printf("Case #%d: %d %d\n", case_index, ans1, N - ans2);
    }
    
    
    return 0;
}
