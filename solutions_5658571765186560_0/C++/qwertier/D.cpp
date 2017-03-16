#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int s,m,n;

int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int vis[21][21],mark[21][21],g[21][21];
int count(int x,int y){
  vis[x][y]=1;
  int ret=1;
  REP(k,4){
    int xt=x+dx[k],yt=y+dy[k];
    if(xt>=1 && xt<=m && yt>=1 && yt<=n && !g[xt][yt] && !vis[xt][yt])
      ret+=count(xt,yt);
  }
  return ret;
}
bool check_num(){
  memset(vis,0,sizeof(vis));
  FOR(i,m)FOR(j,n)if(!g[i][j]&&!vis[i][j]){
    if(count(i,j)%s){
      //FOR(i,m)FOR(j,n)printf("%2d%s",mark[i][j],j==n?"\n":"");
      return false;
    }
  }
  return true;
}
bool check(){
  int x1=10000,y1=10000,x2=0,y2=0;
  FOR(i,20)FOR(j,20)if(mark[i][j]){
    x1=min(x1,i);
    y1=min(y1,j);
    x2=max(x2,i);
    y2=max(y2,j);
  }
  for(int sx=1-x1; sx<=m-x2; sx++)for(int sy=1-y1; sy<=n-y2; sy++){
      memset(g,0,sizeof(g));
      for(int i=x1; i<=x2; i++)
        for(int j=y1; j<=y2; j++)
          if(mark[i][j])g[i+sx][j+sy]=1;
      if(check_num())return true;
    }
  for(int sx=1-x1; sx<=n-x2; sx++)for(int sy=1-y1; sy<=m-y2; sy++){
      memset(g,0,sizeof(g));
      for(int i=x1; i<=x2; i++)
        for(int j=y1; j<=y2; j++)
          if(mark[i][j])g[j+sy][i+sx]=1;
      if(check_num())return true;
    }
  return false;
}
bool dfs(int x,int y,int dep){
  mark[x][y]=1;
  if(dep==s){
    if(!check())return true;
  }else{
    REP(k,4){
      int xt=x+dx[k],yt=y+dy[k];
      if(xt>=1 && yt>=1 && !mark[xt][yt]){
        if(dfs(xt,yt,dep+1))return true;
      }
    }
  }
  mark[x][y]=0;
  return false;
}
int main(){
#ifdef QWERTIER
  freopen("d.in","r",stdin);
  freopen("d.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    printf("Case #%d: ",kase);
    scanf("%d%d%d",&s,&m,&n);
    if(m>n)swap(m,n);
    if(s>=7 || m*n%s!=0){
      puts("RICHARD");
      continue;
    }
    if(m>=s){
      puts("GABRIEL");
      continue;
    }
    int flag=0;
    memset(mark,0,sizeof(mark));
    FOR(i,6){
      if(dfs(i,1,1)){
        //FOR(i,m)FOR(j,n)printf("%2d%s",mark[i][j],j==n?"\n":"");
        puts("RICHARD");
        flag=1;
        break;
      }
    }
    if(!flag)puts("GABRIEL");
  }
  return 0;
}
