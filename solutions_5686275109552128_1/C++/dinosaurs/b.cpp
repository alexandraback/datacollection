#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int T, D, P[1010];

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d", &D);
        for (int i = 0; i < D; ++i) {
            scanf("%d", &P[i]);
        }

        int best = 1000;
        for (int i = 1; i <= 1000; ++i) { // # eats
            int special = 0;
            for (int j = 0; j < D; ++j) {
                special += (P[j] - 1) / i;
            }
            if (special + i < best) {
                best = special + i;
            }
        }

        printf("Case #%d: %d\n", t, best);
    }

    return 0;
}
