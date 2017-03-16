#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int A, B, lowest;
long long dp[33][2][2];
int vis[33][2][2];

long long dfs(int dep, int state1, int state2, int mask)
{
    if (dep<0)
    {
        if (!state1 && !state2)
        {
            return 1;
        }
        return 0;
    }

    if (dep < lowest)
    {
        long long ret1,ret2;

        if (state1)
        {
            ret1 = (A & ((1 << lowest) - 1));
        }
        else
        {
            ret1 = (1 << lowest);
        }
        if (state2)
        {
            ret2 = (B & ((1 << lowest) - 1));
        }
        else
        {
            ret2 = (1 << lowest);
        }
        return ret1 * ret2;
    }

    if (vis[dep][state1][state2])
    {
        return dp[dep][state1][state2];
    }
    vis[dep][state1][state2]=1;
    dp[dep][state1][state2]=0;

    if (mask & (1 << dep))
    {
        if (state1 && (A & (1 << dep)) == 0)
        {
            return 0;
        }
        if (state2 && (B & (1 << dep)) == 0)
        {
            return 0;
        }
        dp[dep][state1][state2] += dfs(dep - 1, state1, state2, mask);
    }
    else
    {
        if (!state1 || (A & (1 << dep)))
        {
            int s1, s2;
            if (!state2)
            {
                s2 = 0;
            }
            else if (B & (1 << dep))
            {
                s2 = 0;
            }
            else
            {
                s2 = 1;
            }
            dp[dep][state1][state2] += dfs(dep - 1, state1, s2, mask);
        }
        if (!state2 || (B & (1 << dep)))
        {
            int s1;
            if (!state1)
            {
                s1 = 0;
            }
            else if (A & (1 << dep))
            {
                s1 = 0;
            }
            else
            {
                s1 = 1;
            }
            dp[dep][state1][state2] += dfs(dep - 1, s1, state2, mask);
        }
        int s1, s2;
        if (!state1 || (A & (1 << dep)))
        {
            s1 = 0;
        }
        else
        {
            s1 = 1;
        }
        if (!state2 || (B & (1 << dep)))
        {
            s2 = 0;
        }
        else
        {
            s2 = 1;
        }
        dp[dep][state1][state2] += dfs(dep - 1, s1, s2, mask);
    }
    return dp[dep][state1][state2];
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);

        long long ans = 0;
        A = a, B = b;

        for (int i = 0; i < 30; i++)
        {
            if (k & (1 << i))
            {
                int mask = 0;
                for (int j = i + 1; j < 30; j++)
                {
                    if (k & (1 << j))
                    {
                        mask += (1 << j);
                    }
                }
                memset(vis, 0, sizeof(vis));
                lowest = i;
                ans += dfs(30, 1, 1, mask);
            }
        }
        cout << "Case #" << cases << ": " << ans << "\n";
    }
    return 0;
}
