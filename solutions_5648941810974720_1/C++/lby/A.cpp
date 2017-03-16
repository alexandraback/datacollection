/**
 * Copyright © 2016 Authors. All rights reserved.
 * 
 * FileName: A.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2016-05-01
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

const int maxn = 50 + 5;
const int maxl = 2000 + 5;
const double eps = 1e-10;
string str[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR",
        "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void gauss(double a[][maxn], int m, int n)
{
        for (int i = 0; i < n; ++i) {
                int r = i;
                for (int k = i + 1; k < m; ++k)
                        if (fabs(a[k][i]) > fabs(a[r][i])) r = k;
                if (r != i) for (int j = i; j <= m; ++j) swap(a[r][j], a[i][j]);
                for (int k = i + 1; k < m; ++k)
                        for (int j = n; j >= i; --j)
                                a[k][j] -= a[k][i] / a[i][i] * a[i][j];
        }
        for (int i = n - 1; i >= 0; --i) {
                for (int j = i + 1; j < n; ++j) a[i][n] -= a[i][j] * a[j][n];
                a[i][n] /= a[i][i];
        }
}

char s[maxl];
double a[maxn][maxn];

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                memset(a, 0, sizeof(a));
                scanf("%s", s);
                for (int i = 0; s[i]; ++i) a[s[i]-'A'][10] += 1;
                rep(d,10) foreach(it,str[d]) a[*it-'A'][d] += 1;
                gauss(a, 26, 10);
                printf("Case #%d: ", ++cas);
                rep(d,10) cout << string((int)(a[d][10] + eps), '0' + d);
                cout << endl;
        }

        return 0;
}
