#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;
typedef long long ll;

int n, p[1024]; //q[1024];
// bitset<1024> v[1024];

struct E {
    int l;
    int to[1024];
} edge[1024];

struct Q {
    int q;
    bitset<1024> v;
    bool ring;
} q[1024];

int s;

int cmp(Q a, Q b) {
    return a.q > b.q;
}

int dfs(int x, int pre, bool d) {
    q[s].v[x] = 1;
    if (d) {
        int r = 0;
        for (int i = 0; i < edge[x].l; ++i) {
            if (!q[s].v[edge[x].to[i]]) {
                r = max(r, 1 + dfs(edge[x].to[i], -1, true));
            }
        }
        return r;
    } else {
        if (q[s].v[p[x]]) {
            if (p[x] == pre) {
                q[s].ring = true;
                return 1 + dfs(x, -1, true);
            } else if (p[x] == s) {
                return 1;
            } else {
                return -1024;
            }
        } else {
            return 1 + dfs(p[x], x, false);
        }
    }
    return 0;
}

int main() {
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        // memset(v, 0, sizeof(v));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            edge[i].l = 0;
            q[i].v.reset();
            q[i].ring = false;
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &p[i]);
            edge[p[i]].to[edge[p[i]].l++] = i;
        }
        int x = 0;
        for (int i = 1; i <= n; ++i) {
            s = i;
            // x = max(x, dfs(i, -1, 0));
            q[i].q = dfs(i, -1, 0);
        }
        sort(q + 1, q + n + 1, cmp);
        x = q[1].q;
        bitset<1024> b = q[1].v;
        if (q[1].ring) {
            for (int i = 2; i <= n; ++i) {
                if (q[i].q <= 0) {
                    break;
                }
                if (q[i].ring && (q[i].v & b).count() == 0) {
                    x += q[i].q;
                    b |= q[i].v;
                }
            }
        } else {
            int y = 0;
            b.reset();
            for (int i = 2; i <= n; ++i) {
                if (q[i].q <= 0) {
                    break;
                }
                if (q[i].ring && (q[i].v & b).count() == 0) {
                    y += q[i].q;
                    b |= q[i].v;
                }
            }
            if (y > x) x = y;
        }
        printf("Case #%d: %d\n", ++cas, x);
    }
    return 0;
}