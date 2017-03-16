#include <string>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int Maxn=100;
const int INF=0x3f3f3f3f;
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
const int limit1=50;
const int fast1=20;
int H,row,col;
struct Square
{
    int ceiling,floor;
} map[Maxn+10][Maxn+10];
int d[Maxn+10][Maxn+10];
bool inQueue[Maxn+10][Maxn+10];
struct Position
{
    Position(const int &xx=0,const int &yy=0):x(xx),y(yy) {}
    int x,y;
};
vector<Position> starts;
void ReadIn()
{

}
bool Test(const int &x,const int &y)
{
    return 1<=x && x<=row && 1<=y && y<=col;
}
void init()
{
    memset(d,0x3f,sizeof(d));
    memset(inQueue,false,sizeof(inQueue));
    d[1][1]=0;
    inQueue[1][1]=true;
    starts.clear();
    starts.push_back(Position(1,1));
}
void did()
{
    for (unsigned int i=0; i<starts.size(); i++)
    {
        int ox=starts[i].x,oy=starts[i].y;
        for (int f=0; f<4; f++)
        {
            int x=ox+dx[f],y=oy+dy[f];
            if (Test(x,y) && !inQueue[x][y] &&
                    map[x][y].ceiling-max(map[x][y].floor,H)>=limit1 &&
                    map[x][y].ceiling-max(map[ox][oy].floor,H)>=limit1 &&
                    map[ox][oy].ceiling-max(map[x][y].floor,H)>=limit1)
            {
                d[x][y]=0;
                inQueue[x][y]=true;
                starts.push_back(Position(x,y));
            }
        }
    }
}
void bfs()
{
    init();
    did();
}
struct Q:public queue<Position>
{
    void clear()
    {
        c.clear();
    }
}q;
void init1()
{
    q.clear();
    for (unsigned int i=0; i<starts.size(); i++)
    {
        q.push(starts[i]);
    }
}
void spfa()
{
    init1();
    for (int j=1; j<=col; j++)
        while (!q.empty())
        {
            int ox=q.front().x,oy=q.front().y;
            q.pop();
            inQueue[ox][oy]=false;
            for (int f=0; f<4; f++)
            {
                int x=ox+dx[f],y=oy+dy[f];
                int t=d[ox][oy];
                if (!Test(x,y) ||
                        map[x][y].ceiling-map[x][y].floor<limit1 ||
                        map[x][y].ceiling-map[ox][oy].floor<limit1 ||
                        map[ox][oy].ceiling-map[x][y].floor<limit1)
                    continue;
                int wait=max(0,(H-t)-(map[x][y].ceiling-limit1));
                int leavingHeight=max(map[ox][oy].floor,H-t-wait);
                int moveTime=leavingHeight-map[ox][oy].floor>=fast1?10:100;
                if (d[x][y]>d[ox][oy]+wait+moveTime)
                {
                    d[x][y]=d[ox][oy]+wait+moveTime;
                    if (!inQueue[x][y])
                    {
                        inQueue[x][y]=true;
                        q.push(Position(x,y));
                    }
                }

            }
        }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    for (int cas=1; cas<=cases; cas++)
    {
        scanf("%d%d%d",&H,&row,&col);
        for (int i=1; i<=row; i++)
            for (int j=1; j<=col; j++)
                scanf("%d",&map[i][j].ceiling);
        for (int i=1; i<=row; i++)
            for (int j=1; j<=col; j++)
                scanf("%d",&map[i][j].floor);
        bfs();
        spfa();
        printf("Case #%d: %d.%d\n",cas,d[row][col]/10,d[row][col]%10);
    }
    return 0;
}
