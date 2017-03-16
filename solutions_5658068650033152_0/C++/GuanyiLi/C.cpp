#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

int ans[100];

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-output.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T ++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= 2 * (n + m) - 4; i ++)
        {
            ans[i] = i;
        }
        for (int i = 1; i <= m; i ++)
        {
            for (int j = i; j <= m; j ++)
            {
                for (int k = i; k <= j; k ++)
                {
                    for (int h1 = max((j - i + 1) / 2, 1) + 1; h1 <= n; h1 ++)
                    {
                        for (int h2 = max((j - k + 1) / 2, 1) + 1; h1 + h2 - 1 <= n; h2 ++)
                        {
                            int len = i + k + (h1 + h2 - 3) * 2;
                            ans[len] = max(ans[len], (i + j) * h1 / 2 + (j + k) * h2 / 2 - j);
                        }
                    }
                }
            }
        }
        int k;
        scanf("%d", &k);
        printf("Case #%d: %d\n", T, lower_bound(ans, ans + 2 * (n + m) - 3, k) - ans);
    }
    return 0;
}
