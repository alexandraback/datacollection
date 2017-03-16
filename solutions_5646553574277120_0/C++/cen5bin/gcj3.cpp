#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int a[N];
int vv[N];
bool vis[N];

void dfs(int x, int sum, int n)
{
    vv[sum] = 1;
    if (x == n) return;
    for (int i = 0; i < n; ++i)
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(x+1, sum+a[i], n);
            vis[i] = 0;
        }
}

int main()
{
    freopen("in3.txt", "r", stdin);
    freopen("out3", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        int c, d, v;
        scanf("%d%d%d", &c, &d, &v);
        for (int i = 0; i < d; ++i) scanf("%d", &a[i]);
        //sort(a, a + d);
        //int ans = 0;
        //if (a[0] != 1) ans++;
        //int last = 1;
        //int low = 1;
        //for (int i = 0; i < d; ++i)
        //{
        //    if (a[i] - last * c > 1)
        //}
        memset(vv, 0, sizeof(vv));
        memset(vis, 0, sizeof(vis));
        dfs(0, 0, d);
        int ans = 0;
        for (int i = 1; i <= v; ++i)
            if (vv[i] == 0)
            {
                //printf("%d\n", i);
                ans++;
                vv[i] = 2;
                for (int j = 1; j <= v; ++j)
                    if (vv[j] == 1) 
                    {
                        if (vv[j+i] == 0)
                        vv[j+i] = 2;
                    }
                for (int j = 1; j <= v; ++j) if (vv[j]) vv[j] = 1;
            }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
