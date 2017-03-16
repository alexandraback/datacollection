#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <deque>

using namespace std;

typedef long long LL;
const int maxn = 20010;
const int inf = 0x3f3f3f3f;
int v[maxn], E, R, N, lp[maxn];
int idx[maxn], canuse[maxn];
bool cmp(int a, int b) {
    return v[a] > v[b];
}
int cv[maxn], lv;
vector<set<int> > ret;
struct Segment {
    static const int maxn = 20010 * 4;
    int left[maxn], right[maxn], mc[maxn];
    void build(int t, int l, int r) {
        left[t] = l, right[t] = r, mc[t] = inf;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(t << 1, l, mid);
        build(t << 1 | 1, mid + 1, r);
    }
    void updata(int t, int p, int c, int typ) {
        if (left[t] == p && right[t] == p) {
            if (typ == -1) {
                ret[p].erase(c);
            } else {
                ret[p].insert(c);
            }
            if (ret[p].empty()) mc[t] = inf;
            else mc[t] = *ret[p].begin();
            return;
        }
        int mid = (left[t] + right[t]) >> 1;
        if (p <= mid) updata(t << 1, p, c, typ);
        else updata(t << 1 | 1, p, c, typ);
        mc[t] = min(mc[t << 1], mc[t << 1 | 1]);
    }
    int query(int t, int l, int r) {
        if (l > r) return inf;
        if (left[t] == l && right[t] == r) {
            return mc[t];
        }
        int mid = (left[t] + right[t]) >> 1;
        if (r <= mid) return query(t << 1, l, r);
        else if (l > mid) return query(t << 1 | 1, l, r);
        else return min(query(t << 1, l, mid), query(t << 1 | 1, mid + 1, r));
    }
}seg;

void solved(int nT) {
    scanf("%d %d %d", &E, &R, &N);
    R = min(R, E);
    lv = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
        cv[lv++] = v[i];
        canuse[i] = E;
        idx[i] = i;
    }
    printf("Case #%d: ", nT);
    LL result = 0, cur = E;
    if (R == E) {
        for (int i = 0; i < N; ++i) {
            result += (LL)v[i] * R;
        }
        printf("%lld\n", result); return;
    }
    sort(cv, cv + lv);
    lv = unique(cv, cv + lv) - cv;
    seg.build(1, 0, lv - 1);
    ret.clear(); ret.resize(lv);
    for (int i = 0; i < N; ++i) {
        
        lp[i] = lower_bound(cv, cv + lv, v[i]) - cv;
        seg.updata(1, lp[i], i, 1);
    }
    cur = E;
    for (int i = 0; i < N; ++i) {
        seg.updata(1, lp[i], i, -1);
        int p = seg.query(1, lp[i] + 1, lv - 1);
        if (p == inf) {
            result += (LL)v[i] * cur;
            cur = R;
        } else {
            LL d = max(0LL, E - (LL)(p - i) * R);
            result += max(0LL, (cur - d)) * (LL)v[i];
            cur -= max(0LL, cur - d);
            cur = min((LL)E, cur + R);
        }
    }
    //result += cur * (LL)v[N - 1];
    printf("%lld\n", result);
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B1.out", "w", stdout);
    int T = 1;
    scanf("%d", &T);
    for (int nT = 1; nT <= T; ++nT) {
        solved(nT);
    }
    return 0;
}