#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int Maxn=(int)1e5+10;
double p[Maxn];
int a,b;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%d%d",&a,&b);
        p[0]=1;
        for(int i=1;i<=a;++i)
        {
            scanf("%lf",&p[i]);
        }
        double tmp=1;
        double ans=b+2;
        for(int i=0;i<=a;++i)
        {
            tmp*=p[i];
            ans=min(ans,((a-i)*2+b-a+1)*tmp+(1-tmp)*((b+1)+(a-i)*2+b-a+1));
        }
        printf("Case #%d: %.6f\n",cas,ans);
    }
    return 0;
}
