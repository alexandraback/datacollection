#include <cstdio>
#include <algorithm>

using namespace std;

int coin[111];

int main() {
    int T, add, maxx, next_coin, c, d, v, i;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%d%d%d", &c, &d, &v);
        for (i = 0; i < d; i++) {
            scanf("%d", coin + i);
        }
        sort(coin, coin + d);
        maxx = 0;
        next_coin = 0;
        add = 0;
        while (maxx < v) {
            if (next_coin < d && coin[next_coin] <= maxx + 1) {
                maxx += coin[next_coin] * c;
                next_coin++;
            } else {
                add++;
                maxx += (maxx + 1) * c;
            }
        }
        printf("%d\n", add);
    }
    return 0;
}
