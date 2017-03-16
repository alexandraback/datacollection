#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, R, C, W;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &R, &C, &W);
        int ans = C / W * R + (W - 1);
        if (C % W) {
            ++ans;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
