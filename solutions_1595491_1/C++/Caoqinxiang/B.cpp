#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int t, n, s, p, a[1000];
int dp[200][200];

void refresh(int & x, int y)
{
    if (x <= y)
        x = y;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d", & t);
    for (int ii = 1; ii <= t; ++ ii)
    {
        scanf("%d %d %d", & n , & s, & p);
        for (int i = 0; i < n; ++ i)
            scanf("%d", a + i);
        
        for (int i = 1; i <= n; ++ i)
            for (int j = 0; j <= i; ++ j)
                dp[i][j] = -100000;
        
        dp[0][0] = 0;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j <= i; ++ j)
                if (a[i] == 0)
                    refresh(dp[i + 1][j], dp[i][j] + (p == 0));
                else if (a[i] == 1)
                    refresh(dp[i + 1][j], dp[i][j] + (p <= 1));
                else if (a[i] >= 29)
                    refresh(dp[i + 1][j], dp[i][j] + 1);
                else if (a[i] % 3 == 0)
                {
                    refresh(dp[i + 1][j], dp[i][j] + (p <= a[i]/3));
                    refresh(dp[i + 1][j + 1], dp[i][j] + (p <= 1 + a[i]/3));
                }
                else if (a[i] % 3 == 1)
                {
                    refresh(dp[i + 1][j], dp[i][j] + (p <= 1 + a[i]/3));
                    refresh(dp[i + 1][j + 1], dp[i][j] + (p <= 1 + a[i]/3));
                }
                else if (a[i] % 3 == 2)
                {
                    refresh(dp[i + 1][j], dp[i][j] + (p <= 1 + a[i]/3));
                    refresh(dp[i + 1][j + 1], dp[i][j] + (p <= 2 + a[i]/3));
                }
        
        printf("Case #%d: %d\n", ii, dp[n][s]);
    }

//    fclose(stdout);
}


