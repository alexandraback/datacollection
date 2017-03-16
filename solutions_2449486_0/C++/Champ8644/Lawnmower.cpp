#include<cstdio>
#include<queue>
using namespace std;
struct yo
{
    int x,y,c;
    bool operator< (const yo &r)const
    {
        return c>r.c;
    }
};
priority_queue<yo> P;
int bg[102][102];
int visit[102][102];
int n,m;
bool check1 (int x,int d)
{
    for (int i=1;i<=m;i++)
    {
        if (bg[x][i]>d)
            return false;
    }
    return true;
}
bool check2 (int y,int d)
{
    for (int i=1;i<=n;i++)
    {
        if (bg[i][y]>d)
            return false;
    }
    return true;
}
int main()
{
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("out_lawnmower.txt","w",stdout);
    yo temp;
    int tt,T,i,j,e,x,y,d;
    scanf("%d",&T);
    for (tt=1;tt<=T;tt++)
    {
        scanf("%d %d",&n,&m);
        while (!P.empty())
            P.pop();
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
            {
                scanf("%d",&bg[i][j]);
                visit[i][j] = 0;
                temp.x = i;
                temp.y = j;
                temp.c = bg[i][j];
                P.push(temp);
            }
        e = 1;
        while (!P.empty())
        {
            temp = P.top();
            P.pop();
            x = temp.x;
            y = temp.y;
            d = temp.c;
            if (visit[x][y]==1)
                continue;
            if (check1(x,d))
            {
                for (i=1;i<=m;i++)
                    visit[x][i] = 1;
            }
            else if (check2(y,d))
            {
                for (i=1;i<=n;i++)
                    visit[i][y] = 1;
            }
            else
            {
                e = 0;
                break;
            }
        }
        printf("Case #%d: ",tt);
        if (e==0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
