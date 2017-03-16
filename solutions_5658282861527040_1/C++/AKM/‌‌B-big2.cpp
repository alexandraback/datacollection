#include <iostream>
#include <memory.h>

using namespace std;

#define MAXP 31
int a, b, k;
long long dp[MAXP + 10][3][3][3];
bool mark[MAXP + 10][3][3][3];
long long calculate(int n, bool sA, bool sB, bool sK)
{
    if (n == MAXP)
        return !sA && !sB && !sK;
    if (!mark[n][sA][sB][sK])
    {
        //cout << n << " " << sA << " " << sB << " " << sK << endl;
        mark[n][sA][sB][sK] = true;
        dp[n][sA][sB][sK] = 0;
        if (sK || ((1 << n) & k) == 0)
        {
            if (sA && ((1 << n) & a))
            {
                if (sB)
                {
                    if ((1 << n) & b)
                    {
                        if (sK && ((1 << n) & k))
                        {
                            dp[n][sA][sB][sK] += calculate(n + 1, false, false, false);
                            dp[n][sA][sB][sK] += 2 * calculate(n + 1, true, false, false);
                        }
                        dp[n][sA][sB][sK] += calculate(n + 1, false, false, sK);
                        dp[n][sA][sB][sK] += 2 * calculate(n + 1, true, false, sK);
                    }
                    if (sK && ((1 << n) & k))
                        dp[n][sA][sB][sK] += 2 * calculate(n + 1, false, true, false);
                    dp[n][sA][sB][sK] += 2 * calculate(n + 1, false, true, sK);
                }
                else
                {
                    if (sK && ((1 << n) & k))
                        dp[n][sA][sB][sK] += calculate(n + 1, false, false, false);
                    dp[n][sA][sB][sK] += calculate(n + 1, false, false, sK);
                }
            }
            else if (sB)
                if ((1 << n) & b)
                {
                    if (sK && ((1 << n) & k))
                        dp[n][sA][sB][sK] += (sA + 1) * calculate(n + 1, sA, false, false);
                    dp[n][sA][sB][sK] += (sA + 1) * calculate(n + 1, sA, false, sK);
                }
        }
        for (int i = 0; i < 2; i++)
        {
            if (!sA && ((1 << n) & a) != (i << n))
                continue;
            for (int j = 0; j < 2; j++)
            {
                if (!sB && ((1 << n) & b) != (j << n))
                    continue;
                if (!sK && ((1 << n) & k) != ((i & j) << n))
                    continue;
                if (sK && ((1 << n) & k) && (i & j) == 0)
                    dp[n][sA][sB][sK] += calculate(n + 1, sA, sB, false);
                dp[n][sA][sB][sK] += calculate(n + 1, sA, sB, sK);
            }
        }

    }
    return dp[n][sA][sB][sK];

}
int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        cin >> a >> b >> k;
        memset(mark, false, sizeof mark);
        cout << "Case #" << tc << ": " << calculate(0, true, true, true) << endl;
    }
}
