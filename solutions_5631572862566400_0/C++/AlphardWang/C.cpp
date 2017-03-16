#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int e[1200];
int maxd[1200];
int vis[1200];
bool used[1200];
bool used2[1200];
int main()
{
    int cases;
    scanf("%d", &cases);
    for (int c = 1; c <= cases; ++c)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &e[i]);
        }
        
        memset(maxd, 0, sizeof(maxd));
        for (int start = 1; start <= n; ++start)
        {
            memset(vis, 0, sizeof(vis));
            int cnt = 1, next = e[start];
            vis[start] = cnt;
            while (vis[next] == 0)
            {
                vis[next] = ++cnt;
                next = e[next];
            }

            if (maxd[next] < vis[next] - 1) maxd[next] = vis[next] - 1;
        }

        int maxc = 0;
        int maxc2 = 0;

        memset(used, 0, sizeof(used));
        memset(used2, 0, sizeof(used2));
        for (int start = 1; start <= n; ++start)
        {
            if (used[start])
            {
                continue;
            }

            used[start] = true;
            memset(vis, 0, sizeof(vis));
            int cnt = 1, next = e[start];
            vis[start] = cnt;
            while (vis[next] == 0)
            {
                used[next] = true;
                vis[next] = ++cnt;
                next = e[next];
            }

            if (cnt - vis[next] == 1)
            {
                if (!used2[next])
                {
                    maxc2 += maxd[next] + maxd[e[next]] + 2;
                    used2[next] = true;
                    used2[e[next]] = true;
                }
            }
            else
            {
                if (maxc < cnt - vis[next] + 1) maxc = cnt - vis[next] + 1;
            }
        }

        if (maxc < maxc2) maxc = maxc2;

        printf("Case #%d: %d\n", c, maxc);
    }
}
