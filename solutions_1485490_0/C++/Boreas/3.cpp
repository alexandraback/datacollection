#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
ll tot1[300], tot2[300], s1[300], s2[300], fin;
int n,m;

void dfs(int i, ll irst, int j, ll jrst, ll ans)
{
    if (i > n || j > m)
    {
        fin = max(fin, ans);
        return;
    }
    if (s1[i] == s2[j])
    {
        if (irst < jrst)
            dfs(i + 1, tot1[i + 1], j, jrst - irst, ans + irst);
        else
            dfs(i, irst - jrst, j + 1, tot2[j + 1], ans + jrst);
        return;
    }
    dfs(i + 1, tot1[i + 1], j, jrst, ans);
    dfs(i, irst, j + 1, tot2[j + 1], ans);
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int Cas,cas;
    scanf("%d",&Cas);
    for (int cas=0; cas<Cas; cas++)
    {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%lld %lld", &tot1[i], &s1[i]);

        for (int i = 1; i <= m; i++)
            scanf("%lld %lld", &tot2[i], &s2[i]);
        fin = 0;
        dfs(1, tot1[1], 1, tot2[1], 0);
        printf("Case #%d: %lld\n", cas+1, fin);
    }
    return 0;
}
