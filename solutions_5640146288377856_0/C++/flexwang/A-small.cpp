#include <bits/stdc++.h>
using namespace std;

int T, r, c, w, f[21][21];

int miss(int c, int w) {
    if (f[c][w] != -1) return f[c][w];
    if (c == 1) return 0;
    int ret = c;
    for (int i = 0; i < w && i < c - 1; ++i) {
        ret = min(ret, max(miss(i + 1, w), miss(c - i - 1, w) + 1));
    }
    return f[c][w] = ret;
}
void init() {
    memset(f, -1, sizeof(f));
}
int main() {
    init();
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d%d%d", &r, &c, &w);
        int ans = c / w * (r - 1) + miss(c - w + 1, w) + w;
        printf("Case #%d: %d\n", cas, ans);
    }
}
