#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n, s[2], t[2], ans = 2;
        double spd[2];
        scanf("%d", &n);
        for (int i = 0, k = 0; i < n; ++i) {
            int d, h, m;
            scanf("%d%d%d", &d, &h, &m);
            for (int j = 0; j < h; ++j, ++k) {
                s[k] = d;
                t[k] = m + j;
                spd[k] = 360.0 / t[k];
            }
        }
        if (spd[0] > spd[1]) {
            swap(s[0], s[1]);
            swap(t[0], t[1]);
            swap(spd[0], spd[1]);
        }
        int dis = s[0] > s[1] ? s[0] - s[1] : s[0] - s[1] + 360;
        double tt = (360.0 - s[0]) / spd[0];
        double l = tt * (spd[1] - spd[0]);
        if (l >= dis - eps) {
            ans = 1;
        } else {
            ans = 0;
        }
        printf("Case #%d: %d\n", cas, ans);
    }
}
