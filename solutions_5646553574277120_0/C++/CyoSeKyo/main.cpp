#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 1000000005
#define eps 1e-10
#define PI acos(-1.0)
#define LL long long

using namespace std;

int C, D, V;

int dp[35], val[35], ans, f[35];

int main()
{
    int T, cas = 0;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &C, &D, &V);
        for (int i = 1; i <= D; i++)
            scanf("%d", &val[i]);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= D; i++)
            for (int j = V; j >= val[i]; j--)
                if (dp[j - val[i]]) dp[j] = 1;
        int tag = 1;
        for (int i = 1; i <= V; i++)
            if (!dp[i]) tag = 0;
        if (tag) ans = 0;
        else
        {
            ans = 0;
            for (int i = 1; i <= V; i++)
                f[i] = dp[i];
            for (int i = 1; i <= V; i++)
                if (!f[i])
                {
                    ans++;
                    for (int j = V; j >= i; j--)
                        if (f[j - i]) f[j] = 1;
                }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
