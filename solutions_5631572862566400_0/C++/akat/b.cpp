#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
int bff[1004],o,used[1004],co,dis[1004],md,p,l,m;
void dfs(int x,int d)
{
    used[x]=d;
    if(used[bff[x]]!=0)
    {
        m=x;
        co=d-used[bff[x]]+1;
        p=bff[x];
        if(x==bff[p])
        {
            l=1;
            p=-2;
            co=used[x];
        }
    }
    else dfs(bff[x],d+1);
    if(p==-1)used[x]=0;
    if(x==p)p=-1;
}
void ddfs(int x)
{
    dis[x]=-1;
    if(used[bff[x]]==0 && dis[bff[x]]==0)ddfs(bff[x]);
    if(used[bff[x]] && bff[x]==m)dis[x]=1;
    else if(dis[bff[x]]==-1)dis[x]=-1;
    else if(dis[bff[x]])dis[x]=dis[bff[x]]+1;
    md=max(dis[x],md);
}
void solve()
{
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>bff[i];
    o=0;
    for(i=1;i<=n;++i)
    {
        l=md=co=0;
        memset(used,0,sizeof(used));
        if(used[i]==0)dfs(i,1);
        memset(dis,0,sizeof(dis));
        for(j=1;j<=n;++j)
            if(used[j]==0 && dis[j]==0)ddfs(j);
        o=max(o,md*l+co);
    }
    cout<<o<<'\n';
}
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
