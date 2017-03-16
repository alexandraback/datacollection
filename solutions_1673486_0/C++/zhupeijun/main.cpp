#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MM 100010

double p[MM],f[MM];

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt","w",stdout);
    int u,zongcishu,a,b,i;
    double tmp1,tmp2,tmp3,res;
    scanf("%d",&zongcishu);
    for(u=1;u<=zongcishu;++u)
    {
        scanf("%d%d",&a,&b);
        f[0] = 1;
        for(i=1;i<=a;++i)
        {
            scanf("%lf",&p[i]);
            f[i]=f[i-1]*p[i];
        }
        tmp1=b+2;
        tmp2=(2-f[a])*b-a+2-f[a];
        res = min(tmp1,tmp2);
        for(i=1;i<=a;++i)
        {
            tmp3=f[a-i]*(2*i+b-a+1)+(1-f[a-i])*(2*i+2*b-a+2);
            res = min(res,tmp3);
        }
        printf("Case #%d: %lf\n",u,res);
    }
}
