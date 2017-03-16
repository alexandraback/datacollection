#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int a[1010];
int next[2010],first[1010],tail[2010],dep[1010],las[1010];
int vis[1010];
int i,j,k,n,m,ca,cas,ans,t,c,p,la;

void Init(){

  p=0;
  memset(first,0,sizeof(first));
  memset(next,0,sizeof(next));
  memset(dep,0,sizeof(dep));
  memset(las,0,sizeof(las));

}

void Make(int x,int y){

  next[++p]=first[x];
  first[x]=p;
  tail[p]=y;

  next[++p]=first[y];
  first[y]=p;
  tail[p]=x;
}

void Dfs(int u,int fa){

int v,x;

  dep[u]=dep[fa]+1;
  las[u]=dep[u];
  vis[u]=1;
  x=first[u];
  while (x){
    v=tail[x];
    if (v!=fa && !vis[v]){
      Dfs(v,u);
      las[u]=max(las[u],las[v]);
    }
    x=next[x];
  }
  return;
}

int main(){

  freopen("C_s.in","r",stdin);
  freopen("C_s.out","w",stdout);
  scanf("%d",&cas);
  for (ca=1;ca<=cas;ca++){
    scanf("%d",&n);
    Init();
    for (i=1;i<=n;i++){
      scanf("%d",&a[i]);
      Make(a[i],i);
    }
    ans=0;
    for (i=1;i<=n;i++){
      t=1;
      memset(vis,0,sizeof(vis));
      c=i;
      vis[c]=1;
      c=a[c];
      la=i;
      while (!vis[c]){
      //  printf("%d %d\n",i,c);
        t++;
        vis[c]=1;
        la=c;
        c=a[c];

      }
    //  printf("%d %d %d\n",i,c,la);
      if (c==i) ans=max(ans,t);
      else if (a[c]==la){
    //    printf("%d %d %d\n",c,la,t);
        Dfs(la,0);
        ans=max(ans,t+las[la]-1);
      }
    }
    printf("Case #%d: %d\n",ca,ans);
  }

  return 0;





}
