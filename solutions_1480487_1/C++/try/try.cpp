#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 200
using namespace std;

double s[MAXN+1];
double c;
int n;

int check(int i,double p)
{
    int j;
    double y,z;
    y=s[i]+c*p;
    z=p;
    for(j=1;j<=n;j++)
    {
        if((i!=j)&&(y>s[j]))
        {
            z=z+(y-s[j])/c;
        }
    }
    if(z<=1.0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int k,t,i;
    double l,r,m;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        scanf("%d",&n);
        c=0.0;
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&s[i]);
            c=c+s[i];
        }
        printf("Case #%d:",k+1);
        for(i=1;i<=n;i++)
        {
            l=0.0;
            r=1.0;
            while(l<r-1e-10)
            {
                m=0.5*(l+r);
                if(check(i,m)==1)
                {
                    l=m;
                }
                else
                {
                    r=m;
                }
            }
            printf(" %.6f",100.0*l);
        }
        printf("\n");
    }
    return 0;
}
