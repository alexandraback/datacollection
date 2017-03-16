#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

template <typename T>
inline void upd_max(T &dest,const T& src){if(dest<src)dest=src;return ;}
template <typename T>
inline void upd_min(T &dest,const T& src){if(dest>src)dest=src;return ;}

const int maxN=1000+13;

int T,N;
int f[maxN];
int ans=0;
int v[maxN];
int ts[maxN];

bool check(int n)
{
  if(!(f[ts[1]]==ts[n] || f[ts[1]]==ts[2])) return false;
  if(!(f[ts[n]]==ts[n-1] || f[ts[n]]==ts[1])) return false;
  for(int i=2;i<=n-1;i++)
    if(!(f[ts[i]]==ts[i+1] || f[ts[i]]==ts[i-1])) return false;
  return true;
}
void dfs(int s)
{
  //cout<<s<<endl;
  //for(int i=1;i<s;i++)
  //  cout<<ts[i]<<' ';
  //cout<<endl;
  //cout<<endl;
  if(s==N+1){
    if(check(N))ans=N;
    return ;
  }
  if(ans==N) return ;
  if(s==1)
  {
    for(int i=1;i<=N;i++)
    {
      v[i]=1;
      ts[1]=i;
      dfs(2);
      v[i]=0;
    }
    return ;
  }
  for(int i=1;i<=N;i++) if(!v[i])
  {
    v[i]=1;
    ts[s]=i;
    if(check(s))upd_max(ans,s);
    dfs(s+1);
    v[i]=0;
  }
  return ;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("C-small-attempt1 (1).in","r",stdin);
  freopen("C.ans","w",stdout);
#endif
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++)
  {
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
      scanf("%d",&f[i]);
    ans=2;
    for(int i=1;i<=N;i++)
    {
      memset(v,0,sizeof(v));
      dfs(1);
    }
    printf("Case #%d: %d\n",cas,ans);
  }

  return 0;
}

