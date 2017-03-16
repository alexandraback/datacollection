#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);
        if (c * s < k) {
            printf("Case #%d: IMPOSSIBLE", i);
        } else {
            printf("Case #%d:", i);
            for (int j = 0; j < k;) {
                long long l = 0;
                for (int n = 0; n < c; ++n) {
                    l = l * k + (j >= k ? 0 : j);
                    ++j;
                }
                cout << ' ' << (l + 1);
            }
        }
        if (i + 1 <= T) {
            printf("\n");
        }
    }
    return 0;
}
