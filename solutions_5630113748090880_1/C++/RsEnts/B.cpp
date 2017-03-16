#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 1010

using namespace std;

int T, N;
bool exist[MaxN * 5];

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T0 = 0;
    scanf("%d", &T);
    for ( ; T; --T) {
        scanf("%d", &N);
        memset(exist, 0, sizeof(exist));
        for (int i = 1; i <= 2 * N - 1; ++i) {
            for (int j = 1; j <= N; ++j) {
                int x;
                scanf("%d", &x);
                exist[x] ^= 1;
            }
        }
        printf("Case #%d:", ++T0);
        for (int i = 1; i <= 2500; ++i) {
            if (exist[i]) {
                printf(" %d", i);
            }
        }
        puts("");
    }
    return 0;
}
