#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int q,t,i;
    double c,f,x,s,v,m,l;
    scanf("%d",&t);
    for(q=0;q<t;q++)
    {
        scanf("%lf %lf %lf",&c,&f,&x);
        s=0.0;
        v=2.0;
        m=x/v;
        l=x/c;
        for(i=1;i<=l;i++)
        {
            s=s+c/v;
            v=v+f;
            if(m>s+x/v)
            {
                m=s+x/v;
            }
            else
            {
                break;
            }
        }
        printf("Case #%d: %.7f\n",q+1,m);
    }
    return 0;
}
