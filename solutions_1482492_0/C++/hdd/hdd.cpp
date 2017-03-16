#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn 2010
#define eps 1e-8
using namespace std;

double ttime[maxn],ddis[maxn],acc;

void solve(int icas)
{
    int N,A,i,j;
    double ldis,cp,v,ans,temp,p;
    scanf("%lf%d%d",&ldis,&N,&A);
    for(i=0; i<N; ++i) scanf("%lf%lf",&ttime[i],&ddis[i]);
    printf("Case #%d:\n",icas);
    for(i=0; i<A; ++i)
    {
        scanf("%lf",&acc);
        if(ddis[0]>ldis) ans=sqrt(2.0*ldis/acc);
        else
        {
            v=(double)((ddis[1]-ddis[0])/(ttime[1]-ttime[0]));
            temp=(ldis-ddis[0]) ;
            ans=sqrt(2.0*ldis/acc);
            if(ans<=temp) ans=temp;
        }
        printf("%lf\n",ans);
    }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int cas,icas=0;
    scanf("%d",&cas);
    for(icas=1; icas<=cas; ++icas)
    {
        solve(icas);
    }
    return 0;
}
