#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forit(it, v) for (auto it : v)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

struct Attack {
    int left;
    int w, e, delta_p;
    int s, delta_s;
    int delta_d;
};

struct Query {
    int l, r, s;
    bool upd; // or get
};

const int INF = 2100000000;
const int nn = 1<<21;
int t[nn<<1], tl[nn<<1], tr[nn<<1];


void upd_min(int v, int l, int r, int s) {
    if (tl[v] >= r || tr[v] <= l) return;
    if (l <= tl[v] && tr[v] <= r) {
        t[v] = max(t[v], s);
        return;
    }
    int v1 = v<<1, v2 = (v<<1)+1;
    t[v1] = max(t[v1], t[v]);
    upd_min(v1, l, r, s);
    t[v2] = max(t[v2], t[v]);
    upd_min(v2, l, r, s);
    t[v] = min(t[v1], t[v2]);
}

int get_min(int v, int l, int r) {
    if (tl[v] >= r || tr[v] <= l) return INF;
    if (l <= tl[v] && tr[v] <= r) return t[v];
    int v1 = v<<1, v2 = (v<<1)+1;
    t[v1] = max(t[v1], t[v]);
    t[v2] = max(t[v2], t[v]);
    return min(get_min(v1, l, r), get_min(v2, l, r));
}


int main() {
    int __;
    scanf("%d", &__);
    forn(_, __) {
        eprintf("%d\n", _+1);
        printf("Case #%d: ", _+1);
        
        map<int, vector<Attack> > m;
        vector<Query> queries;

        int n;
        scanf("%d", &n);
        forn(i, n) {
            int di,ni,w,e,s,dd,dp,ds;
            scanf("%d%d%d%d%d%d%d%d", &di,&ni,&w,&e,&s,&dd,&dp,&ds);
            Attack a = {.left=ni, .w=w, .e=e, .delta_p=dp, .s=s, .delta_s=ds, .delta_d=dd};
            m[di].push_back(a);
        }

        while (!m.empty()) {
            int t = m.begin()->first;
            vector<Attack> v = m.begin()->second;
            m.erase(m.begin());

            for (auto a : v) {
                queries.push_back(Query { .l = a.w, .r = a.e, .s = a.s, .upd = false });
            }

            for (auto a : v) {
                queries.push_back(Query { .l = a.w, .r = a.e, .s = a.s, .upd = true });
                if (a.left > 1) {
                    Attack b = {.left=a.left-1, .w=a.w+a.delta_p, .e=a.e+a.delta_p, .s=a.s+a.delta_s,
                        .delta_p=a.delta_p, .delta_s=a.delta_s, .delta_d=a.delta_d};
                    m[t + a.delta_d].push_back(b);
                }
            }
        }

        set<int> coords;
        for (auto& query : queries) {
            coords.insert(query.l);
            coords.insert(query.r);
        }
        map<int, int> coord_map;
        int ccc = 0;
        for (auto x : coords) coord_map[x] = ccc++;
        assert(ccc < nn);

        for (auto& query : queries) {
            query.l = coord_map[query.l];
            query.r = coord_map[query.r];
        }


        forn(i, nn) {
            tl[i+nn] = i;
            tr[i+nn] = i+1;
            t[i+nn] = 0;
        }
        for (int i = nn-1; i; i--) {
            tl[i] = tl[i<<1];
            tr[i] = tr[(i<<1)+1];
            t[i] = 0;
        }

        int ans = 0;
        for (auto& query : queries) {
            if (query.upd) {
                upd_min(1, query.l, query.r, query.s);
                // eprintf("upd_min %d %d %d\n", query.l, query.r, query.s);
            } else {
                int m = get_min(1, query.l, query.r);
                // eprintf("get_min %d %d = %d, s = %d\n", query.l, query.r, m, query.s);
                if (m < query.s) ans++;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}

