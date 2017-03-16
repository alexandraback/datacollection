#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <functional>
#include <set>
#include <stdlib.h>
#define INF 0x3f3f3f3f
#define clc(x) memset(x, 0, sizeof(x))
using namespace std;
typedef long long ll;
int T, K, C, S;
ll Pow(ll a, ll b) {
    ll ans = 1;
    for (ll i = 1; i <= b; i++) {
        ans *= a;
    }
    return ans;
}
int main()
{
    int kase = 1;
    // freopen("/Users/akanork/desktop/1.in", "r", stdin);
    // freopen("/Users/akanork/desktop/1.out", "w", stdout);
    scanf("%d", &T);
    int sv = T;
    while (T--) {
        if (T != sv - 1) printf("\n");
        scanf("%d %d %d", &K, &C, &S);
        printf("Case #%d: ", kase++);
        if ( K == 1 ) {
            printf("1");
            continue;
        }
        else {
            ll distance = (Pow(K, C) - 1) / (K - 1);
            //printf("distance = %lld\n", distance);
            for (int i = 1; i <= S; i++) {
                printf("%lld ", (i - 1) * distance + 1);
            }
            }
    }

return 0;
}