#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int E, R, N;
int v[100];
int ans;

void dfs(int energy, int gain, int depth)
{
    if (depth >= N)
    {
        ans = max(ans, gain);
        return;
    }
    for (int i = 0; i <= energy; ++i)
    {
        dfs(min(E, energy - i + R), gain + v[depth] * i, depth + 1);
    }
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%d%d", &E, &R, &N);
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &v[i]);
        }
        ans = 0;
        dfs(E, 0, 0);
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
