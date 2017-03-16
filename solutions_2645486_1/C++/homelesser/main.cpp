#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const long long maxn = 10005;
long long e, r, n, v[maxn];

struct node {
    long long val, pos;

    node() {
    }

    node(long long _x, long long _y) {
        val = _x;
        pos = _y;
    }
};
vector<node> vv;
vector<node> vvv;

bool cmp(const node&x, const node &y) {
    if (x.val > y.val) return 1;
    if (x.val < y.val) return 0;
    return x.pos < y.pos;
}

int main() {
    freopen("in.x", "r", stdin);
    freopen("out.x", "w", stdout);
    long long T;
    scanf("%lld", &T);
    for (long long cas = 1; cas <= T; cas++) {
        scanf("%lld%lld%lld", &e, &r, &n);
        for (long long i = 1; i <= n; i++) scanf("%lld", &v[i]);
        vv.clear();
        for (long long i = 1; i <= n; i++)
            vv.push_back(node(v[i], i));
        sort(vv.begin(), vv.end(), cmp);
        long long pre = -1;
        vvv.clear();
        for (long long i = 0; i < vv.size(); i++) {
            if (pre == -1) {
                vvv.push_back(vv[i]);
                pre = i;
            } else if (vv[i].pos > vv[pre].pos) {
                vvv.push_back(vv[i]);
                pre = i;
            }
        }
        long long cur = e, ans = 0, pp;
        for (long long i = 0; i < vvv.size(); i++) {
            if (i == 0) pp = 1;
            else pp = vvv[i - 1].pos + 1;
            for (long long p = pp; p < vvv[i].pos; p++) {
                if (cur + r > e) {
                    ans += v[p]*(cur + r - e);
                    cur = e;
                } else {
                    cur += r;
                }
            }
            ans += cur * vvv[i].val;
            cur = r;
        }
        if (vvv.size() > 0)
            for (long long p = vvv[vvv.size() - 1].pos + 1; p <= n; p++) {
                if (cur + r > e) {
                    ans += v[p]*(cur + r - e);
                    cur += r - e;
                } else {
                    cur += r;
                }
            }
        printf("Case #%lld: %lld\n", cas, ans);
    }
    return 0;
}

