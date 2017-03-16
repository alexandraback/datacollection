#include <cstdio>
const int N=10000000;
int q[N],ans[N],pre[N];
int reverse(int x)
{
    int y=0;
    while (x)
    {
        y=y*10+x%10;
        x/=10;
    }
    return(y);
}
void init()
{
    int l,r;
    q[l=r=0]=1;
    ans[1]=1;
    while (l<=r)
    {
        int x=q[l++];
        if (x+1<N && ans[x+1]==0)
        {
            q[++r]=x+1;
            ans[x+1]=ans[x]+1;
            pre[x+1]=x;
        }
        int y=reverse(x);
        if (ans[y]==0)
        {
            q[++r]=y;
            ans[y]=ans[x]+1;
            pre[y]=x;
        }
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x;
        scanf("%d",&x);
        static int id=0;
        printf("Case #%d: %d\n",++id,ans[x]);
    }
}

