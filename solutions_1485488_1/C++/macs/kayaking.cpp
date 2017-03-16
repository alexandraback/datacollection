#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define lim 101
#define in(x,y) (x>=0 && x<y)

struct ST
{
  int x,y,z;

  ST(int x,int y,int z):x(x),y(y),z(z)
  {
  }
  bool operator<(const ST &o)const
  {
    return z>o.z;
  }
};

int cs,c,n,m,h,i,j,x,y,x2,y2,t,z;
int C[lim][lim],F[lim][lim],D[lim][lim];
priority_queue <ST> Q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void push(int x,int y,int z)
{
  if(D[x][y]==-1 || z<D[x][y])
  {
    D[x][y]=z;
    Q.push(ST(x,y,z));
  }
}
void dijkstra(bool f)
{
  while(!Q.empty())
  {
    x=Q.top().x;
    y=Q.top().y;
    z=Q.top().z;
    Q.pop();
    for(i=0;i<4;i++)
    {
      x2=x+dx[i];
      y2=y+dy[i];
      if(in(x2,n) && in(y2,m) && C[x2][y2]-F[x][y]>=50 && C[x2][y2]-F[x2][y2]>=50 && C[x][y]-F[x2][y2]>=50)
      {
        t=max(50+h-C[x2][y2]-z,0);
        if(!f && t>0)
          continue;
        if(h-(z+t)-F[x][y]>=20)
          t+=10;
        else
          t+=100;
        if(!f)
          t=0;
        push(x2,y2,z+t);
      }
    }
  }
}
int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d%d%d",&h,&n,&m);
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        scanf("%d",&C[i][j]);
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
      {
        scanf("%d",&F[i][j]);
        D[i][j]=-1;
      }
    push(0,0,0);
    dijkstra(0);
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        if(D[i][j]!=-1)
          Q.push(ST(i,j,0));
    dijkstra(1);
    printf("Case #%d: %.10lf\n",c,D[n-1][m-1]/10.);
  }
  return 0;
}
