#include <iostream>
#include <cstdio>
using namespace std;
#define INF (-1)
int r, c, w;
int dfs(int i, int j)
{
    if (i <= j) return j;
    return 1+dfs(i-j, j);
}
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d %d %d", &r, &c, &w);
        printf("Case #%d: %d\n", cas, dfs(c, w)+(r-1)*c/w);
    }
    return 0;
}
