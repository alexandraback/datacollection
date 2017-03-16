#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define small
//#define large

int main()
{
#ifdef small
    freopen("B-small.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
#endif

#ifdef large
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
#endif
    
    int t, n, a;
    double dis, ts[5], ns[5], as, time;
    scanf("%d", &t);
    for(int c = 1; c <= t; c ++)
    {
        scanf("%lf%d%d", &dis, &n, &a);
        for(int i = 1; i <= n; i ++)
            scanf("%lf%lf", &ts[i], &ns[i]);
        printf("Case #%d: \n", c);
        for(int i = 1; i <= a; i ++)
        {
            scanf("%lf", &as);
            for(int j = 1; j <= n; j ++)
            {
                if(ns[j] - dis > -1e-6)
                {
                    if(j == 1)
                        time = 0.0;
                    else
                        time = (dis - ns[j - 1]) / ((ns[j] - ns[j - 1]) / (ts[j] - ts[j - 1])) + ts[j - 1];
//                    printf("%f\n", time);
                    break;
                }
            }
            if((2 * dis) / as > pow(time, 2))
            {
                time = sqrt(2 * dis / as);
                printf("%.6f\n", time);
            }
            else
                printf("%.6f\n", time);
        }
    }
//    system("pause");
    return 0;
}
