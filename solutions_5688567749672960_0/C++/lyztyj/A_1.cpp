#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
LL tm[16]={1};
LL f(LL x)
{
    if(x<10)return x;
    if(x%10==0)return f(x-1)+1;
    LL p=x,ans=0;
    int u[16],q[16];
    u[0]=0;
    while(p)
    {
        u[0]++;
        u[u[0]]=p%10;
        p/=10;
        q[u[0]]=0;
    }
    q[1]=q[u[0]]=1;
    ans+=u[1]+u[u[0]]-2;
    p=1;
    ans=0;
    for(int i=1;i<=(u[0]+1)/2;i++)
    {
        ans+=(u[i]-q[i])*tm[i-1];
        p*=10;
    }
    int flag=0;
    for(int i=(u[0]+1)/2+1;i<=u[0];i++)
    {
        if(u[i]>q[i])
        {
            ans+=(u[i]-q[i])*tm[u[0]-i];
            flag=1;
        }
        p*=10;
    }
    ans+=flag;
    if(ans==0)return f(x-2)+2;
    else return ans+f(p/10+1);
}
void Solve()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=15;i++)
        tm[i]=tm[i-1]*10;
    int cnt=0;
    while(T--)
    {
        LL x;
        scanf("%lld",&x);
        printf("Case #%d: ",++cnt);
        printf("%lld\n",f(x));
    }
}
int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);
    Solve();
    return 0;
}
