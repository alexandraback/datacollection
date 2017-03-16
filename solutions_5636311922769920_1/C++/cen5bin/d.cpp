#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
#define esp 1e-9
typedef long long LL;
const int MOD = 1e9+7;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        static int cas = 1;
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);
        if (c*s < k) {
            printf("Case #%d: IMPOSSIBLE\n", cas++);
            continue;
        }
        printf("Case #%d:", cas++);
        LL now = 0, cnt = 0;
        for (int i = 0; i < k; ++i) {
            now = now * k + i;
            if (++cnt == c) {
                printf(" %lld", now+1);
                now = 0;
                cnt = 0;
            }
        }
        if (cnt) printf(" %lld", now+1);
        puts("");
    }
    return 0;
}

