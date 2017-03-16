#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

const int NN = 105;

int mark[NN];
int dd[NN];
int f[NN];
int dp(int n, int v)
{
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = v; j >= dd[i]; j--)
            f[j] |= f[j - dd[i]];
    for (int i = 1; i <= v; i++)
        if (f[i] == 0)
            return 0;
    return 1;
}

int ans;
void dfs(int step, int before, int d, int v)
{
    if (step >= ans) return;
    if (dp(d + step, v) == 1)
    {
        ans = step;
        return ;
    }
    for (int i = before + 1; i <= 16; i++)
        if (mark[i] == 0)
        {
            dd[step + d + 1] = i;
            dfs(step + 1, i, d, v);
        }
}

int main()
{
   // freopen("1.txt", "r", stdin);

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        int c, d, v;
        cin >> c >> d >> v;

        memset(mark, 0, sizeof(mark));
        for (int i = 1; i <= d; i++)
        {
            scanf("%d", &dd[i]);
            mark[dd[i]] = 1;
        }

        ans = 8;
        dfs(0, 0, d, v);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
