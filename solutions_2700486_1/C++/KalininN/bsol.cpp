#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int maxn = 2e3 + 4;

long double ans[maxn][maxn];
int n;
int X, Y;

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        long double answer = 0;
        
        scanf("%d%d%d", &n, &X, &Y);
        X = abs(X);
        int lvl = (X + Y) / 2;
        int h = Y;
        
        int prev = 0;
        int cur = 1;
        for (int i = 0; i < lvl; i++)
        {
            prev += cur;
            cur = cur + 4;
        }
        
//         cout << lvl << ' ' << h << ' ' << prev << ' ' << cur << endl;
        
        if (n <= prev) answer = 0;
        else if (n >= prev + cur) answer = 1;
        else if (h == 2 * lvl) answer = 0;
        else
        {
//             cout << "yes" << endl;
            int m = (cur - 1) / 2;
            ans[0][0] = 1;
            for (int i = 1; i <= m; i++)
            {
                ans[i][0] = ans[i - 1][0] / 2;
                ans[0][i] = ans[0][i - 1] / 2;
                if (i >= h + 1 && i == n - prev) answer += ans[i][0];
            }
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    ans[i][j] = 0;
                    if (i == m) ans[i][j] += ans[i][j - 1];
                    else ans[i][j] += ans[i][j - 1] / 2;
                    if (j == m) ans[i][j] += ans[i - 1][j];
                    else ans[i][j] += ans[i - 1][j] / 2;
                    if (i + j == n - prev && i >= h + 1) answer += ans[i][j];
                }
            }
        }
        
        printf("Case #%d: ", T);
        printf("%.7Lf\n", answer);
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
