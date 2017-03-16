#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXA 100050
#define INF 1000000000
using namespace std;
double p[MAXA];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    int a,b,t,i,j,ca;
    scanf("%d",&t);
    for(ca=1;ca<=t;++ca)
    {
        scanf("%d%d",&a,&b);
        printf("Case #%d: ",ca);
        p[0]=1;
        for(i=1;i<=a;++i)
        {
            scanf("%lf",&p[i]);
            if(i) p[i]*=p[i-1];
        }

        double MIN=double(b+2);
        double sum=1,tmp;
        j=b-a+1;
        for(i=0;i<=a;++i)
        {
            double tmp=p[a-i]*(j)+(1-p[a-i])*(j+b+1);
            MIN=min(tmp,MIN);
            j+=2;
        }
        printf("%.6lf\n",MIN);
    }
    return 0;
}
