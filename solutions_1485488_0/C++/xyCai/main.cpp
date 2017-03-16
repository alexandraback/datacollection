#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

#define Height 50
#define CanSwim 20

using namespace std;

//const int dx[4]={0,-1,0,1};
//const int dy[4]={-1,0,1,0};

const int dir[4][2] = {0,-1,-1,0,0,1,1,0};
struct Square
{
    int TianHuaBan,DiBan;
} map[115][115];
int ZaiDuiLieLi[115][115];
int d[115][115];
int H,N,M;
struct Pos
{
    Pos(const int &xx=0,const int &yy=0)
        :x(xx),y(yy) {}
    int x,y;
};
vector<Pos> KaiTou;
bool inRange(const int &x,const int &y)
{
    return 1<=x && x<=N && 1<=y && y<=M;
}
void SPFA()
{
    return ;
}

int main()
{
//    freopen("B-small-attempt0.in","r",stdin);
//    freopen("B-small-attempt0.out","w",stdout);
    int cases = 1,t;
    scanf("%d",&t);
    int i,j;
    while(t--)
    {
        scanf("%d%d%d",&H,&N,&M);
        for (i=1; i<=N; i++)
        {
            for (j=1; j<=M; j++)
            {
                scanf("%d",&map[i][j].TianHuaBan);
            }
        }
        for (i=1; i<=N; i++)
        {
            for (j=1; j<=M; j++)
            {
                scanf("%d",&map[i][j].DiBan);
            }
        }
        memset(d,0x3f,sizeof(d));
        memset(ZaiDuiLieLi,0,sizeof(ZaiDuiLieLi));
        d[1][1]=0;
        ZaiDuiLieLi[1][1]=1;
        KaiTou.clear();
        KaiTou.push_back(Pos(1,1));
        for (i=0; i<KaiTou.size(); i++)
        {
            int valx=KaiTou[i].x;
            int valy=KaiTou[i].y;
            for (int f=0; f<4; f++)
            {
                int x=valx+dir[f][0];
                int y=valy+dir[f][1];
                bool isInRange = inRange(x,y);
                bool j2 = (!ZaiDuiLieLi[x][y]);
                bool j3 = (map[x][y].TianHuaBan-max(map[x][y].DiBan,H)>=Height);
                bool j4 = (map[x][y].TianHuaBan-max(map[valx][valy].DiBan,H)>=Height);
                bool j5 = (map[valx][valy].TianHuaBan-max(map[x][y].DiBan,H)>=Height);
                if (isInRange && j2 && j3 && j4 && j5)
                {
                    d[x][y]=0;
                    ZaiDuiLieLi[x][y]=1;
                    KaiTou.push_back(Pos(x,y));
                }
            }
        }
        SPFA();
        queue<Pos> q;
        for (int i=0; i<KaiTou.size(); i++)
        {
            q.push(KaiTou[i]);
        }
        for (int j=1; j<=M; j++)
            while (!q.empty())
            {
                int valx=q.front().x;
                int valy=q.front().y;
                q.pop();
                ZaiDuiLieLi[valx][valy]=0;
                for (int f=0; f<4; f++)
                {
                    int Hehe;
                    int HaiShengDuoGao;
                    int x = valx+dir[f][0];
                    int y=valy+dir[f][1];
                    int t=d[valx][valy];
                    bool j1 = (!inRange(x,y));
                    bool j2 = (map[x][y].TianHuaBan-map[x][y].DiBan<Height);
                    bool j3 = (map[x][y].TianHuaBan-map[valx][valy].DiBan<Height);
                    bool j4 = (map[valx][valy].TianHuaBan-map[x][y].DiBan<Height);
                    if ( j1||j2||j3||j4)
                        continue;
                    Hehe = (H-t)-(map[x][y].TianHuaBan-Height)>0?(H-t)-(map[x][y].TianHuaBan-Height):0;
                    HaiShengDuoGao=max(map[valx][valy].DiBan,H-t-Hehe);
                    int moveTime=HaiShengDuoGao-map[valx][valy].DiBan>=CanSwim?10:100;
                    if (d[x][y]>d[valx][valy]+Hehe+moveTime)
                    {
                        d[x][y]=d[valx][valy]+Hehe+moveTime;
                        if (!ZaiDuiLieLi[x][y])
                        {
                            ZaiDuiLieLi[x][y] = 1;
                            q.push(Pos(x,y));
                        }
                    }

                }
            }
        printf("Case #%d: %d.%d\n",cases++,d[N][M]/10,d[N][M]%10);
    }
    return 0;
}
