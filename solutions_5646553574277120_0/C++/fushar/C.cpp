#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

int T;
int C, D, V;
int curMask;

int ANS;

bool dp[31];

bool can(int mask)
{
    bool newdp[32] = {};
    REP(i, V+1)
        newdp[i] = dp[i];

    REP(i, V+1)
        if (mask & (1<<i))
        {
            for (int j = V; j >= i; j--)
                newdp[j] |= newdp[j-i];
        }

    REP(i, V+1)
        if (!newdp[i])
            return false;
    return true;
}

void go(int denom, int mask)
{
    if (denom > V+1 || __builtin_popcount(mask) > 5)
        return;

    if (can(mask))
        ANS = min(ANS, __builtin_popcount(mask));

    go(denom+1, mask);

    if (! ( curMask & (1<<denom)))
        go(denom+1, mask | (1<<denom));
}

int main()
{
    scanf("%d", &T);

    REP(tc, T)
    {
        scanf("%d %d %d", &C, &D, &V);

        memset(dp, false, sizeof dp);
        dp[0] = true;

        curMask = 0;
        REP(i, D)
        {
            int d;
            scanf("%d", &d);
            curMask |= 1<<d;

            for (int j = V; j >= d; j--)
                dp[j] |= dp[j-d];
        }

        ANS = 999999;
        go(1, 0);

        printf("Case #%d: %d\n", tc+1, ANS);
    }
}
