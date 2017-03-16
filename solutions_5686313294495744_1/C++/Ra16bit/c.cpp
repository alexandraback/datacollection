#include <bits/stdc++.h>
using namespace std;
int t,tt,n,na,nb,r,i,x,y,it,u[2020],b[2020];
vector<int> g[2020];
map<string,int> ma,mb;
string s;
char st[44];
bool dfs(int i) {
  if (u[i]==it) return false;
  u[i]=it;
  for (int j=0; j<g[i].size(); j++) if (b[g[i][j]]==-1 || dfs(b[g[i][j]])) {
    b[g[i][j]]=i;
    return true;
  }
  return false;
}
int main() {
  freopen("Cl.in","r",stdin);
  freopen("Cl.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    na=nb=0;
    ma.clear();
    mb.clear();
    scanf("%d",&n);
    for (i=0; i<n; i++) {
      scanf("%s",st); s=st;
      if (ma.count(s)) x=ma[s]; else { ma[s]=x=++na; g[na].clear(); }
      scanf("%s",st); s=st;
      if (mb.count(s)) y=mb[s]; else { mb[s]=y=++nb; b[nb]=-1; }
      g[x].push_back(y);
    }
    r=na+nb;
    for (i=1; i<=na; i++) {
      ++it;
      if (dfs(i)) r--;
    }
    printf("Case #%d: %d\n",t,n-r);
  }
  return 0;
}
