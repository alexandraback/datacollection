#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 222
#define EPS 1e-8
int T;
int n;
int a[MAX_N];
int f[MAX_N];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int sum = 0;
        memset(f, 0, sizeof(f));
        scanf("%d", &n);
        for(int j = 0; j < n; ++j)
        {
            scanf("%d", &a[j]);
            sum += a[j];
        }
        bool flag = 1;
        int count = n;
        int sumb = sum;
        while(flag)
        {
            flag = 0;
            double avg =  1.0 * (sumb + sum) / count;
            for(int j = 0; j < n; ++j)
            {
                if(!f[j] && a[j] >= avg)
                {
                    sum -= a[j];
                    f[j] = 1;
                    count--;
                    flag = 1;
                }
            }
            if(!sum) break;
        }
        printf("Case #%d:", i + 1);
        for(int j = 0; j < n; ++j)
        {
            if(f[j]) printf(" %lf", 0.000000);
            else if(!sum) printf(" %lf", 100.0 / count);
            else printf(" %lf", 100.0 / count + 100.0 * sum / (count * sumb) - 100.0 * a[j] / sumb);
        }
        printf("\n");
    }
    return 0;
}
