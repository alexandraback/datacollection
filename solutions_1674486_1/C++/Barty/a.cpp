#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge
{
    int v, next;
}e[100010];
int p[1010], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    p[x] = eid++;
}
int vst[1010];
bool dfs(int v)
{
    vst[v]++;
    if (vst[v] >= 2) return true;
    for (int i = p[v]; i != -1; i = e[i].next)
        if (dfs(e[i].v)) return true;
    return false;
}
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int T, n;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca)
    {
        scanf("%d", &n);
        mapinit();
        for (int i = 1; i <= n; ++i)
        {
            int k, x; scanf("%d", &k);
            while (k--)
            {
                scanf("%d", &x);
                insert(i, x);
            }
        }
        bool  flag = false;
        for (int i = 1; i <= n; ++i)
        {
            memset(vst, 0, sizeof(vst));
            if (dfs(i)) flag = true;
        }
        printf("Case #%d: ", ca);
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
