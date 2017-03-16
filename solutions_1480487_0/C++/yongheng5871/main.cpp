#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int Maxn=210;
int n;
int eps(double x,double y)
{
    if(fabs(x-y)<1e-9)return 0;
    return x<y?-1:1;
}
struct P
{
    double v;
    int id;
    bool operator <(const P &a)const
    {
        return eps(v,a.v)<0;
    }
}p[Maxn];
double ans[Maxn],ans2[Maxn];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%d",&n);
        double sum=0,Sum=0;
        for(int i=0;i<n;++i)
        {
            scanf("%lf",&p[i].v);
            p[i].id=i;
            sum+=p[i].v;
        }
        Sum=sum;
        sort(p,p+n);
        p[n].v=1e9;
        for(int i=0;i<=n;++i)ans[i]=0;
       for(int i=0;i<n;++i)
       {
            if(eps(sum,(i+1)*(p[i+1].v-p[i].v))>0)
            {
                ans[i]=(p[i+1].v-p[i].v);
                sum-=ans[i]*(i+1);
            }
            else
            {
                ans[i]=sum/(i+1);
                break;
            }
       }
       for(int i=n-1;i>=0;--i)
       {
           ans[i]+=ans[i+1];
       }
       for(int i=0;i<n;++i)
       {
           int id=p[i].id;
           ans2[id]=ans[i];
       }
        printf("Case #%d:",cas);
        for(int i=0;i<n;++i)
            printf(" %.6f",ans2[i]/Sum*100);
        printf("\n");
    }
    return 0;
}
