#include <cstdio>
#include <algorithm>
using namespace std;

int n, x, y;
double dp[5000][5000];
int main()
{
    int mt; scanf("%d", &mt);
    for(int t = 1; t <= mt; t++)
    {
        scanf("%d %d %d", &n, &x, &y);
        int level = (abs(x) + y) / 2;
        n -= level * (2 * level - 1);
        double ans;
        if(n < 0) 
            ans = 0.0;
        else if(n >= 4 * level + 1)
            ans = 1.0;
        else if(x == 0)
            ans = 0.0;
        else
        {
            int slen = 2 * level;
            int spos = y + 1;
            for(int i = 0; i <= slen; i++)
                for(int j = 0; j <= slen; j++)
                    dp[i][j] = 0.0;
            dp[0][0] = 1.0;
            for(int s = 0; s < 2 * slen; s++)
                for(int i = max(0, s - slen); i <= s; i++)
                {
                    int j = s - i;
                    if(j < 0)
                        break;
                    if(i == slen)
                        dp[i][j + 1] += dp[i][j];
                    else if(j == slen)
                        dp[i + 1][j] += dp[i][j];
                    else
                    {
                        dp[i][j + 1] += 0.5 * dp[i][j];
                        dp[i + 1][j] += 0.5 * dp[i][j];
                    }
                }
            ans = 0.0;
            for(int i = 0; i <= slen; i++)
                for(int j = 0; j <= slen; j++)
                    if(i + j == n && j >= spos)
                        ans += dp[i][j];
        }
        printf("Case #%d: %.12f\n", t, ans);
    }
    return 0;
}
