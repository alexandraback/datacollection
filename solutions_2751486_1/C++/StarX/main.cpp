#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <sstream>
#include <stack>
#include <map>
#include <queue>

#define CL(arr, val)    memset(arr, val, sizeof(arr))
#define lc l,m,rt<<1
#define rc m + 1,r,rt<<1|1
#define pi acos(-1.0)
#define ll long long
#define L(x)    (x) << 1
#define R(x)    (x) << 1 | 1
#define MID(l, r)   (l + r) >> 1
#define Min(x, y)   (x) < (y) ? (x) : (y)
#define Max(x, y)   (x) < (y) ? (y) : (x)
#define E(x)        (1 << (x))
#define iabs(x)     (x) < 0 ? -(x) : (x)
#define OUT(x)  printf("%I64d\n", x)
#define lowbit(x)   (x)&(-x)
#define Read()  freopen("A-large.in", "r", stdin)
#define Write() freopen("dout.txt", "w", stdout);


#define M 30007
#define N 1000007

using namespace std;

const int inf = 100000007;
const int mod = 1000000007;
const double eps = 1e-6;
ll dp[N][2];
int ok[N];
char s[N];
int a[N];

int main()
{
    Read();
    Write();
    int T,n;
    int cas = 1;
    int i;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%d",s,&n);
//        printf("%s\n",s);
        int len = strlen(s);
        for (i = 0; i < len; ++i)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') a[i + 1] = 0;
            else a[i + 1] = 1;
        }
        int cnt = 0;
        CL(ok,0);
        for (i = 1; i <= len; ++i)
        {
            if (a[i] == 0)
            {
                cnt = 0;
                ok[i] = 0;
            }
            else
            {
                cnt++;
                if (cnt >= n) ok[i] = 1;
                else ok[i] = 0;
            }
        }
        CL(dp,0);

        for (i = n; i <= len; ++i)
        {
            if (ok[i] == 1) dp[i][1] = i - n + 1;
            else dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        }
        ll ans = 0;
        for (i = n; i <= len; ++i)
        {
            ans += dp[i][0] + dp[i][1];
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }

    return 0;
}
