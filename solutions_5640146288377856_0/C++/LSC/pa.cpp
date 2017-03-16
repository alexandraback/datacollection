#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int r, c, w;
        scanf("%d%d%d", &r, &c, &w);
        int ans = (r - 1) * (c / w) + c / w + w;
        if (c - (c / w - 1) * w == w) ans--;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
