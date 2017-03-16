#include <cstdio>
#include <algorithm>
using namespace std;
long long ti,xx,yy;
int exi[300][300];
long long co;
int mini;
void simulate(int re)
{
    if(re==0)
    {
        ti+=exi[xx][yy];
        co++;
        return;
    }
    int y=0,x=150,tx,ty;
    while(exi[150][y])
        y+=2;
    tx=x;
    ty=y;
    if(exi[x-1][y-1]==0)
    {
        while(y>0&&!exi[x-1][y-1])
        {
            x--;
            y--;
        }
        exi[x][y]=1;
        simulate(re-1);
        exi[x][y]=0;
    }
    x=tx;
    y=ty;
    if(exi[x+1][y-1]==0)
    {
        while(y>0&&!exi[x+1][y-1])
        {
            x++;
            y--;
        }
        exi[x][y]=1;
        simulate(re-1);
        exi[x][y]=0;
    }
    x=tx;
    y=ty;
    if(exi[x+1][y-1]==1&&exi[x-1][y-1]==1)
    {
        exi[x][y]=1;
        simulate(re-1);
        exi[x][y]=0;
    }
}
int solve()
{
    for(int i=0;i<300;i++)
    {
        for(int j=0;j<300;j++)
        {
            exi[i][j]=0;
        }
    }
    co=0;
    ti=0;
    mini=10000;
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    if(n>=15)
    {
        exi[150][0]=1;
        exi[152][0]=1;
        exi[148][0]=1;
        exi[151][1]=1;
        exi[149][1]=1;
        exi[150][2]=1;
        exi[154][0]=1;
        exi[153][1]=1;
        exi[152][2]=1;
        exi[151][3]=1;
        exi[150][4]=1;
        exi[146][0]=1;
        exi[147][1]=1;
        exi[148][2]=1;
        exi[149][3]=1;
        n-=15;
    }
    else
    {
        if(n>=6)
        {
            exi[150][0]=1;
            exi[152][0]=1;
            exi[148][0]=1;
            exi[151][1]=1;
            exi[149][1]=1;
            exi[150][2]=1;
            n-=6;
        }
        else
        {
            exi[150][0]=1;
            n--;
        }
    }
    xx=x+150;
    yy=y;
    if(-100>x||x>100)
    {
        printf("0.0\n");
        return 2 ;
    }
    simulate(n);
    printf("%lf\n",(double)ti/(double)co);
}
int main()
{
    freopen("BBB.in","r",stdin);
    freopen("ou.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
}
