#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=100005;

double p[N];
double c[N];
int a,b;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j;
    scanf("%d",&t);
    int cs=0;
    while(t--)
    {
        scanf("%d%d",&a,&b);
        c[0]=1;
        for(i=1;i<=a;i++)
        {
            scanf("%lf",&p[i]);
            c[i]=c[i-1]*p[i];
        }

    double ans=1e9;
    double x=(b-a+1)+(1-c[a])*(b+1);
    ans=min(ans,x);
    for(i=1;i<=a;i++)
    {
    x=0;
    x=(i+(b+i-a)+1)+(1-c[a-i])*(b+1);
    ans=min(ans,x);
    }
    ans=min(ans,2.0+b);
    printf("Case #%d: %f\n",++cs,ans);
    }
    return 0;
}
