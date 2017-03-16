#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int in[200020];
int out[200020];
bool c[200020];
int H[200020];
int ans[200020][2];
int timer;
vector < int > g[200020];

void dfs(int p,int u)
 {
  timer++;
  in[u]=timer;
  for (int i=0;i<g[u].size();i++)
   {
    int to=g[u][i];
    if (to == p) continue;
    H[to]=1-H[u];
    dfs(u,to);
    ans[u][0]^=ans[to][1];
    ans[u][1]^=ans[to][0];
   }
  ans[u][0]^=c[u];
  out[u]=timer;
 }

int n,i,u,v,a,b,q,nw;

int main()
 {
  cin>>n;
  for (i=1;i<=n;i++)
   scanf("%d",&c[i]);

  for (i=1;i<n;i++)
   {
    scanf("%d%d",&a,&b);
    g[a].pb(b);
    g[b].pb(a);
   }
  dfs(0,1);
  scanf("%d",&q);
  while (q--)
   {
    scanf("%d%d",&u,&v);
    if (in[u] <= in[v] && out[v] <= out[u])
     {
      printf("INVALID\n");
      continue;
     }
    nw=ans[1][1]^ans[u][1-H[u]]^ans[u][H[v]];
    printf((nw)?("YES\n"):("NO\n"));
   }
 }
