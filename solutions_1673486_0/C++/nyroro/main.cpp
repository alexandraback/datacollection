#include <iostream>
#include<cstdio>
using namespace std;
#define MAXN 99999+100
double p[MAXN],pre[MAXN];
int main()
{
//    freopen("in","r",stdin);
//    freopen("out","w",stdout);
    int t;
    scanf("%d",&t);

    int ti=1;
    while(t--)
    {
        double correct=1.0;

        int a,b;

        scanf("%d%d",&a,&b);

        pre[0]=1.0;
        for(int i=0;i<a;i++)
        {
            scanf("%lf",&p[i]);
            correct*=p[i];
            pre[i+1]=correct;
        }

        double res=correct*(b-a+1)+(1.0-correct)*(b-a+1+b+1);

        res=min(2.0+b,res);

        double q=1.0;

        for(int i=a;i>=0;i--)
        {
            int back=a-i;
            int type=b-i;
            int enter=1;
            int retype=b+1;
            q=(1.0-pre[i])*retype+back+type+enter;
            res=min(res,q);
        }

        printf("Case #%d: %.6lf\n",ti++,res);

    }
    return 0;
}
