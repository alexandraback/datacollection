#include<bits/stdc++.h>
using namespace std;
int T,n,a[1010],ans,cnt;
int mx[1010],co[1010];
int lis[1010];
int view[1010];
int work(int x)
{
    memset(view,0,sizeof(view));
    int t=0;view[x]=1;
    lis[++t]=x;
    while(true)
    {
        lis[t+1]=a[lis[t]];++t;
        if(view[lis[t]])break;
        view[lis[t]]=t;
    }
    int ret=t-view[lis[t]];
    if(ret==2)
    {
        co[lis[t]]=lis[t-1];
        co[lis[t-1]]=lis[t];
        mx[lis[t]]=max(mx[lis[t]],t-2);
    }
    return ret;
}
int main()
{
    cin>>T;
    for(int data=1;data<=T;data++)
    {
        cin>>n;ans=0;cnt=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        memset(mx,0,sizeof(mx));
        memset(co,0,sizeof(co));
        for(int i=1;i<=n;i++)ans=max(ans,work(i));
        for(int i=1;i<=n;i++)if(co[i])cnt+=mx[i]+mx[co[i]];
        cnt/=2;
        ans=max(ans,cnt);
        cout<<"Case #"<<data<<": "<<ans<<endl;;
    }
}
