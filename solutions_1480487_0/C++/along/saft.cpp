/*
 * =====================================================================================
 *
 *       Filename:  saft.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/5/6 0:00:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int main()
{
    int n;
    int c,mark[220];
    double ans[220];
    scanf("%d",&n);
    int i,j,k;
    int min1,min2;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&c);
        int num = 0;
        for(j=0;j<c;j++)
        {
            scanf("%d",&mark[j]);
            num+=mark[j];
        }
        for(j=0;j<c;j++)
        {
            ans[j] = (2.0*num/c-mark[j])/num;
        }
        double t=2*num;
        int cnt = c;
        for(j=0;j<c;j++)
        {
            if(ans[j]<-0.000000000000001)
            {
                t -= mark[j];
                cnt --;
                ans[j]=0.0000000001;
            }
        }
        double p;
        for(j=0;j<c&&cnt!=c;j++)
        {
            p = ans[j] - 0.0000000001;
            if(p>0.0000000001)
            {
                ans[j] = (t/cnt - mark[j])/num;
            }
        }

        printf("Case #%d:",i);
        for(j=0;j<c;j++)
        {
            printf(" %.5f",ans[j]*100);
        }
        printf("\n");
    }
    return 1;
}
