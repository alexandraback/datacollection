#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct state
{
    int num,x,y;
    state(){}
    state(int num,int x,int y):num(num),x(x),y(y){}
};
inline bool operator <(const state &a,const state &b)
{
    return(a.num>b.num);
}
state c[10010];
int b[110],d[110],a[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,tot=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                c[++tot]=state(a[i][j],i,j);
            }
        sort(c+1,c+tot+1);
        bool flag=true;
        memset(b,-1,sizeof(b));
        memset(d,-1,sizeof(d));
        for (int i=1;i<=n*m;i++)
        {
            int x=c[i].x,y=c[i].y;
            if (c[i].num<b[x] && c[i].num<d[y])
            {
                flag=false;
                break;
            }
            b[x]=max(b[x],c[i].num);
            d[y]=max(d[y],c[i].num);
        }
        static int id=0;
        printf("Case #%d: %s\n",++id,flag?"YES":"NO");
    }
    return(0);
}

