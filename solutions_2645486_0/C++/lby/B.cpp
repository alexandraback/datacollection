/**
 * Copyright (c) 2013 Authors. All rights reserved.
 * 
 * FileName: B.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2013-04-27
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10 + 5;
const int MAXE = 5 + 2;

int n, r, e;
int v[MAXN];
int opt[MAXN][MAXE];

int main()
{
        //freopen("B-small-attempt0.in", "r", stdin);
        //freopen("B-small-attempt0.out", "w", stdout);

        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                scanf("%d%d%d", &e, &r, &n);
                for (int i = 0; i < n; ++i)
                        scanf("%d", &v[i]);

                memset(opt, 0, sizeof(opt));
                for (int i = 0; i < n; ++i)
                        for (int j = 0; j <= e; ++j)
                                for (int k = 0; k <= j; ++k)
                                        opt[i+1][min(e, j - k + r)] =
                                                max(opt[i+1][min(e, j - k + r)],
                                                                opt[i][j] + v[i] * k);

                int ans = 0;
                for (int j = 0; j <= e; ++j)
                        ans = max(ans, opt[n][j]);

                printf("Case #%d: %d\n", ++cas, ans);
        }

        return 0;
}
