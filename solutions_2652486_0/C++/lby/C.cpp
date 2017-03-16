/**
 * Copyright (c) 2013 Authors. All rights reserved.
 * 
 * FileName: C.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2013-04-27
 */
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXK = 7 + 5;

int r, n, m, k;
int p[MAXK];
bool ok[256];

void solve() {
        for (int i1 = 2; i1 <= m; ++i1)
                for (int i2 = 2; i2 <= m; ++i2)
                        for (int i3 = 2; i3 <= m; ++i3) {
                                memset(ok, false, sizeof(ok));
                                ok[1] = true;
                                ok[i1] = true;
                                ok[i2] = true;
                                ok[i3] = true;
                                ok[i1*i2] = true;
                                ok[i1*i3] = true;
                                ok[i2*i3] = true;
                                ok[i1*i2*i3] = true;

                                bool flag = true;
                                for (int i = 0; i < k; ++i)
                                        flag &= ok[p[i]];

                                if (!flag) continue;

                                printf("%d%d%d\n", i1, i2, i3);
                                return;
                        }
}

int main()
{
        //freopen("C-small-1-attempt0.in", "r", stdin);
        //freopen("C-small-1-attempt0.out", "w", stdout);

        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                scanf("%d%d%d%d", &r, &n, &m, &k);

                printf("Case #%d:\n", ++cas);
                while (r--) {
                        for (int i = 0; i < k; ++i)
                                scanf("%d", &p[i]);
                        solve();
                }
        }

        return 0;
}
