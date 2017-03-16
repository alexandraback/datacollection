/**
 * Copyright © 2016 Authors. All rights reserved.
 * 
 * FileName: A.cpp
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

int n, cnt;
bool vis[10];

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                scanf("%d", &n);
                cnt = 0;
                memset(vis, false, sizeof(vis));
                for (int i = n; i; i += n) {
                        char buf[16];
                        sprintf(buf, "%d", i);
                        for (int j = 0; buf[j]; ++j) {
                                if (!vis[buf[j]-'0']) ++cnt;
                                vis[buf[j]-'0'] = true;
                        }
                        if (cnt == 10) {
                                printf("Case #%d: %d\n", ++cas, i);
                                break;
                        }
                }
                if (cnt < 10) printf("Case #%d: INSOMNIA\n", ++cas);
        }

        return 0;
}
