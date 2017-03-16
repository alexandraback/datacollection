#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a,b,d,e,f;
int t;
int n,m;
double C[105][105];
double F[105][105];
double dp[105][105];
double h,sum,l,r,mid;
int head,tail;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
struct dfdjk{
       int x,y;
       }lie[10000000];

int pan(int x1,int y1,int x2,int y2,double h)
{
    int a,b;
    if (C[x1][y1]-max(h,F[x1][y1])<50) return 0;
    if (C[x2][y2]-max(h,F[x2][y2])<50) return 0;
    if (C[x2][y2]-F[x1][y1]<50) return 0;
    if (C[x2][y2]-F[x2][y2]<50) return 0;
    if (C[x1][y1]-F[x1][y1]<50) return 0;
    if (C[x1][y1]-F[x2][y2]<50) return 0;
    return 1;
}

double cao(int x1,int y1,int x2,int y2,double h)
{
    int a,b;
    if (C[x2][y2]-F[x1][y1]<50) return -1;
    if (C[x2][y2]-F[x2][y2]<50) return -1;
    if (C[x1][y1]-F[x1][y1]<50) return -1;
    if (C[x1][y1]-F[x2][y2]<50) return -1;
    double yao=C[x2][y2]-50;
    if (yao>=h) return 0; else return (h-yao)/10.0;
}

double suan(int x,int y,double h)
{
       h=max(F[x][y],h);
       if (h-F[x][y]>=20) return 1;
       else return 10;
}

void yuchuli()
{
     int a,b,c,d;
     int x,y;
     int tx,ty;
     while (head<=tail)
     {
           x=lie[head].x;  y=lie[head].y;
           for (a=0;a<=3;a++)
           if (x+dx[a]>=1 && x+dx[a]<=n && y+dy[a]>=1 && y+dy[a]<=m)
           {
              tx=x+dx[a]; ty=y+dy[a];
              if (pan(x,y,tx,ty,h)==1)
              if (dp[tx][ty]==-1)
              {
                 tail++;
                 lie[tail].x=tx;
                 lie[tail].y=ty;
                 dp[tx][ty]=0;
              }
           }
           head++;
     }
}

void fuck()
{
     int a,b;
     double hnow;
     int x,y,tx,ty;
     while (head<=tail)
     {
           x=lie[head].x;  y=lie[head].y;
           hnow=h-dp[x][y]*10;
           for (a=0;a<=3;a++)
           if (x+dx[a]>=1 && x+dx[a]<=n && y+dy[a]>=1 && y+dy[a]<=m)
           {
              tx=x+dx[a]; ty=y+dy[a];
              if (cao(x,y,tx,ty,hnow)!=-1)
              {
                 double kkk=cao(x,y,tx,ty,hnow);
              if (dp[tx][ty]==-1 || dp[x][y]+suan(x,y,hnow-kkk*10)+kkk<dp[tx][ty])
              {
                 tail++;
                 lie[tail].x=tx;
                 lie[tail].y=ty;
                 dp[tx][ty]=dp[x][y]+suan(x,y,hnow-kkk*10)+kkk;
              }
              }
           }
           head++;
     }
}
int main()
{
    freopen("B-small-attempt0(2).in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>t;
    for (int cas=1;cas<=t;cas++)
    {
        cin>>h>>n>>m;
        for (a=1;a<=n;a++)
            for (b=1;b<=m;b++)
                dp[a][b]=-1;
        for (a=1;a<=n;a++)
            for (b=1;b<=m;b++)
                cin>>C[a][b];
        for (a=1;a<=n;a++)
            for (b=1;b<=m;b++)
                cin>>F[a][b];
        head=1; tail=1;
        dp[1][1]=0;
        lie[1].x=1; lie[1].y=1;
        yuchuli();
        head=1;
        fuck();
        printf("Case #%d: %.5lf\n",cas,dp[n][m]);
    }
}
        
        
        
        
        
