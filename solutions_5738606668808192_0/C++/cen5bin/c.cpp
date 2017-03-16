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
LL p[1000010];
int cnt = 1;
void init() {
    p[0] = 2;
    for (LL i = 3; i < 2000000; i+=2) {
        bool yes = 0;
        for (int j = 0; p[j] * p[j] <= i; ++j)
            if (i % p[j] == 0) {
                yes = 1;
                break;
            }
        if (!yes) p[cnt++] = i;
    }
}
int main()
{
    init();
    printf("Case #1:\n");
    LL n = 16;
    scanf("%lld", &n);
    int cc;
    scanf("%d", &cc);
    LL all = (1<<n);
    int b[40];
    int pp[10];
    for (LL i = (1<<(n-1)) + 1; i < all; i+=2) {
        int x = i;
        for (int j = 0; j < n; ++j) b[n-1-j] = x & 1, x >>= 1;
        bool yes = 0;
        for (int j = 2; j <= 10; ++j) {
            LL x = 0;
            for (int k = 0; k < n; ++k)
                x = x * j + b[k];
            //printf("zzz %lld\n", x);
            yes = 0;
            for (int k = 0; p[k] * p[k] <= x && k < cnt; ++k)
                if (x % p[k] == 0) {
                    pp[j] = p[k];
                    yes = 1;
                    break;
                }
            if (!yes) break;
        }
        if (yes) {
            cc--;
            for (int j = 0; j < n; ++j) printf("%d", b[j]);
            for (int j = 2; j <= 10; ++j) printf(" %d", pp[j]);
            puts("");
        }
        if (cc == 0) break;
    }
    return 0;
}

