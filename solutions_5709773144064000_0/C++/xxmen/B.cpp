#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, Case = 0;
    double c,f,x,ans;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lf%lf%lf",&c,&f,&x);
        if (x < c)
        {
            printf("Case #%d: %lf\n",++Case,x / 2.0);
            continue;
        }
        double pd, t1, t2;
        pd = 2.0;
        ans = c / pd;
        while (1)
        {
            t1 = (x-c) / pd;
            t2 = x / (pd + f);
            if (t1<t2)
            {
                ans += t1;
                break;
            }
            else
            {
                pd += f;
                ans += c / pd;
            }
        }
        printf("Case #%d: %.7lf\n",++Case,ans);
    }
    return 0;
}