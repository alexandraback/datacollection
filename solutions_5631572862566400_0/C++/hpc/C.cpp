//GCJ 2016 round1A C
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 1005
using namespace std;
int N,ans,ans2,tmp;

int out[MAXN];
vector<int>in[MAXN];
bool T;
int v[MAXN];
bool V[MAXN];
void solve_in(int x,int y,int c)
{
    //cout<<x<<": ";
    if(in[x].size()==0)
    {
        if(c>=ans) ans=c,T=0;
        //ans=max(ans,c);
        return;
    }
    for(int i=0;i<in[x].size();++i)
    {
        if(in[x][i]==y) continue;
        solve_in(in[x][i],y,c+1);
    }
}
void solve(int x,int r,int c)
{
    //cout<<x<<" ";
    v[x]=c;
    if(v[out[x]]==0)
        solve(out[x],r,c+1);
    else
    {
        if(out[x]==r&&c==2&&in[x].size()==1&&in[out[x]].size()==1)
        {
            tmp+=1;
        }
        else if(out[x]==r)
        {
            if(c>ans2) ans2=c,T=1;
        }
        else if(out[out[x]]==x)
        {
            if(c>=ans) ans=c,T=0;
            solve_in(x,out[x],c);
        }
        else
        {
        }
    }
}
int main()
{
    freopen("C-small-attempt4.in","r",stdin);
    freopen("C-small-attempt4.out","w",stdout);
    int Case,a;
    scanf("%d",&Case);
    for(int t=1;t<=Case;++t)
    {
        scanf("%d",&N);
        for(int i=0;i<MAXN;++i)
            in[i].clear();
        memset(out,0,sizeof(out));
        for(int i=1;i<=N;++i)
        {
            scanf("%d",&a);
            out[i]=a;
            in[a].push_back(i);
        }
        ans=0,ans2=0;
        tmp=0;
        T=0;
        for(int i=1;i<=N;++i)
        {
            //cout<<i<<" ";
            memset(v,0,sizeof(v));
            solve(i,i,1);
            //cout<<"\n";
        }
        ans+=tmp;
        printf("Case #%d: %d\n",t,max(ans,ans2));

    }
    return 0;
}
