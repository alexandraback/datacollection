#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define eps 1e-8
double s[3000],t[3000];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    int N,A,Cas,cas;
    double D;
    scanf("%d",&Cas);
    for (int cas=0; cas<Cas; cas++)
    {
        scanf("%lf%d%d",&D,&N,&A);
        for(int i=0; i<N; i++)
            scanf("%lf%lf",&s[i],&t[i]);
        printf("Case #%d:\n",cas+1);
        for(int i=0; i<A; i++)
        {
            double tmp,ans;
            scanf("%lf",&tmp);
            if(t[0]>D)
            {
                ans=sqrt(2.0*D/tmp);
                printf("%lf\n",ans);
            }
            else
            {
                double speed=(double)((t[1]-t[0])/(s[1]-s[0]));
                ans=sqrt(2.0*D/tmp);
                if(ans>(D-t[0])/speed)
                    printf("%lf\n",ans);
                else
                    printf("%lf\n",(D-t[0])/speed);
            }
        }
    }
    return 0;
}
