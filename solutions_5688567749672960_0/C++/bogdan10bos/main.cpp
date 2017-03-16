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
int i, j, o, t, cs, x, dp[1000005];

vector <int> v[1000005];

int rev_erse(int n)
{
    int x = 0;
    while(n)
    {
        x = x * 10 + n % 10;
        n /= 10;
    }
    return x;
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    for(i = 1; i <= 1000000; i++)
    {
        x = rev_erse(i);
        v[x].push_back(i);
    }
    dp[1] = 1;
    dp[0] = INF;
    for(i = 2; i <= 1000000; i++)
        dp[i] = INF;
    for(o = 1; o <= 50; o++)
        for(i = 2; i <= 1000000; i++)
        {
            dp[i] = min(dp[i], dp[i - 1] + 1);

            for(j = 0; j < v[i].size(); j++)
                dp[i] = min(dp[i], dp[ v[i][j] ] + 1);
        }

    scanf("%d", &t);
    for(cs = 1; cs <= t; cs++)
    {
        scanf("%d", &x);
        printf("Case #%d: %d\n", cs, dp[x]);
    }
    return 0;
}
