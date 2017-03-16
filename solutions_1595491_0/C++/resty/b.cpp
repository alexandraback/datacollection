#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int cc = 1; cc <= T; ++cc) {
        int N, S, p;
        int best = 0, need_s = 0;
        scanf("%d%d%d", &N, &S, &p);
        for (int i = 0; i < N; ++i)
        {
            int k;
            scanf("%d", &k);
            if (k % 3 == 0) {
                if (k / 3 >= p) {
                    ++best;
                } else if (k > 0 && k / 3 + 1 >= p) {
                    ++need_s;
                }
            } else if (k % 3 == 1) {
                if (k / 3 + 1 >= p) {
                    ++best;
                }
            } else {
                if (k / 3 + 1 >= p) {
                    ++best;
                } else if (k / 3 + 2 >= p) {
                    ++need_s;
                }
            }
        }
        printf("Case #%d: %d\n", cc, best + min(S, need_s));
    }
    return 0;
}
