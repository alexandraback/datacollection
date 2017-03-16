#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
#define two(i) (1<<(i))
int dp[two(20)],pre[two(20)],a[25],b[25][205],use[205],id[205],N;
int have[25][205],ax[205],ini[205];
int check(int s, int k)
{
    for(int i = 0; i < N; i++)
    {
        ax[i] = ini[i];
        //printf("s=%d ax[%d]=%d\n",s,i,ax[i]);
    }
    for(int i = 0; i < n; i++)
        if(two(i)&s)
        {
            ax[id[a[i]]]--;
            for(int j = 0; j < N; j++)
                ax[j]+=have[i][j];
        }
    if(ax[id[a[k]]] > 0)return 1;
    return 0;
}

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D.out","w",stdout);
    int T,m,x,K,cas=0;scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&K,&n);
        memset(b,0,sizeof(b));
        memset(use,0,sizeof(use));
        memset(have,0,sizeof(have));
        memset(ax,0,sizeof(ax));
        memset(ini,0,sizeof(ini));
        N = 0;
        for(int i = 0; i < K; i++)
            scanf("%d",&ax[i]),use[ax[i]]=1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&a[i],&m);
            for(int j = 0; j < m; j++)
            {
                scanf("%d",&x);
                b[i][x]++;
                use[x] = 1;
            }
        }
        for(int i = 0; i <= 200; i++)
            if(use[i])
            {
                //printf("%d=%d\n",i,N);
                id[i] = N++;
            }
        for(int i = 0; i < K; i++)
            ini[id[ax[i]]]++;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= 200; j++)
                if(b[i][j])
                    have[i][id[j]] = b[i][j];

        memset(dp,0,sizeof(dp));
        for(int i = 0; i < two(n); i++)
            pre[i] = n;
        dp[two(n)-1] = 1;
        for(int i = two(n)-1; i >= 0; i--)if(dp[i])
        {
            //printf("%d:\n",i);
            for(int j = 0; j < n; j++)
                if(two(j)&i)
                {
                    if(!check(i^two(j),j))continue;
                    //printf("%d\n",j);
                    dp[two(j)^i] = 1;
                    pre[two(j)^i] = min(pre[two(j)^i],j);
                }
        }
        printf("Case #%d:",++cas);
        if(dp[0]==0)
            printf(" IMPOSSIBLE\n");
        else
        {
            int s = 0;
            for(int i = 0; i < n; i++)
            {
                printf(" %d",pre[s]+1);
                s ^= two(pre[s]);
            }
            puts("");
        }
    }

    return 0;
}
