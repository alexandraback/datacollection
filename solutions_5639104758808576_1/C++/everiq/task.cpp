#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int zz = 1; zz <= t; ++zz) {
        int smax;
        scanf("%d ", &smax);

        int f = 0;
        int s = 0;
        for (int i = 0; i <= smax; ++i) {
            char t = 0;
            scanf("%c", &t);
            s += t - '0';
            f += max(0, (i - s + 1));
            s = max(s, i+1);
            // printf("%d:%d(%d) ", i, s, f);
        }

        printf("Case #%d: %d\n", zz, f);
    }

    return 0;
}
