#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

const int maxn=200;
const int mininf=2000000000;
int dx[4],dy[4];
int limint,fas;
int H,row,col;

struct Square
{
    int c,f;
}map[maxn+10][maxn+10];

int d[maxn+10][maxn+10];
bool temp[maxn+10][maxn+10];

struct Point
{
    Point(const int &xx=0,const int &yy=0)
        :x(xx),y(yy) {}
    int x,y;
};

vector<Point> starts;

void init()
{
    dx[0]=0; dx[1]=-1; dx[2]=0; dx[3]=1;
    dy[0]=-1; dy[1]=0; dy[2]=1; dy[3]=0;
    limint=50;
    fas=20;
}

bool inRange(const int &x,const int &y)
{
    return (1<=x&&x<=row&&1<=y&&y<=col);
}

void spfa()
{
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
            temp[ox][oy]=false;
            for (int f=0; f<4; f++)
            {
                int x=ox+dx[f],y=oy+dy[f];
                int t=d[ox][oy];
                if (!inRange(x,y)||map[x][y].c-map[x][y].f<limint||map[x][y].c-map[ox][oy].f<limint||map[ox][oy].c-map[x][y].f<limint) continue;
                int wait=max(0,(H-t)-(map[x][y].c-limint));
                int height=max(map[ox][oy].f,H-t-wait);
                int moveTime=height-map[ox][oy].f>=fas?10:100;
                if (d[x][y]>d[ox][oy]+wait+moveTime)
                {
                    d[x][y]=d[ox][oy]+wait+moveTime;
                    if (!temp[x][y])
                    {
                        temp[x][y]=true;
                        q.push(Point(x,y));
                    }
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
    init();
    scanf("%d",&cases);
    for (int c=1; c<=cases; c++)
    {
        scanf("%d%d%d",&H,&row,&col);
        for (int i=1;i<=row;i++)
        {
            for (int j=1;j<=col;j++)  scanf("%d",&map[i][j].c);
        }
        for (int i=1;i<=row;i++)
        {
            for (int j=1;j<=col;j++)  scanf("%d",&map[i][j].f);
        }
        memset(d,0x3f,sizeof(d));
        memset(temp,false,sizeof(temp));
        d[1][1]=0;
        temp[1][1]=true;
        starts.clear();
        starts.push_back(Point(1,1));
        for (int i=0; i<starts.size(); i++)
        {
            int ox=starts[i].x,oy=starts[i].y;
            for (int f=0; f<4; f++)
            {
                int x=ox+dx[f],y=oy+dy[f];
                if (inRange(x,y)&&!temp[x][y]&&map[x][y].c-max(map[x][y].f,H)>=limint&&map[x][y].c-max(map[ox][oy].f,H)>=limint&&map[ox][oy].c-max(map[x][y].f,H)>=limint)
                {
                    d[x][y]=0;
                    temp[x][y]=true;
                    starts.push_back(Point(x,y));
                }
            }
        }
        spfa();
        printf("Case #%d: %d.%d\n",c,d[row][col]/10,d[row][col]%10);
    }
    return 0;
}
