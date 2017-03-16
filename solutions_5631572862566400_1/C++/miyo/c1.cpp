#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

template <typename T>
inline void upd_max(T &dest,const T& src){if(dest<src)dest=src;return ;}
template <typename T>
inline void upd_min(T &dest,const T& src){if(dest>src)dest=src;return ;}

const int maxN=1000+13;
const int maxE=3000+13;

struct Arc
{
  int dest;
  Arc* next;
  Arc(){};
  Arc(int dest,Arc* next):dest(dest),next(next){};
}Npool[maxE],*Nptr;

Arc *adj[maxN];
void add_edge(int st,int ed)
{
  adj[st]=new (Nptr++) Arc(ed,adj[st]);
}

int T,N,f[maxN];
int low[maxN],dfn[maxN],Belong[maxN];
int sb[maxN],nxt[maxN];
bool v[maxN];
vector<int>po[maxN];

int ind=0,Bcnt=0;
stack<int>s;

void tarjan(int id)
{
  dfn[id]=low[id]=++ind; v[id]=true;  s.push(id);
  int tt;
  for(Arc* p=adj[id];p;p=p->next)
  {
    tt=p->dest;
    if(!dfn[tt])
    {
      tarjan(tt);
      if(low[tt]<low[id]) low[id]=low[tt];
    }
    else if(v[tt] && dfn[tt]<low[id]) low[id]=dfn[tt];
  }
  if(dfn[id]==low[id])
  {
    Bcnt++; tt=0;
    while(tt!=id)
    {
      tt=s.top(); s.pop(); v[tt]=false;
      Belong[tt]=Bcnt;
      sb[Bcnt]++;
      po[Bcnt].push_back(tt);
    }
  }
  return ;
}
void t_solve()
{
  Bcnt=ind=0;
  while(!s.empty())s.pop();
  memset(dfn,0,sizeof(dfn));
  for(int i=1;i<=N;i++) if(!dfn[i]) tarjan(i);
  return ;
}

void reset()
{
  Nptr=Npool;
  for(int i=1;i<=N;i++) adj[i]=NULL;
  for(int i=1;i<=N;i++) po[i].clear();
  Bcnt=0;ind=0;
  memset(low,0,sizeof(low));
  memset(dfn,0,sizeof(dfn));
  memset(Belong,0,sizeof(Belong));
  memset(v,0,sizeof(v));
  memset(sb,0,sizeof(sb));
}
int dfs(int id)
{
  v[id]=1;
  int ret=0;
  for(Arc* p=adj[id];p;p=p->next) if(!v[p->dest])
  {
    int tl=dfs(p->dest);
    if(tl>ret) 
    {
      ret=tl;
      nxt[id]=p->dest;
    }
  }
  return ret+1;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("C-large.in","r",stdin);
  freopen("C.out","w",stdout);
#endif
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++)
  {
    reset();
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
      scanf("%d",&f[i]);
    for(int i=1;i<=N;i++)
      add_edge(f[i],i);
    t_solve();
    int ans=0;
    for(int i=1;i<=Bcnt;i++)
      if(sb[i]>=2)upd_max(ans,sb[i]);
    int ans2=0;
    for(int i=1;i<=Bcnt;i++) if(sb[i]==2) ans2+=2;
    for(int i=1;i<=Bcnt;i++)if(sb[i]==2)
    {
      //cout<<po[i][0]<<' '<<po[i][1]<<endl;
      int tans=0;
      memset(v,0,sizeof(v));
      v[po[i][0]]=1;v[po[i][1]]=1;
      memset(nxt,-1,sizeof(nxt));
      tans+=dfs(po[i][0])-1;
      //cout<<"For:"<<po[i][0]<<' '<<tans-2<<endl;
      memset(v,0,sizeof(v));
      v[po[i][0]]=1;v[po[i][1]]=1;
      int id=po[i][0];
      while(id!=-1)
      {
        v[id]=1;
        id=nxt[id];
      }
      tans+=dfs(po[i][1])-1;
      //cout<<"For:"<<po[i][1]<<' '<<tans<<endl;
      //cout<<tans-3<<endl;
      ans2+=max(0,tans);
    }
    upd_max(ans,ans2);
    printf("Case #%d: %d\n",cas,ans);
  }
  return 0;
}

