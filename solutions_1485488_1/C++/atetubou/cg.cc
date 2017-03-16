#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>

using namespace std;

#define mp(a,b) make_pair(a,b)


int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

bool vis[200][200];

int solve(){
  int h,n,m;
  scanf("%d%d%d",&h,&n,&m);

  memset(vis,0,sizeof(vis));
  int c[n][m],f[n][m];
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      scanf("%d",c[i]+j);

  for(int i=0;i<n;++i)  
    for(int j=0;j<m;++j)
      scanf("%d",f[i]+j);

  priority_queue<pair<int,pair<int,int> > >q;
  q.push(mp(0,mp(0,0)));

  while(!q.empty()){
    pair<int,pair<int,int> > p=q.top();q.pop();
    int x=p.second.first;
    int y=p.second.second;
    int ti=-p.first;
    if(x==n-1 && y==m-1)
      return ti;
    if(vis[x][y])continue;
    vis[x][y]=true;

    
    for(int i=0;i<4;++i){
      int nx=x+dx[i],ny=y+dy[i];
      if(0>nx || 0>ny ||
         nx>=n || ny>=m)continue;
      if(c[nx][ny]-f[nx][ny]<50)continue;
      if(c[nx][ny]-f[x][y]<50)continue;
      if(c[x][y]-f[nx][ny]<50)continue;
      if(ti==0 && c[nx][ny]-h>=50){
        q.push(mp(0,mp(nx,ny)));
        continue;
      }
      int ct=(50-c[nx][ny]+h);
      if(ct<=ti){
        if((h-ti)-f[x][y]>=20)
          q.push(mp(-ti-10,mp(nx,ny)));
        else
          q.push(mp(-ti-100,mp(nx,ny)));
      }else{
        if((h-ct)-f[x][y]>=20)
          q.push(mp(-ct-10,mp(nx,ny)));
        else
          q.push(mp(-ct-100,mp(nx,ny)));
      }
    }
  }
}

int main(){
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;++i)
    printf("Case #%d: %.15f\n",i+1,solve()/10.0);
}
