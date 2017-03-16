#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

#define INF (1<<30)
#define mod 666013

using namespace std;

int t, cs;

int solve()
{
    int c, n, m, i, j, sol;
    int v[35] = {0}, f[35] = {0};
    scanf("%d%d%d", &c, &n, &m);
    for(i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    f[0] = 1;
    for(i = 1; i <= n; i++)
    {
        for(j = m; j >= v[i]; j--)
            if(f[j - v[i]] == 1)
                f[j] = 1;
    }

    sol = 0;
    while(1)
    {
        for(i = 1; i <= m; i++)
            if(f[i] == 0)
                break;
        if(i > m)
            return sol;

        sol++;
        for(j = m; j >= i; j--)
            if(f[j - i] == 1)
                f[j] = 1;
    }
    return -1;
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        cs++;
        printf("Case #%d: ", cs);

        printf("%d\n", solve());
    }
    return 0;
}
