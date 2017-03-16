#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define N 1005
#define D 880005
#define BASE 2000005
#define M 4000055

const int INF = 1 << 30;

struct Attack {
    int l, r, s;
    Attack(int l = 0, int r = 0, int s = 0):l(l), r(r), s(s) {}
};

struct Node {
    int d, num, l, r, s;
    int delta_d, delta_p, delta_s;
    void read() {
        scanf("%d %d %d %d %d", &d, &num, &l, &r, &s);
        scanf("%d %d %d", &delta_d, &delta_p, &delta_s);
    }
    void update(vector < Attack > *days) {
        int now = d, ln = l, rn = r, sn = s;
        for (int i = 0; i < num; ++i) {
            days[now].push_back(Attack(ln, rn, sn));
            now += delta_d;
            ln += delta_p;
            rn += delta_p;
            sn += delta_s;
        }
    }
};

int n;
Node a[N];
int h[M * 10];
vector < Attack > days[D];
int x[M], xn;

void init(int i, int l, int r) {
    h[i] = -INF;
    if (l != r) {
        int mid = (l + r) >> 1;
        init(i + i, l, mid);
        init(i + i + 1, mid + 1, r);
    }
}

void update(int i, int ln, int rn, int l, int r, int v) {
    if (l <= ln && rn <= r) {
        h[i] = max(h[i], v);
        return;
    }
    h[i + i] = max(h[i + i], h[i]);
    h[i + i + 1] = max(h[i + i + 1], h[i]);
    int mid = (ln + rn) >> 1;
    if (l <= mid)
        update(i + i, ln, mid, l, r, v);
    if (r > mid)
        update(i + i + 1, mid + 1, rn, l, r, v);
}

int query(int i, int ln, int rn, int l, int r) {
    if (l <= ln && rn <= r)
        return h[i];
    h[i + i] = max(h[i + i], h[i]);
    h[i + i + 1] = max(h[i + i + 1], h[i]);
    int ret = INF, mid = (ln + rn) >> 1;
    if (l <= mid)
        ret = min(ret, query(i + i, ln, mid, l, r));
    if (r > mid)
        ret = min(ret, query(i + i + 1, mid + 1, rn, l, r));
    return ret;
}

int solve() {
    scanf("%d", &n);
    for (int i = 0; i < D; ++i)
        days[i].clear();
    for (int i = 0; i < n; ++i) {
        a[i].read();
        a[i].update(days);
    }

    vector < Attack >::iterator it;

    int left = M, right = 0;
    xn = 0;
    for (int i = 0; i < D; ++i)
        for (it = days[i].begin(); it != days[i].end(); ++it) {
            left = min(left, it->l + BASE);
            right = max(right, it->r + BASE);
            x[xn++] = it->l + BASE;
            x[xn++] = it->r + BASE - 1;
        }
    sort(x, x + xn);
    xn = unique(x, x + xn) - x;
    init(1, 0, xn - 1);

    int ret = 0;
    for (int i = 0; i < D; ++i) if (days[i].size() > 0) {
        for (it = days[i].begin(); it != days[i].end(); ++it) {
            int lp = lower_bound(x, x + xn, it->l + BASE) - x;
            int rp = lower_bound(x, x + xn, it->r + BASE - 1) - x;
            ret += (it->s > query(1, 0, xn - 1, lp, rp));
        }
        for (it = days[i].begin(); it != days[i].end(); ++it) {
            int lp = lower_bound(x, x + xn, it->l + BASE) - x;
            int rp = lower_bound(x, x + xn, it->r + BASE - 1) - x;
            update(1, 0, xn - 1, lp, rp, it->s);
        }
    }
    return ret;
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
        printf("Case #%d: %d\n", ++cas, solve());
    return 0;
}
