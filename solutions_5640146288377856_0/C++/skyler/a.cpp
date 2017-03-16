#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int T, r, c, w;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d%d%d", &r, &c, &w);
        int ans = r * (c / w) + w - 1;
        if (c % w) ans++;
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
