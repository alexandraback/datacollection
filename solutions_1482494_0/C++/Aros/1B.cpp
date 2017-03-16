#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 1000+5, MAXM = 12*16+5;
const int INF = 0x3f3f3f3f;
int T, N, a[MAXN], b[MAXN];
bool vis[MAXN][2];
struct Node
{
    int a, b;
} lv[MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d%d", &lv[i].a, &lv[i].b);
        int star = 0, ans = 0;
        bool flag = 1;
        while (flag)
        {
            flag = 0;
            for (int i = 1; i <= N && !flag; i++)
                if (star >= lv[i].b && !vis[i][0] && !vis[i][1])
                {
                    vis[i][1] = 1;
                    star += 2;
                    ans++;
                    flag = 1;
                }
            for (int i = 1; i <= N && !flag; i++)
                if (star >= lv[i].b && vis[i][0] && !vis[i][1])
                {
                    vis[i][1] = 1;
                    star += 1;
                    ans++;
                    flag = 1;
                }
            for (int i = 1; i <= N && !flag; i++)
                if (star >= lv[i].a && !vis[i][0] && !vis[i][1])
                {
                    vis[i][0] = 1;
                    star += 1;
                    ans++;
                    flag = 1;
                }
        }
        flag = 1;
        for (int i = 1; i <= N; i++)
            if (!vis[i][1])
            {
                flag = 0;
                break;
            }
        if (flag)
            printf("Case #%d: %d\n", cas, ans);
        else
            printf("Case #%d: Too Bad\n", cas);
    }
    return 0;
}
