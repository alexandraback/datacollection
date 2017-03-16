#include <iostream>
#include <stdio.h>
using namespace std;
#include <queue>
#include <string.h>
#include <algorithm>
#define MAXN 220
struct NODE
{
    int x,y;
    int times;
    string road;
};
bool used[MAXN][MAXN];
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
string dir[4] = {"N","S","E","W"};
int MAP[MAXN][MAXN];
string BFS(int endx,int endy)
{
    NODE now,next;
    now.x = 100;
    now.y = 100;
    now.times = 0;
    now.road = "";
    memset(used,false,sizeof(used));
    used[100][100] = true;
    queue <NODE> Q;
    while(!Q.empty()) Q.pop();
    Q.push(now);
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            next.x = now.x+X[i]*(now.times+1);
            next.y = now.y+Y[i]*(now.times+1);
            if(next.x<0||next.x>200||next.y<0||next.y>200) continue;
            if(used[next.x][next.y]==true) continue;
            used[next.x][next.y] = true;
            next.times = now.times+1;
            next.road = now.road+dir[i];
            if(next.x==endx&&next.y==endy) return next.road;
            Q.push(next);
        }
    }
    return "error";
}
int main()
{
    int T;
    int x,y;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&T);

    for(int cnt = 1;cnt<=T;cnt++)
    {
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",cnt);
        cout<<BFS(x+100,y+100)<<endl;
    }
}
