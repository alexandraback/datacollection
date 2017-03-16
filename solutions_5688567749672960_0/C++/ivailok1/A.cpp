#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int OFFSET = 5;
const int MAXN = 1000000 + OFFSET;

int T, N;
int dp[MAXN];

int GetReverse(int n)
{
    int curr = n, reversed = 0;
    while (curr != 0)
    {
        reversed = 10 * reversed + curr % 10;
        curr /= 10;
    }
    return reversed;
}

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small.out", "w", stdout);

    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d", &N);

        memset(dp, 0x3F, sizeof(dp));

        dp[1] = 1;
        for (int i = 1; i < N; i++)
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            int r = GetReverse(i);

            //cout << i << " " << r << endl;
            if (r <= N)
            {
                dp[r] = min(dp[r], dp[i] + 1);
            }
        }

        printf("Case #%d: %d\n", t, dp[N]);
    }
    return 0;
}
