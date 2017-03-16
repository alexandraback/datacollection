#include <bits/stdc++.h>
#define MAXN 1123

using namespace std;

typedef int arrayN[MAXN];

arrayN f, vis, fir, e, nxt, lst;
int num;

void link(int u, int v) {
    e[++num] = v, nxt[num] = fir[u];
    fir[u] = num;
}

int dfs(int x) {
    lst[x] = 1;
    for (int p = fir[x]; p; p = nxt[p]) {
        int q = e[p];
        if (vis[q] < 2) {
            vis[q] = 2;
            lst[x] = max(lst[x], dfs(q) + 1);
        }
    }
    return lst[x];
}

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int N;
        scanf("%d", &N);
        int ans = 0;
        int tmpAns = 0;
        num = 0;
        memset(vis, 0, sizeof(vis));
        memset(fir, 0, sizeof(fir));
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &f[i]);
            link(f[i], i);
        }
        for (int i = 1; i <= N; ++i)
            if (!vis[i]) {
                int now = i;
                for (;!vis[now]; now = f[now]) {
                    vis[now] = 1;
                }
                int len = 1;
                int sta = now;
                vector <int> vec;
                now = f[now];
                vec.push_back(sta);
                vis[sta] = 2;
                for (; now != sta; now = f[now]) {
                    ++len;
                    vis[now] = 2;
                    vec.push_back(now);
                }
                for (int i = 0; i < vec.size(); ++i) {
                    int x = vec[i];
                    lst[x] = dfs(x);
                }
                ans = max(ans, len);
                if (len == 2) {
                    tmpAns += lst[vec[0]] + lst[vec[1]];
                }
            }
        ans = max(ans, tmpAns);
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}