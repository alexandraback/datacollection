#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX=1100;
int T,N,f[MX];
int seen1[MX],dist1[MX];
bool ispair[MX];
bool iscyc[MX];
int tg[MX],dist2[MX],pval[MX];

int dfs1(int u,int r,int d) {
  if(seen1[u]==r) {
    r=u;
    u=f[u];
    for(;u!=r;) {
      iscyc[u]=true;
      u=f[u];
    }
    iscyc[u]=true;
    return d-dist1[u];
  }
  if(seen1[u]!=-1) return 0;
  seen1[u]=r, dist1[u]=d;
  return dfs1(f[u],r,d+1);
}

int dfs2(int u) {
  if(dist2[u]!=-1) return dist2[u];
  return dist2[u]=dfs2(f[u])+1;
}
int dfs3(int u) {
  if(tg[u]!=-1) return tg[u];
  if(iscyc[u]) return tg[u]=u;
  return tg[u]=dfs3(f[u]);
}

int main() {
  cin>>T; for(int zz=1;zz<=T;zz++) {
    int ans1=0;
    cin>>N; for(int i=0;i<N;i++) cin>>f[i], --f[i];
    for(int i=0;i<N;i++) seen1[i]=-1,iscyc[i]=ispair[i]=false;
    for(int i=0;i<N;i++) ans1=max(ans1,dfs1(i,i,0));
    for(int i=0;i<N;i++) ispair[i]=(i==f[f[i]]);
    for(int i=0;i<N;i++) dist2[i]=tg[i]=-1, pval[i]=0;
    for(int i=0;i<N;i++) if(iscyc[i]) dist2[i]=0;
    for(int i=0;i<N;i++) if(ispair[i]) assert(iscyc[i]);
    for(int i=0;i<N;i++) dfs2(i);
    for(int i=0;i<N;i++) dfs3(i);
    for(int i=0;i<N;i++) pval[tg[i]]=max(pval[tg[i]],dist2[i]+1);
    int ans2=0;
    for(int i=0;i<N;i++) if(ispair[i]) ans2+=pval[i];
    printf("Case #%d: %d\n",zz,max(ans1,ans2));
  }
}
