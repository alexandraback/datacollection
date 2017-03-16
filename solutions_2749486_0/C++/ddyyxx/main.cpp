#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#define maxn 100010
#define po 500
using namespace std;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int vis[1010][1010];
char ans[510];
char Dir[4];
int check(int x,int y)
{
    if(x<0||y<0||x>1000||y>1000||vis[x][y])
    return 0;
    return 1;
}

int SX,SY;
int path[1010][1010][4];
void bfs()
{
    queue<int > q;
    q.push(500);
    q.push(500);
    q.push(0);
    vis[500][500]=1;
    while(!q.empty())
    {
        int i;
        int x=q.front();q.pop();
        int y=q.front();q.pop();
        int len=q.front();q.pop();
        if(x==SX&&y==SY)
        {
            return;
        }
        len++;
        for(i=0;i<4;i++)
        {
            int xx=x+dir[i][0]*len,yy=y+dir[i][1]*len;
            if(check(xx,yy))
            {
                vis[xx][yy]=1;
                q.push(xx);
                q.push(yy);
                q.push(len);
                path[xx][yy][0]=x;
                path[xx][yy][1]=y;
                path[xx][yy][2]=i;
            }
        }
    }
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,time=0;
    scanf("%d",&ncase);
    Dir[0]='E',Dir[1]='N',Dir[2]='W',Dir[3]='S';
    while(ncase--)
    {
        printf("Case #%d: ",++time);
        scanf("%d%d",&SX,&SY);
        SX+=po;
        SY+=po;
        memset(vis,0,sizeof(vis));
        bfs();
        int num=0;
        while(SX!=500||SY!=500)
        {
            ans[num++]=path[SX][SY][2];
            int tmp=SX;
            SX=path[SX][SY][0];
            SY=path[tmp][SY][1];
        }
        for(int i=num-1;i>=0;i--)
        {
            printf("%c",Dir[ans[i]]);
        }
        printf("\n");
    }
    return 0;
}
