#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct s
{
    int x,y;
};

s temp;

int incx[4]={0,1,0,-1};
int incy[4]={1,0,-1,0};
int ce[103][103],f[103][103];
double st[103][103];

class cmp
{
    public:
    bool operator()(const s& a,const s& b)
    {
        return st[a.x][a.y]>st[b.x][b.y];
    }
};

int main()
{
    freopen("b.txt","r",stdin);
    freopen("b.out","w",stdout);
    int test,cas,n,m,i,j,r,c,nr,nc;
    double h,curh,diff,cst;
    scanf("%d",&test);
    for (cas=1;cas<=test;cas++)
    {
        scanf("%lf%d%d",&h,&n,&m);
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++) scanf("%d",&ce[i][j]);
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++) scanf("%d",&f[i][j]);
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++) st[i][j]=1e18;
        }
        priority_queue<s, vector<s>, cmp> q;
        st[0][0]=0.0;
        temp.x=temp.y=0;
        q.push(temp);
        while (!q.empty())
        {
            r=q.top().x;
            c=q.top().y;
            q.pop();
            for (i=0;i<4;i++)
            {
                nr=r+incx[i];
                nc=c+incy[i];
                if (nr<0||nr>=n||nc<0||nc>=m) continue;
                if (ce[nr][nc]<f[nr][nc]+50) continue;
                if (ce[nr][nc]<f[r][c]+50) continue;
                if (ce[r][c]<f[nr][nc]+50) continue;
                if (st[r][c]==0.0&&h<=ce[nr][nc]-50)
                {
                    if (0.0<st[nr][nc])
                    {
                        st[nr][nc]=0.0;
                        temp.x=nr;
                        temp.y=nc;
                        q.push(temp);
                    }
                }
                else
                {
                    curh=h-st[r][c]*10.0;
                    diff=max(curh-ce[nr][nc]+50.0,0.0);
                    cst=diff/10.0;
                    curh-=cst*10.0;
                    if (curh-f[r][c]>=20.0&&st[r][c]+cst+1.0<st[nr][nc])
                    {
                        st[nr][nc]=st[r][c]+cst+1.0;
                        temp.x=nr;
                        temp.y=nc;
                        q.push(temp);
                    }
                    if (curh-f[r][c]<20.0&&st[r][c]+cst+10.0<st[nr][nc])
                    {
                        st[nr][nc]=st[r][c]+cst+10.0;
                        temp.x=nr;
                        temp.y=nc;
                        q.push(temp);
                    }
                }
            }
        }
        printf("Case #%d: %.10lf\n",cas,st[n-1][m-1]);
    }
    return 0;
}
