/**
 * Copyright © 2016 Authors. All rights reserved.
 * 
 * FileName: D-small.cpp
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

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                int k, c, s;
                scanf("%d%d%d", &k, &c, &s);
                printf("Case #%d:", ++cas);
                For(i,1,k) printf(" %d", i);
                puts("");
        }

        return 0;
}
