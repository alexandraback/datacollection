#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1000000+100;
typedef long long LL;
bool vis[20];

LL solve(LL n)
{
    memset(vis,0,sizeof(vis));
    int cnt = 10;
    for(int i = 1;;++i)
    {
        LL now = n*i;
        while(now)
        {
            int t = now%10;
            if(!vis[t])
            {
                vis[t] = 1;
                cnt--;
            }
            now /= 10;
        }
        if(cnt == 0) return n*i;
    }
}



int main()
{
    //freopen("./test.txt","r",stdin);
    freopen("./A-large.in","r",stdin);
    freopen("./out","w",stdout);
    int kase;
    scanf("%d",&kase);
    for(int z = 1;z <= kase;++z)
    {
        int n;
        scanf("%d",&n);
        if(n == 0)
            printf("Case #%d: INSOMNIA\n",z);
        else
            printf("Case #%d: %lld\n",z,solve(n));
    }
    return 0;
}
