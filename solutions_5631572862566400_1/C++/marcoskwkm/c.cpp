#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1010;

int nxt[MAXN];
bool seen[MAXN];
bool used[MAXN];
vector<int> rev[MAXN];

int dfs(int v, int prev, int depth) {
    int ret = depth;
    for (int u: rev[v]) {
        if (u == prev) continue;
        ret = max(ret, dfs(u, v, depth + 1));
    }
    return ret;
}

int main() {
    int t = 1, T;
    for (scanf("%d", &T); t <= T; t++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            rev[i].clear();
            used[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &nxt[i]);
            rev[nxt[i]].push_back(i);
        }
        
        // max cycles
        int ans = 0;
        for (int s = 1; s <= n; s++) {
            memset(seen, 0, sizeof(seen));
            int cnt = 1, cur = s;
            seen[s] = 1;
            while (!seen[nxt[cur]]) {
                cnt++;
                cur = nxt[cur];
                seen[cur] = 1;
            }
            if (nxt[cur] == s) ans = max(ans, cnt);
        }

        // independent segments
        int ans2 = 0;
        for (int s = 1; s <= n; s++) {
            if (used[s]) continue;
            if (nxt[nxt[s]] == s) {
                ans2 += dfs(s, nxt[s], 0) + 2 + dfs(nxt[s], s, 0);
                used[s] = used[nxt[s]] = 1;
            }
        }

        printf("Case #%d: %d\n", t, max(ans, ans2));
    }
    return 0;
}
