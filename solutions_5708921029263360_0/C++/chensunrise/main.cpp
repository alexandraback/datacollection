#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn = 1000 + 10;

using namespace std;

bool vis[30],tp[30];
int  usd[340];
int A[30],B[30],C[30],n,K,ans;

void dfs(int x,int num)
{
    if (x>n)
    {
        if (ans<num)
        {
            ans = num;
            for (int i=1;i<=n;i++) vis[i]=tp[i];
            return;
        }
        return;
    }
    if (num + (n-x+1)<=ans) return;
    int x1 = A[x]*100+C[x];
    int x2 = A[x]*100+B[x]*10;
    int x3 = B[x]*10+C[x];
    if (usd[x1]<K && usd[x2]<K  && usd[x3]<K)
    {
        usd[x1]++; usd[x2]++; usd[x3]++; tp[x]=1;
        dfs(x+1,num+1);
        usd[x1]--; usd[x2]--; usd[x3]--; tp[x]=0;
    }
    dfs(x+1,num);

}

void output()
{
    printf(" %d\n",ans);
    for (int i=1;i<=n;i++) if (vis[i]) printf("%d %d %d\n",A[i],B[i],C[i]);
}

void work()
{
    int J ,P ,S;
    n=0;
    scanf("%d%d%d%d",&J,&P,&S,&K);
    for (int i=1;i<=J;i++)
        for (int j=1;j<=P;j++)
            for (int k=1;k<=S;k++)
                {
                    n++;
                    A[n]=i; B[n]=j; C[n]=k;
                }
    ans = 0;
    memset(usd,0,sizeof usd);
    memset(vis,0,sizeof vis);
    memset(tp,0,sizeof tp);
    dfs(1,0);
    output();
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T, cas = 0 ;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case #%d:",++cas);
        work();
    }
    return 0;
}
