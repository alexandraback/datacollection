#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <fstream>

const int maxn=200;
using namespace std;
int n;
int check(double x,double y)
{
    if(fabs(x-y)<1e-9)return 0;
    return x<y?-1:1;
}
struct Point
{
    double v;
    int id;
    bool operator <(const Point &a)const
    {
        return check(v,a.v)<0;
    }
}p[maxn+10];

double ans[maxn+10],ans2[maxn+10];
double sum,S;

double solve()
{
    sort(p,p+n);
    p[n].v=1000000000;
    for(int i=0;i<=n;++i)ans[i]=0;
    for(int i=0;i<n;++i)
    {
        if(check(sum,(i+1)*(p[i+1].v-p[i].v))>0)
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
}

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;++t)
    {
        scanf("%d",&n);
        sum=0;
        for(int i=0;i<n;++i)
        {
            scanf("%lf",&p[i].v);
            p[i].id=i;
            sum+=p[i].v;
        }
        S=sum;
        solve();
        printf("Case #%d:",t);
        for(int i=0;i<n;++i) printf(" %.6f",ans2[i]/S*100);
        printf("\n");
    }
    return 0;
}
