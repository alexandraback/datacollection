#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

const int N=2000020;
bool yc[N];
int getdignum(int x)
{
    int ans=0;
    do
    {
        ++ans;
        x/=10;
    }while(x);
    return ans;
}
int dp[10]={0,1,10,100,1000,10000,100000,1000000};

int next(int x,int n)
{
    return x/10+x%10*dp[n];
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);

    int tt,kk=1;
    for(scanf("%d",&tt);tt--;)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for(int i=a;i<=b;++i)
            yc[i]=false;

        int q[10],end;
        int dignum=getdignum(a);
        int ans=0;
        for(int i=a;i<=b;++i)
        {
            if(yc[i])
                continue;
            yc[i]=true;
            end=0;
            q[++end]=i;
            int x=i;
            for(int j=1;j<dignum;++j)
            {
                x=next(x,dignum);
                if(x>=a && x<=b &&!yc[x])
                    q[++end]=x,yc[x]=true;
            }
            ans+=(end-1)*end/2;
        }
        printf("Case #%d: %d\n",kk++,ans);
    }
    return 0;
}
