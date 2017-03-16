#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define N 1005
#define D 770005
#define BASE 1000
#define M 10005

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
        //printf("num %d\n", num);
        for (int i = 0; i < num; ++i) {
            //printf(" %d : %d\n", i, now);
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
int h[M], nxth[M];
vector < Attack > days[D];

int solve() {
    scanf("%d", &n);
    for (int i = 0; i < D; ++i)
        days[i].clear();
    for (int i = 0; i < n; ++i) {
        a[i].read();
        a[i].update(days);
    }

    int ret = 0;
    fill(h, h + M, -INF);
    for (int i = 0; i < D; ++i) if (days[i].size() > 0) {
        //puts("???");
        memcpy(nxth, h, sizeof(h));
        for (vector < Attack >::iterator it = days[i].begin(); it != days[i].end(); ++it) {
            //printf("%d: %d,%d %d\n", i, it->l, it->r, it->s);
            bool flag = false;
            for (int p = it->l; p < it->r; ++p) {
                int pos = p + BASE;
                if (it->s > h[pos])
                    flag = true;
                nxth[pos] = max(nxth[pos], it->s);
            }
            ret += flag;
        }
        memcpy(h, nxth, sizeof(nxth));
    }
    return ret;
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
        printf("Case #%d: %d\n", ++cas, solve());
    return 0;
}
