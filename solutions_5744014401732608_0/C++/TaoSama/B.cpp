//
//  Created by TaoSama on 2016-05-08
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, g[55][55];
typedef long long LL;
LL m;

int main() {
#ifdef LOCAL
    freopen("B-small-attempt4.in", "r", stdin);
    freopen("B-small-attempt4.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%lld", &n, &m);

        memset(g, 0, sizeof g);
        for(int i = 1; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                g[i][j] = 1;

        static int kase = 0;
        printf("Case #%d: ", ++kase);
        if(1LL << n - 2 < m) {
            puts("IMPOSSIBLE");
        } else {
            puts("POSSIBLE");
            --m;
            g[1][n] = 1;
            for(int i = 0; i < n - 2; i++)
                if(m >> i & 1) g[i + 2][n] = 1;

            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j)
                    printf("%d", g[i][j]);
                puts("");
            }
        }
    }

#ifdef LOCAL
//    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
