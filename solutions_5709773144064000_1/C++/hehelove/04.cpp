#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int T,i,j,cas=0;
    double x,f,c;
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&c,&f,&x);
        double t1,t2,sum=0.0,v=2.0;
        while(1)
        {
            //printf("%lf %lf\n",sum,v);
            double tt=c/v;
            t1=x/v;
            t2=x/(v+f)+tt;
            if(t1<=t2)
            {
                sum+=t1;
                break;
            }
            v+=f;
            sum+=tt;
        }
        printf("Case #%d: %.7lf\n",++cas,sum);
    }
    return 0;
}
