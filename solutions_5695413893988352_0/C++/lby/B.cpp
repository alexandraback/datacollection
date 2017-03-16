/**
 * Copyright © 2016 Authors. All rights reserved.
 * 
 * FileName: B.cpp
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

const int maxl = 18 + 5;

LL b[18];
int l;
char c[maxl], j[maxl];
vector<LL> ret;

void dfs(int i, LL C, LL J)
{
        if (i == l) {
                vector<LL> tmp;
                tmp.push_back(abs(C - J));
                tmp.push_back(C);
                tmp.push_back(J);
                ret = min(ret, tmp);
                return;
        }
        if (C < J) {
                dfs(i + 1, C + (c[i] == '?'? 9: c[i] - '0') * b[l-i-1], J + (j[i] == '?'? 0: j[i] - '0') * b[l-i-1]);
        } else if (C > J) {
                dfs(i + 1, C + (c[i] == '?'? 0: c[i] - '0') * b[l-i-1], J + (j[i] == '?'? 9: j[i] - '0') * b[l-i-1]);
        } else if (c[i] == '?' && j[i] == '?') {
                dfs(i + 1, C, J);
                dfs(i + 1, C + b[l-i-1], J);
                dfs(i + 1, C, J + b[l-i-1]);
        } else if (c[i] == '?') {
                dfs(i + 1, C + (j[i] - '0') * b[l-i-1], J + (j[i] - '0') * b[l-i-1]);
                if (j[i] > '0') dfs(i + 1, C + (j[i] - '0' - 1) * b[l-i-1], J + (j[i] - '0') * b[l-i-1]);
                if (j[i] < '9') dfs(i + 1, C + (j[i] - '0' + 1) * b[l-i-1], J + (j[i] - '0') * b[l-i-1]);
        } else if (j[i] == '?') {
                dfs(i + 1, C + (c[i] - '0') * b[l-i-1], J + (c[i] - '0') * b[l-i-1]);
                if (c[i] > '0') dfs(i + 1, C + (c[i] - '0') * b[l-i-1], J + (c[i] - '0' - 1) * b[l-i-1]);
                if (c[i] < '9') dfs(i + 1, C + (c[i] - '0') * b[l-i-1], J + (c[i] - '0' + 1) * b[l-i-1]);
        } else {
                dfs(i + 1, C + (c[i] - '0') * b[l-i-1], J + (j[i] - '0') * b[l-i-1]);
        }
}

void print(LL v)
{
        vector<int> d;
        do d.push_back(v % 10);
        while (v /= 10);
        while (d.size() < l) d.push_back(0);
        rep(i,l) putchar('0' + d[l-i-1]);
}

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        b[0] = 1;
        For(i,1,17) b[i] = b[i-1] * 10;
        while (T--) {
                scanf("%s%s", c, j);
                l = strlen(c);
                ret.clear();
                rep(i,3) ret.push_back(infLL);
                dfs(0, 0, 0);
                printf("Case #%d: ", ++cas);
                print(ret[1]);
                putchar(' ');
                print(ret[2]);
                puts("");
        }

        return 0;
}
