#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI acos(-1.0)

using namespace std;

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int cas,t=1;
    long long ans;
    double r,tot;

    scanf("%d",&cas);
    while (cas--)
    {
        ans=0;
        scanf("%lf%lf",&r,&tot);
        if (4*r*r-4*r+1+8*tot>=0)
        {
            ans=(long long)((sqrt(4*r*r-4*r+1+8*tot)-(2*r-1))/4.0);
            if (ans<0)
                ans=0;
        }
        else
            ans=0;
        double tmp_tot=2*ans*ans+(2*r-1)*ans;
        while(tmp_tot>tot&&ans>0)
        {
            ans--;
            tmp_tot=2*ans*ans+(2*r-1)*ans;
        }
        printf("Case #%d: %I64d\n",t++,ans);
    }
    return 0;
}
