#include <cstdio>

using namespace std;

int main() {
    int t, k, c, s;
    int tc, i, j, l;

    scanf("%d", &t);
    for (tc = 1; tc <= t; tc++) {
        scanf("%d %d %d", &k, &c, &s);
        printf("Case #%d: ", tc);
        if (k == s) {
            for (i = 1; i < k; i++) {
                printf("%d ", i);
            }
            printf("%d\n", k);
        } else {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
