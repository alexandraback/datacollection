#include <stdio.h>

void update(double *ans, double t)
{
    if(*ans>t) *ans=t;
}

int main()
{
    int T;
    int cnt=0;
    for(scanf("%d", &T); T; T--,cnt++)
    {
        int A, B;
        int i;
        static double pcorr[110000];
        static double mistake[110000];
        double ans;
        scanf("%d%d", &A, &B);
        for(i=0; i<A; i++)
        {
            scanf("%lf", pcorr+i);
            if(i) mistake[i]=1-(1-mistake[i-1])*pcorr[i];
            else mistake[i]=1-pcorr[i];
        }
        ans=2+B;
        update(&ans, (1-mistake[A-1])*(B-A+1)+(mistake[A-1])*(B-A+1+B+1));
        for(i=2; i<=A; i++)
        {
            update(&ans, (1-mistake[A-i])*(i-1+B-A+i-1+1)+(mistake[A-i])*(i-1+B-A+i-1+1+B+1));
        }
        printf("Case #%d: %.6lf\n", cnt+1, ans);
    }
    return 0;
}
