/**
 * Copyright © 2016 Authors. All rights reserved.
 * 
 * FileName: C.cpp
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

const int maxn = 32 + 5;

int a[maxn];

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                int n, j;
                scanf("%d%d", &n, &j);
                printf("Case #%d:\n", ++cas);
                rep(i,j) {
                        int v = i, p = n / 2 - 1;
                        do a[--p] = v & 1;
                        while (v >>= 1);
                        a[0] = a[n/2-1] = 1;
                        rep(k,n/2) printf("%d", a[k]);
                        rep(k,n/2) printf("%d", a[k]);
                        For(b,2,10) {
                                LL ret = 0;
                                rep(k,n/2) ret = ret * b + a[k];
                                printf(" %lld", ret);
                        }
                        puts("");
                }
        }

        return 0;
}
