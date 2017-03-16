#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

int BASE; int val[1 << 23], mn[1 << 23];
const int INF = 1000000000;

void add(int a, int b, int x, int y, int p, int v) {
    if (a == x && b == y) {
        val[p] = v;
        mn[p] = v;
        return;
    }
    int mid = (x + y) / 2;
    if (b <= mid) {
        add(a, b, x, mid, 2 * p, v);
    } else if (a > mid) {
        add(a, b, mid + 1, y, 2 * p + 1, v);
    } else {
        add(a, mid, x, mid, 2 * p, v);
        add(mid + 1, b, mid + 1, y, 2 * p + 1, v);
    }
    mn[p] = min(max(val[p], mn[2 * p]), max(val[p], mn[2 * p + 1]));
}

int get(int a, int b, int x, int y, int p) {
    if (a == x && b == y) {
        return mn[p];
    }
    int mid = (x + y) / 2, res = INF;
    if (b <= mid) {
        res = get(a, b, x, mid, 2 * p);
    } else if (a > mid) {
        res = get(a, b, mid + 1, y, 2 * p + 1);
    } else {
        res = get(a, mid, x, mid, 2 * p);
        res = min(get(mid + 1, b, mid + 1, y, 2 * p + 1), res);
    }
    res = max(res, val[p]);
    return res;
}

struct event {
    int d, s, a, b;
    int operator<(const event &e) const {
        return d < e.d;
    }
};

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        vector<event> ev;
        VI all;
        int N; scanf("%d", &N);
        REP (i, N) {
            int d, n, w, e, s, dd, dp, ds;
            scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
            int D = d, W = w, E = e, S = s;
            event tmp;
            REP (j, n) {
                tmp.d = D; tmp.a = W; tmp.b = E; tmp.s = S;
                ev.PB(tmp);
                D += dd; W += dp; E += dp; S += ds;
            }
        }
        FC (ev, it) {
            all.PB(it->a);
            all.PB(it->b);
        }
        sort(ALL(all));
        all.erase(unique(ALL(all)), all.end());
        FC (ev, it) {
            it->a = (lower_bound(ALL(all), it->a) - all.begin()) * 2;
            it->b = (lower_bound(ALL(all), it->b) - all.begin()) * 2;
        }
        sort(ALL(ev));
        for (BASE = 1; BASE < 2 * SZ(all); BASE <<= 1);
        assert(2 * BASE <= (1 << 23));
        memset(val, 0, sizeof(int) * 2 * BASE);
        memset(mn, 0, sizeof(int) * 2 * BASE);
        int res = 0;
        for (int i = 0; i < SZ(ev); ) {
            int j;
            for (j = i; j < SZ(ev) && ev[j].d == ev[i].d; ++j);
            for (int k = i; k < j; ++k) {
                if (get(ev[k].a, ev[k].b, 0, BASE - 1, 1) < ev[k].s) {
                    //printf("succ %d %d %d s: %d ->%d\n", ev[k].d, ev[k].a, ev[k].b, ev[k].s, get(ev[k].a, ev[k].b, 0, BASE - 1, 1) );
                    ++res;
                }
            }
            for (int k = i; k < j; ++k) {
                int m = max(get(ev[k].a, ev[k].b, 0, BASE - 1, 1), ev[k].s);
                add(ev[k].a, ev[k].b, 0, BASE - 1, 1, m);
            }
            i = j;
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
                    

