#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define p 1000000007
#define pb push_back
#define mp make_pair
typedef long long Int;
typedef pair<Int,Int> pii;
typedef vector<Int> vi;
typedef vector<pii> vii;
vi G[1002];
vi RG[1002];//reverse graph
Int maxm=0;
Int depth[1002];
Int N,inc[1002];
Int visited[1002];
Int lonchain[1002];//longest chain upto each node
void dfs(Int src)
{
    visited[src]=-1;
    if (visited[G[src][0]]==0)
    {
        depth[G[src][0]]=depth[src]+1;
        dfs(G[src][0]);
    }
    else if (visited[G[src][0]]==-1)
        maxm=max(maxm,depth[src]-depth[G[src][0]]+1);
    visited[src]=1;
}
void dfs2(Int src)
{
    visited[src]=1;
    if (visited[G[src][0]]==0)
    {
        lonchain[G[src][0]]=max(lonchain[G[src][0]],lonchain[src]+1);
        dfs2(G[src][0]);
    }
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    Int T;
    cin>>T;
    for (Int z=1;z<=T;++z)
    {
       maxm=0;
       Int total=0;
       Int f;
       cin>>N;
       for (Int i=1;i<=N;++i)
       {
           inc[i]=0;
           depth[i]=0;
           G[i].clear();
           RG[i].clear();
           visited[i]=0;
           lonchain[i]=0;
       }
       for (Int i=1;i<=N;++i)
       {
           cin>>f;
           G[i].pb(f);
           RG[f].pb(i);
           inc[f]++;
       }
       for (Int i=1;i<=N;++i)
       {
           if (visited[i]==0)
           {
                depth[i]=1;
                dfs(i);
           }
       }
       memset(visited,0,sizeof(visited));
       for (Int i=1;i<=N;++i)
       {
           if (inc[i]==0)
           {
               lonchain[i]=1;
               dfs2(i);
           }
       }
       //for (Int i=1;i<=N;++i)
        //cout<<lonchain[i]<<" ";
       //cout<<"\n";
       for (Int i=1;i<=N;++i)
       {
           if (G[G[i][0]][0]==i&&G[i][0]>i)
           {
               //cout<<"This :"<<i<<" "<<G[i][0]<<"\n";
               Int j=G[i][0];
               Int l1=0,l2=0;
               for (Int k=0;k<RG[i].size();++k)
               {
                   if (RG[i][k]==j)
                    continue;
                   l1=max(l1,lonchain[RG[i][k]]);
                   //cout<<RG[i][k]<<" "<<lonchain[RG[i][k]]<<"\n";
               }
               for (Int k=0;k<RG[j].size();++k)
               {
                   if (RG[j][k]==i)
                    continue;
                   l2=max(l2,lonchain[RG[j][k]]);
              }
               total=total+l1+l2+2;
           }
       }
       maxm=max(maxm,total);
       cout<<"Case #"<<z<<": "<<maxm<<"\n";
    }
    return 0;
}
/*
4
10
7 8 10 10 9 2 9 6 3 3
*/
