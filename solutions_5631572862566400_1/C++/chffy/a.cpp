#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

const int N = 1005;

int a[N];
vector<int> e[N];
int dfn[N], mark[N], color[N], val[N];
int sum, cnt;

stack<int> sta;

int c[N];

void dfs(int x) {
    dfn[x] = mark[x] = ++sum;
    sta.push(x);
    
    for (auto y : e[x]) {
        if (!dfn[y]) dfs(y);
        mark[x] = min(mark[x], mark[y]);
    }
    if (mark[x] == dfn[x]) {
        int y;
        ++cnt;
        do {
            y = sta.top();  sta.pop();
            mark[y] = 1 << 30;
            color[y] = cnt;
            ++val[cnt];
            c[cnt] = y;
        } while (y != x);
    }
}

int f[N], d[N];

int answer(int x) {
    f[x] = 0;
    dfn[x] = 1;
    map<int, int> t;
    for (auto y : e[x]) {
        answer(y);
        t[a[c[y]]] = max(t[a[c[y]]], f[y]);
        if (f[y] > f[x]) f[x] = f[y];
    }
    f[x] += val[x];
    int ans = val[x];
    for (auto fr : t)
        ans += fr.second;
    if (val[x] == 2) return ans;
    else return 0;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
   
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) e[i].clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            e[a[i]].push_back(i);
        }    
        memset(dfn, 0, sizeof(dfn));
        memset(val, 0, sizeof(val));
        cnt = sum = 0;
        for (int i = 1; i <= n; ++i)
            if (dfn[i] == 0) dfs(i);
        memset(dfn, 0, sizeof(dfn));
        for (int i = 1; i <= n; ++i)
            e[i].clear();
        for (int i = 1; i <= n; ++i)
            if (color[i] != color[a[i]]) {
                e[color[a[i]]].push_back(color[i]);
            }
        int ans = 0;
        for (int i = 1; i <= cnt; ++i)
            if (val[i] > 1)
                ans = ans + answer(i);
        for (int i = 1; i <= cnt; ++i)
            if (val[i] > 1) ans = max(ans, val[i]);
        static int ca = 0;
        printf("Case #%d: %d\n", ++ca, ans);
    }
    return 0;
}
