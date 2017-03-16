#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100, maxl = 1000000;
class Tribe {
public:
    int d, n, w, e, s, dd, dp, ds;
}t[maxn];
class Attack {
public:
    int d, w, e, s;
    Attack(int _d = 0, int _w = 0, int _e = 0, int _s = 0) {
        d = _d, w = _w, e = _e, s = _s;
    }
    bool operator<(const Attack &x) const {
        return d < x.d;
    }
}v[maxn * maxn];
int h[maxl * 2];
long long solve() {
    int n, m = 0, l, r;
    l = 0x7fffffff;
    r = -l;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i) {
        scanf("%d%d%d%d%d%d%d%d", &t[i].d, &t[i].n, &t[i].w, &t[i].e, &t[i].s, &t[i].dd, &t[i].dp, &t[i].ds);
        for (int j = 0 ; j < t[i].n ; ++j) {
            v[m++] = Attack(t[i].d + t[i].dd * j, t[i].w + t[i].dp * j, t[i].e + t[i].dp * j, t[i].s + t[i].ds * j);
            l = min(l, v[m - 1].w);
        }
    }
    for (int i = 0 ; i < m ; ++i) {
        v[i].w -= l, v[i].e -= l;
        v[i].w = v[i].w * 2;
        v[i].e = v[i].e * 2 - 1;
        r = max(r, v[i].e);
    }
    for (int i = 0 ; i <= r ; ++i) h[i] = 0;
    sort(v, v + m);
    long long c = 0;
    for (int i = 0 ; i < m ;) {
        int j = i + 1;
        while (j < m && v[j].d == v[j - 1].d) ++j;
        for (int k = i ; k < j ; ++k)
            for (int x = v[k].w ; x <= v[k].e ; ++x)
                if (h[x] < v[k].s) {
                    ++c;
                    break;
                }
        for (int k = i ; k < j ; ++k)
            for (int x = v[k].w ; x <= v[k].e ; ++x)
                h[x] = max(h[x], v[k].s);
        i = j;
    }
    return c;
}
int main() {
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int i = 1 ; i <= t ; ++i)
        printf("Case #%d: %lld\n", i, solve());
    fclose(stdin);
    fclose(stdout);
    return 0;
}