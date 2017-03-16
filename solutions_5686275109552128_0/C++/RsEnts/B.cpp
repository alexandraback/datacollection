#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 100010

using namespace std;

int T, D, P[MaxN], ans;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int i, j, T0 = 0;
    scanf("%d", &T);
    for( ; T; --T) {
        scanf("%d", &D);
        for(i = 1; i <= D; ++i)
            scanf("%d", &P[i]);
        ans = ~0U >> 1;
        for(i = 1; i <= 1000; ++i) {
            int tmp = 0;
            for(j = 1; j <= D; ++j)
                tmp += (P[j] - 1) / i;
            tmp += i;
            ans = min(ans, tmp);
        }
        printf("Case #%d: %d\n", ++T0, ans);
    }
}
