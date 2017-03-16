#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPF(i, a, b) for (int i = (a); i <= (b); ++i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
const int maxint = -1u>>1;
const int maxn = 1000 + 4;

int n;
int tag[maxn];
pair<int, int> lv[maxn];

pair<int, int> get_oper(int now) {
    for (int i = 0; i < n; ++i) {
        if (tag[i] < 2 && now >= lv[i].second) return make_pair(i, 2);
    }
    for (int i = 0; i < n; ++i) {
        if (tag[i] < 1 && now >= lv[i].first) return make_pair(i, 1);
    }
    return make_pair(-1, 0);
}
bool cmp(const pair<int, int> &x1, const pair<int, int> &x2) {
    return x1.second > x2.second;
}
int main() {
    freopen("b.out", "w", stdout);
    int t, ca = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ++ca);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &lv[i].first, &lv[i].second);
            tag[i] = 0;
        }
        sort(lv, lv + n, cmp);
        int now = 0, ans = 0;
        while (now < n * 2) {
            pair<int, int> op = get_oper(now);
            if (op.first == -1) break;
            ++ans;
            now += op.second - tag[op.first];
            tag[op.first] = op.second;
        }
        if (now < n * 2) printf("Too Bad\n");
        else printf("%d\n", ans);
    }
    return 0;
}

