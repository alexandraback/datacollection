#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 200+5, MAXM = (1<<20)+5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int T, N, s[MAXN];
int sum[MAXM], SUM, C;
vector<int> V[20*100000+5];
void dfs(int x)
{
    if (x == N)
    {
        sum[C] = SUM;
        V[SUM].push_back(C);
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        C += (1<<x)*i;
        SUM += s[x+1]*i;
        dfs(x+1);
        SUM -= s[x+1]*i;
        C -= (1<<x)*i;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &s[i]);
        SUM = 0; C = 0;
        for (int i = 1; i <= 20*100000; i++)
            V[i].clear();
        dfs(0);
        int ans = 0;
        for (int i = 1; i <= 20*100000; i++)
        {
            if (V[i].size() > 1)
            {
                ans = i;
//                printf("%u\n", V[i].size());
                break;
            }
        }
        printf("Case #%d:\n", cas);
        for (int i = 0; i < N; i++)
        {
            if (V[ans][0]&(1<<i))
                printf("%d ", s[i+1]);
        }
        printf("\n");
        for (int i = 0; i < N; i++)
        {
            if (V[ans][1]&(1<<i))
                printf("%d ", s[i+1]);
        }
        printf("\n");
    }
    return 0;
}
