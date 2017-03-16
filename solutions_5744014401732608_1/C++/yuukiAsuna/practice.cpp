#include <bits/stdc++.h>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>  P;
const int N = 55,MOD = 7+1e9;
int G[N][N];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while(T --)
    {
        int n;
        LL m;
        scanf("%d%lld", &n, &m);
        LL MAX = 1LL<<(n-2);
        printf("Case #%d: ", ++ca);
        if(m > MAX)
        {
            puts("IMPOSSIBLE");
            continue;
        }
        memset(G, 0, sizeof G);
        puts("POSSIBLE");
        m --, G[1][n] = 1;
        for(int i = 1;i <= n;i ++)
        {
            for(int j = i + 1;j < n;j ++) G[i][j] = 1;
        }
        for(int i = 2;i < n;i ++)
        {
            if((m&1LL) != 0)
            {
                G[i][n] = 1;
            }
            m >>= 1;
        }
        for(int i = 1;i <= n;i ++)
        {
            for(int j = 1;j <= n;j ++) printf("%d", G[i][j]);
            printf("\n");
        }
    }
    return 0;
}