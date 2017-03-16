#include <stdio.h>

double p[100010];
int main()
{
    int test, A, B;
    scanf("%d",&test);
    for (int cas=1;cas<=test;cas++)
    {
        scanf("%d%d",&A,&B);
        for (int i=0;i<A;i++)
            scanf("%lf",&p[i]);
        
        double right = 1;
        double ans = 1 + B + 1;
        for (int i=0;i<=A;i++)
        {
            double cost = right * (A-i + B-i + 1) + (1-right) * (A-i + B-i+1 + B+1);
            if (cost < ans)
                ans = cost;
            if (i < A) right *= p[i];
        }
        printf("Case #%d: %.7f\n",cas, ans);
    }
}
