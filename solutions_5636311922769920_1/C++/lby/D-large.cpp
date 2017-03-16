/**
 * Copyright © 2016 Authors. All rights reserved.
 * 
 * FileName: D-large.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2016-04-09
 */
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;

const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

int k, c, s;

void dfs(int d, int i, LL offset)
{
        if (d == c) {
                printf(" %lld", offset + i);
                return;
        }
        dfs(d + 1, min(i + 1, k), (offset + i - 1) * k);
}

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                scanf("%d%d%d", &k, &c, &s);
                printf("Case #%d:", ++cas);
                if (c * s < k) {
                        puts(" IMPOSSIBLE");
                        continue;
                }
                for (int i = 1; i <= k; i += c) dfs(1, 1, i - 1);
                puts("");
        }

        return 0;
}
