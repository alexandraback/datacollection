#include <cstdio>
#include <cstring>
#define Min(a,b) ((a)<(b)?(a):(b))
#define oo 1000000000
using namespace std;
int dis[105][105]={0};
int f[105][105]={0},c[105][105]={0};
int hash[105][105]={0};
int dl[50005][2]={0};
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
inline bool check(int x,int y,int x1,int y1,int w)
{if(w+50<=c[x1][y1]&&f[x][y]+50<=c[x1][y1]&&f[x1][y1]+50<=c[x1][y1]&&f[x1][y1]+50<=c[x][y])return 1;
 return 0;
}
int main()
{int n,m,i,j,k,l,H,h,t,T,tt=0;
 freopen("B.in","r",stdin);
 freopen("B.out","w",stdout);
 scanf("%d",&T);
 while(T--)
 {tt++;
  scanf("%d",&H);
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
    scanf("%d",&c[i][j]);
  for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
    scanf("%d",&f[i][j]);
  for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
   {dis[i][j]=oo;
    hash[i][j]=0;
   }
  dis[1][1]=0;
  h=0;t=1;
  dl[1][0]=1;
  dl[1][1]=1;
  hash[1][1]=1;
  do
  {h++;
   for(i=0;i<4;i++)
   {int x1=dl[h][0]+dx[i],y1=dl[h][1]+dy[i];
    if(x1>0&&y1>0&&x1<=n&&y1<=m&&check(dl[h][0],dl[h][1],x1,y1,H)&&!hash[x1][y1])
    {hash[x1][y1]=1;
     dis[x1][y1]=0;
     dl[++t][0]=x1;
     dl[t][1]=y1;
    }
   }
  }while(h<t);
  h=0;
  do
  {h++;
   int h1=h%30000,H1=H-dis[dl[h1][0]][dl[h1][1]];
   for(i=0;i<4;i++)
   {int x1=dl[h1][0]+dx[i],y1=dl[h1][1]+dy[i],H2,qz;
    if(x1>0&&y1>0&&x1<=n&&y1<=m)
    {H2=c[x1][y1]-50;
     if(H2>H1)H2=H1;
     if(check(dl[h1][0],dl[h1][1],x1,y1,H2))
     {qz=(H1-H2);
      if(H2-f[dl[h1][0]][dl[h1][1]]>=20)qz+=10;
      else qz+=100;
      if(dis[x1][y1]>dis[dl[h1][0]][dl[h1][1]]+qz)
      {if(!hash[x1][y1])
       {hash[x1][y1]=1;
        t++;
        int t1=t%30000;
        dl[t1][0]=x1;
        dl[t1][1]=y1;
       }
       dis[x1][y1]=dis[dl[h1][0]][dl[h1][1]]+qz;
      }
     }
    }
   }
   hash[dl[h1][0]][dl[h1][1]]=0;
  }while(h<t);
  printf("Case #%d: %d.%d\n",tt,dis[n][m]/10,dis[n][m]%10);
 }
 return 0;
}
 
