#include <bits/stdc++.h>
using namespace std;

vector<int> res[1010];
vector<int> g[1010];
int use[1010], tuse[1010], ne[1010];

vector<int> get(int st) {
    int cur = st;
    while (!tuse[cur]) {
        tuse[cur] = 1;
        cur = ne[cur];
    }
    vector<int> res;
    res.push_back(cur);
    int now = cur;
    cur = ne[cur];
    while (cur != now) {
        res.push_back(cur);
        cur = ne[cur];
    }
    return res;
}

int getD(int now) {
    int res = 1;
    for (auto v : g[now]) {
        if (use[v]) {
            continue;
        } else {
            res = max(res, getD(v) + 1);
        }
    }
    return res;
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &ne[i]);
            g[ne[i]].push_back(i);
        }
        memset(use, 0, sizeof(use));
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            memset(tuse, 0, sizeof(tuse));
            vector<int> tcyc = get(i);
            if (!use[tcyc[0]]) {
                for (auto x : tcyc) {
                    use[x] = 1;
                }
                res[cnt++] = tcyc;
            }
        }
        int ans = 0, ress = 0;
        for (int i = 0; i < cnt; i++) {
            vector<int> tcyc = res[i];
            if (tcyc.size() > 2) {
                ans = max(ans, (int)tcyc.size());
            } else {
                memset(use, 0, sizeof(use));
                use[tcyc[0]] = 1;
                use[tcyc[1]] = 1;
                int dep = getD(tcyc[0]) + getD(tcyc[1]);
                ress += dep;
            }
        }
        printf("Case #%d: %d\n", cas, max(ans, ress));
    }
    return 0;
}