#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define N 100010
double p[N];
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=0;cas<t;cas++)
    {
        int a,b;

        scanf("%d%d",&a,&b);
        double sp=1,ex=a+b+2;
        for(int i=0;i<a;i++)
        {
            scanf("%lf",&p[i]);
            sp*=p[i];
            ex=min(ex,(double)(a-i-1)+b-i+(1.0-sp)*(b+1));
            //printf("Case #%d: %.6lf\n",cas+1,ex);
        }
        ex=min(ex,1.0+b+1);
        printf("Case #%d: %.6lf\n",cas+1,ex);
    }
    return 0;
}
