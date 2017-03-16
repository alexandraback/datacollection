#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[20],b[20];
bool lin[20][20];
char te[100],ans[100];
int n,m,now;
bool f;
bool exam(int s)
{
    for(int i=0;i<s;i++)
        if(ans[i]>te[i])return 1;
        else if(ans[i]<te[i])return 0;
    return 0;
}
void dfs(int s)
{
    if(now==n)
    {
        for(int i=0;i<n;i++)
        {
            int pp=a[b[i]];
            for(int j=0;j<5;j++)
                te[i*5+4-j]=pp%10+'0',pp/=10;
        }
        te[n*5]=0;
        if(f==0||exam(n*5))
        {
            f=1;
            for(int i=0;i<n*5;i++)
                ans[i]=te[i];
            ans[n*5]=0;
        }
    }
    else
    {
        for(int i=0;i<n;i++)
            if(lin[s][i])
            {
                if(i==b[now])
                {
                    now++;
                    dfs(i);
                    i=0;
                }
            }
    }
}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int x,y;
        memset(lin,0,sizeof(lin));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int i=0;i<m;i++)
            scanf("%d%d",&x,&y),lin[x-1][y-1]=lin[y-1][x-1]=1;
        for(int i=0;i<n;i++)b[i]=i;
        f=0;
        do
        {
            now=1;dfs(b[0]);
        }while(next_permutation(b,b+n));
        printf("Case #%d: %s\n",ti++,ans);
    }
    return 0;
}
