#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = (1 << 10);
int dp[MAXN][MAXN];

int r, c, w;

int dfs(int mask, int subMask)
{
    if (dp[mask][subMask] != INT_MAX / 2)
    {
        return dp[mask][subMask];
    }
//     printf("%d\n", __builtin_popcount((~mask) & ((1 << c) - 1)));
    if (__builtin_popcount((~mask) & ((1 << c) - 1)) + __builtin_popcount(subMask) < w)
    {
        dp[mask][subMask] = INT_MIN / 2;
        return dp[mask][subMask];
    }
    
    if (((~mask) & subMask) != 0)
    {
        dp[mask][subMask] = INT_MIN / 2;
        return dp[mask][subMask];
    }
    
    int minBitInSubMask = c - 1;
    int maxBitInSubMask = 0;
    
    for (int i = 0; i < c; ++i)
    {
        if ((subMask >> i) & 1)
        {
            minBitInSubMask = min(minBitInSubMask, i);
            maxBitInSubMask = i;
        }
    }
    if (subMask && maxBitInSubMask - minBitInSubMask + 1 > w)
    {
        dp[mask][subMask] = INT_MIN / 2;
        return dp[mask][subMask];
    }
    else
    {
//         printf("%d %d %d %d %d\n", mask, subMask, maxBitInSubMask, minBitInSubMask, w);
        if (subMask && maxBitInSubMask - minBitInSubMask + 1 == w)
        {
            for (int i = minBitInSubMask; i <= maxBitInSubMask; ++i)
            {
                if (((mask >> i) & 1) && !((subMask >> i) & 1))
                {
                    dp[mask][subMask] = INT_MIN / 2;
                    return dp[mask][subMask];
                }
            }
            dp[mask][subMask] = __builtin_popcount(((~mask) & ((1 << c) - 1)) & (((1 << (maxBitInSubMask - minBitInSubMask + 1)) - 1) << minBitInSubMask));
            return dp[mask][subMask];
        }
        int current = INT_MAX / 2;
        for (int i = 0; i < c; ++i)
        {
            if (!((mask >> i) & 1))
            {
                current = min(current, max(dfs(mask | (1 << i), subMask | (1 << i)) + 1, dfs(mask | (1 << i), subMask) + 1));
            }
        }
        dp[mask][subMask] = current;
    }
    return dp[mask][subMask];
}


int main()
{
    int T;
    scanf("%d", &T);
    for (int z = 1; z <= T; ++z)
    {
        printf("Case #%d: ", z);
        scanf("%d %d %d", &r, &c, &w);
        for (int i = 0; i < (1 << c); ++i)
            for (int j = 0; j < (1 << c); ++j)
                dp[i][j] = INT_MAX / 2;
        printf("%d\n", dfs(0, 0));
//         for (int i = 0; i < (1 << c); ++i)
//         {
//             for (int j = 0; j < (1 << c); ++j)
//             {
//                 printf("%d\t", dp[i][j]);
//             }
//             printf("\n");
//         }
    }
    
    return 0;
}