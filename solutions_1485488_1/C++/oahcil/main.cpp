#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 200

using namespace std;

const int mininf=1500000000;
const int dx[4]= {0,-1,0,1};
const int dy[4]= {-1,0,1,0};
int limint,fas;
int H,row,col;

struct Square
{
    int c,f;
} map[maxn+10][maxn+10];

int d[maxn+10][maxn+10];
bool flag[maxn+10][maxn+10];

struct Point
{
    Point(const int &xx=0,const int &yy=0)
    {
        x=xx,y=yy;
    }
    int x,y;
};

vector<Point> starts;

bool check(const int &x,const int &y)
{
    return (1<=x&&x<=row&&1<=y&&y<=col);
}
bool check2(int ox,int oy,int x, int y)
{
    return (map[x][y].c-max(map[x][y].f,H)>=limint&&map[x][y].c-max(map[ox][oy].f,H)>=limint&&map[ox][oy].c-max(map[x][y].f,H)>=limint);
}
void solve()
{
    memset(d,0x3f,sizeof(d));
    memset(flag,false,sizeof(flag));
    d[1][1]=0;
    flag[1][1]=true;
    starts.clear();
    starts.push_back(Point(1,1));
    for (int i=0; i<starts.size(); i++)
    {
        int ox=starts[i].x,oy=starts[i].y;
        for (int f=0; f<4; f++)
        {
            int x=ox+dx[f],y=oy+dy[f];
            if (check(x,y)&&!flag[x][y]&&check2(ox,oy,x,y))
            {
                d[x][y]=0;
                flag[x][y]=true;
                starts.push_back(Point(x,y));
            }
        }
    }
    queue<Point> q;
    for (int i=0; i<starts.size(); i++)
    {
        q.push(starts[i]);
    }
    for (int j=1; j<=col; j++)
    {
        while (!q.empty())
        {
            int ox=q.front().x,oy=q.front().y;
            q.pop();
            flag[ox][oy]=false;
            for (int f=0; f<4; f++)
            {
                int x=ox+dx[f],y=oy+dy[f];
                int t=d[ox][oy];
                if (!check(x,y)||map[x][y].c-map[x][y].f<limint||map[x][y].c-map[ox][oy].f<limint||map[ox][oy].c-map[x][y].f<limint) continue;
                int wait=max(0,(H-t)-(map[x][y].c-limint));
                int height=max(map[ox][oy].f,H-t-wait);
                int moveTime=height-map[ox][oy].f>=fas?10:100;
                if (d[x][y]>d[ox][oy]+wait+moveTime)
                {
                    d[x][y]=d[ox][oy]+wait+moveTime;
                    if (!flag[x][y])
                    {
                        flag[x][y]=true;
                        q.push(Point(x,y));
                    }
                }
            }
        }
    }
}

int main()
{
    int cases;
    limint=50;
    fas=20;
    scanf("%d",&cases);
    for (int c=1; c<=cases; c++)
    {
        scanf("%d%d%d",&H,&row,&col);
        for (int i=1; i<=row; i++)
        {
            for (int j=1; j<=col; j++)  scanf("%d",&map[i][j].c);
        }
        for (int i=1; i<=row; i++)
        {
            for (int j=1; j<=col; j++)  scanf("%d",&map[i][j].f);
        }
        solve();
        printf("Case #%d: %d.%d\n",c,d[row][col]/10,d[row][col]%10);
    }
    return 0;
}
