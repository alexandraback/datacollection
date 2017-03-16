#include <stdio.h>

typedef struct
{
    long long num;
    int type;
}Goods;

Goods a[105];
Goods b[105];
int n,m;
long long ans;

void DFS(int x,int y,long long sum)
{
    int i,j;
    long long s;
  //  printf("%d %d %lld %lld %lld\n",x,y,sum,a[x].num,b[y].num);
    if (x==n || y==m)
    {
        if (sum>ans) ans=sum;
        return;
    }
    s=0;
    if (a[x].type==b[y].type)
    {
        if (a[x].num>=b[y].num)
        {
            s=b[y].num;
            a[x].num-=s;
            DFS(x,y+1,sum+s);
            a[x].num+=s;
        }
        else
        {
            s=a[x].num;
            b[y].num-=s;
            DFS(x+1,y,sum+s);
            b[y].num+=s;
        }
    }
    else
    {
        DFS(x+1,y,sum);
        DFS(x,y+1,sum);
    }
}

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int i,j,T,cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
        {
            scanf("%lld%d",&a[i].num,&a[i].type);
        }
        for (i=0;i<m;i++)
        {
            scanf("%lld%d",&b[i].num,&b[i].type);
        }
        ans=0;
        DFS(0,0,0);
        printf("Case #%d: %lld\n",cnt++,ans);
    }
    return 0;
}
