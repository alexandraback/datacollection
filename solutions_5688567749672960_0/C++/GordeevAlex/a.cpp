#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ldb;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

const int MAXN = 2e6 + 10;

int rev(int x) {
    vector<int> dig;
    while (x > 0) {
        dig.push_back(x % 10);
        x /= 10;
    }

    int res = 0;

    forn(i, dig.size())
        res = res * 10 + dig[i];

    return res;
}

int dp[MAXN];

int q[MAXN];
int b = 0, e = 0;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    q[e++] = 1;

    while (b < e) {
        int v = q[b++];

        if (v + 1 < MAXN && dp[v + 1] == -1) {
            q[e++] = v + 1;
            dp[v + 1] = dp[v] + 1;
        }

        int u = rev(v);

        if (u < MAXN && dp[u] == -1) {
            q[e++] = u;
            dp[u] = dp[v] + 1;
        }
    }

    int T;
    scanf("%d ", &T);
    forn(testNum, T) {
        printf("Case #%d: ", testNum + 1);

        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);

    }
    return 0;
}
