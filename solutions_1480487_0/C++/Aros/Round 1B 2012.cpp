#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 200+5, MAXM = 255+5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int T, N, X, s[MAXN];
int r[MAXN];
bool vis[MAXN];
bool cmp(int a, int b)
{
    return s[a] < s[b];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d", &N);
        X = 0;
        for (int i = 1; i <= N; i++)
        {
            r[i] = i;
            scanf("%d", &s[i]);
            X += s[i];
        }
        sort(r+1, r+1+N, cmp);
        int x = X, n = 0;
        for (int j = 1; j <= N; j++)
        {
            vis[r[j]] = 1;
            x += s[r[j]];
            n++;
            if (j < N && (double)x/n < (double)s[r[j+1]])
                break;
        }
        printf("Case #%d:", cas);
        for (int i = 1; i <= N; i++)
        {
            if (vis[i])
                printf(" %.6lf", 100.0*((double)x/n-s[i])/X);
            else
                printf(" %.6lf", 0.0);
        }
        printf("\n");
    }
    return 0;
}
