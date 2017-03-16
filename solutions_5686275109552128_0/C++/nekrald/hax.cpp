#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int SZ = 1111;
int d, p[SZ], need[SZ][SZ];

int solve() {
    memset(p, 0, sizeof(p));
    memset(need, 0, sizeof(need));
    scanf("%d", &d);
    int maxv = 0;
    for (int i = 0; i < d; ++i) {
        scanf("%d", p + i);
        maxv = max(maxv, p[i]);
    }
    for (int ps = 0; ps < d; ++ps) {
        for (int etm = 1; etm <= maxv; ++etm) {
            need[ps][etm] = ((p[ps] + etm - 1) / etm) - 1;
        }
    }
    int ans = maxv;
    for (int etm = 1; etm <= maxv; ++etm) {
        int cand = etm;
        for (int ps = 0; ps < d; ++ps) {
            cand += need[ps][etm];
        }
        ans = min(ans, cand);
    }
    return ans;
}

int main() {
    int T; scanf("%d", &T);
    for (int _ = 1; _ <= T; ++_) {
        printf("Case #%d: %d\n", _, solve());
    }
    return 0;
}
