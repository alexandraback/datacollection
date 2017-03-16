/**
 * Copyright © 2016 Authors. All rights reserved.
 * 
 * FileName: B.cpp
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

const int maxn = 100 + 5;

int n, cnt;
char s[maxn];

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                scanf("%s", s);
                n = strlen(s), cnt = 0;
                for (int i = 0; i < n; ++i) {
                        int j = i + 1;
                        while (j < n && s[j] == s[i]) ++j;
                        ++cnt;
                        i = j - 1;
                }
                if (s[n-1] == '+') --cnt;
                printf("Case #%d: %d\n", ++cas, cnt);
        }

        return 0;
}
