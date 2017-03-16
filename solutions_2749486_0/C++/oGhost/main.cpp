#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define dx 1111
#define dy 1111

struct data
{
    int x,y,step;
};

data a[1111111];

int map[3111][3111];
int pre[3111][3111],n;
char ans[111111];

void bfs(int x,int y)
{
    int head=-1,tail=0,size=1111110,step,sx,sy;
    a[0].x=a[0].y=0;
    a[0].step=0;

    while(head!=tail)
    {
        head=(head+1) % size;
        step=a[head].step+1;
        sx=a[head].x;
        sy=a[head].y;

        if(dx+sx+step>=0 && dx+sx+step<=3000 && sy+dy>=0 && sy+dy<=3000 && map[dx+sx+step][sy+dy]==0)
        {
            map[dx+sx+step][sy+dy]=step;
            pre[dx+sx+step][sy+dy]=0;
            tail=(tail+1) % size;
            a[tail].step=step;
            a[tail].x=sx+step;
            a[tail].y=sy;
            if(x==a[tail].x && y==a[tail].y)
                return;
        }
        if(dx+sx-step>=0 && dx+sx-step<=3000 && sy+dy>=0 && sy+dy<=3000 && map[dx+sx-step][sy+dy]==0)
        {
            map[dx+sx-step][sy+dy]=step;
            pre[dx+sx-step][sy+dy]=1;

            tail=(tail+1) % size;
            a[tail].step=step;
            a[tail].x=sx-step;
            a[tail].y=sy;
            if(x==a[tail].x && y==a[tail].y)
                return;

        }
        if(dx+sx>=0 && dx+sx<=3000 && sy+dy+step>=0 && sy+dy+step<=3000 && map[sx+dx][dy+step+sy]==0)
        {
            map[sx+dx][sy+step+dy]=step;
            pre[sx+dx][sy+step+dy]=2;

            tail=(tail+1) % size;
            a[tail].step=step;
            a[tail].x=sx;
            a[tail].y=sy+step;
            if(x==a[tail].x && y==a[tail].y)
                return;

        }
        if(dx+sx>=0 && dx+sx<=3000 && sy+dy-step>=0 && sy+dy-step<=3000 && map[sx+dx][sy+dy-step]==0)
        {
            map[sx+dx][sy+dy-step]=step;
            pre[sx+dx][sy+dy-step]=3;
            tail=(tail+1) % size;
            a[tail].step=step;
            a[tail].x=sx;
            a[tail].y=sy-step;
            if(x==a[tail].x && y==a[tail].y)
                return;
        }
    }

}

void print(int x,int y,int s)
{
    if(x==dx && y==dy)
    {
        n=s;
    }
    else
    {
        if(pre[x][y]==0)
        {
            ans[s]='E';
            print(x-map[x][y],y,s+1);
        }
        if(pre[x][y]==1)
        {
            ans[s]='W';
            print(x+map[x][y],y,s+1);
        }
        if(pre[x][y]==2)
        {
            ans[s]='N';
            print(x,y-map[x][y],s+1);
        }
        if(pre[x][y]==3)
        {
            ans[s]='S';
            print(x,y+map[x][y],s+1);
        }
    }
}

int main()
{
    int cases,o,stx,sty;
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&cases);
    for(o=1;o<=cases;o++)
    {
        memset(map,0,sizeof(map));
        memset(pre,0,sizeof(pre));
        scanf("%d%d",&stx,&sty);

        //printf("%d: %d %d\n",o,stx,sty);
        bfs(stx,sty);
        n=0;
        print(stx+dx,sty+dy,0);
        printf("Case #%d: ",o);
        for(int i=n-1;i>=0;i--)
            printf("%c",ans[i]);
        printf("\n");
    }
}
