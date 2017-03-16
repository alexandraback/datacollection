#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
double s[1000000];
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int cas,n,m;
    scanf("%d",&cas);
    for (int i=0; i<cas; i++)
    {
        double may=1.0;
        double tmp;
        scanf("%d%d",&n,&m);
        for(int j=0; j<n; j++)
        {
            scanf("%lf",&tmp);
            may *= tmp;
            s[j] = 1-may;
        }
        double ans=m+2;
        for(int j=0; j<n; j++)
        {
            double tmp=(j*2+m-n+1)*(1-s[n-j-1])+(j*2+m-n+1+m+1)*s[n-j-1];
            if (ans>tmp) ans=tmp;
        }
        printf("Case #%d: %.6lf\n",i+1,ans);
    }
    return 0;
}
