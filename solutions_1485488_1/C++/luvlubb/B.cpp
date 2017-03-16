#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define INF 1000000000
using namespace std;
typedef pair<int,int> PII;
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int unlocks[101][101];
int floors[101][101];
int ceils[101][101];
int dist[101][101];
bool incloud[101][101];
bool visit[101][101];
int t,rows,cols,h;
priority_queue<pair<int,PII> > q; 
inline void dfs(int a,int b)
{
 visit[a][b]=true;
 q.push(pair<int,PII>(0,PII(a,b)));
 dist[a][b]=0;
 //printf("visit %d %d\n",a,b);
    for(int i=1;i<=4;i++)
   {
    if(a+dy[i]>=1&&a+dy[i]<=rows&&b+dx[i]>=1&&b+dx[i]<=cols)
    {
     if(unlocks[a+dy[i]][b+dx[i]]==0&&visit[a+dy[i]][b+dx[i]]==false&&floors[a][b]<=ceils[a+dy[i]][b+dx[i]]-50&&floors[a+dy[i]][b+dx[i]]<=ceils[a+dy[i]][b+dx[i]]-50&&floors[a+dy[i]][b+dx[i]]<=ceils[a][b]-50)
     {
     // printf("from %d %d to %d %d\n",a,b,a+dy[i],b+dx[i]);
      dfs(a+dy[i],b+dx[i]);
     }
    }
   }
}
inline void dijkstra()
{
int aty,atx,att,pluss,stm;
 for(int i=1;i<=rows;i++)
 {
  for(int j=1;j<=cols;j++)
  {
   dist[i][j]=INF;
   incloud[i][j]=false;
   visit[i][j]=false;
  }
 }
 dfs(1,1);
 while(!q.empty())
 {
  att=-((q.top()).first);
  aty=((q.top()).second).first;
  atx=((q.top()).second).second;
  q.pop();
  if(incloud[aty][atx]==false)
  {
   incloud[aty][atx]=true;
  // printf("walk %d %d\n",aty,atx);
   for(int i=1;i<=4;i++)
   {
    if(aty+dy[i]>=1&&aty+dy[i]<=rows&&atx+dx[i]>=1&&atx+dx[i]<=cols)
    {
     //printf("%d %d to %d %d | %d %d , %d %d , %d %d,",aty,atx,aty+dy[i],atx+dx[i],floors[aty][atx],ceils[aty+dy[i]][atx+dx[i]]-50,floors[aty+dy[i]][atx+dx[i]],ceils[aty+dy[i]][atx+dx[i]]-50,floors[aty+dy[i]][atx+dx[i]],ceils[aty][atx]-50);
     if(incloud[aty+dy[i]][atx+dx[i]]==false&&floors[aty][atx]<=ceils[aty+dy[i]][atx+dx[i]]-50&&floors[aty+dy[i]][atx+dx[i]]<=ceils[aty+dy[i]][atx+dx[i]]-50&&floors[aty+dy[i]][atx+dx[i]]<=ceils[aty][atx]-50)
     {
      if(att>=unlocks[aty+dy[i]][atx+dx[i]])
      {
       stm=att;
      }
      else
      {
       stm=unlocks[aty+dy[i]][atx+dx[i]];
      }
     // printf("-- %d\n",(h-stm)-floors[aty][atx]);
      if((h-stm)-floors[aty][atx]>=20)
      {
       stm=stm+10;
      }
      else
      {
       stm=stm+100;
      }
      if(stm<dist[aty+dy[i]][atx+dx[i]])
      {
       dist[aty+dy[i]][atx+dx[i]]=stm;
       q.push(pair<int,PII>(-stm,PII(aty+dy[i],atx+dx[i])));
      }
     }
    }
   }
  }
 }
}
main()
{
 freopen("B-large.in","r",stdin);
 freopen("B-large.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%d%d%d",&h,&rows,&cols);
  for(int i=1;i<=rows;i++)
  {
   for(int j=1;j<=cols;j++)
   {
    scanf("%d",&ceils[i][j]);
    if(ceils[i][j]-h>=50){unlocks[i][j]=0;}
    else{unlocks[i][j]=h-ceils[i][j]+50;}
   }
  }
    for(int i=1;i<=rows;i++)
  {
   for(int j=1;j<=cols;j++)
   {
    scanf("%d",&floors[i][j]);
   }
  }
  while(!q.empty())
  {
   q.pop();
  }
  dijkstra();
  /*for(int i=1;i<=rows;i++)
  {
   for(int j=1;j<=cols;j++)
   {
    printf("%d ",dist[i][j]);
   }
   printf("\n");
  }*/
  printf("Case #%d: %d.%d\n",tests,dist[rows][cols]/10,dist[rows][cols]%10);
 }
 return 0;
}
