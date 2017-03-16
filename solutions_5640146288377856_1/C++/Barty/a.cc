#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T, ca, r, c, w;
int main() {
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d%d", &r, &c, &w);
        int res = 0;

        if (c % w) {
            res = (c / w + w) + (r - 1) * c / w;
        } else {
            res = (c / w + w - 1) + (r - 1) * c / w;
        }
        printf("Case #%d: %d\n", ca, res);
    }
    return 0;
}
