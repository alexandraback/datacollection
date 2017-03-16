#include <cstdio>

using namespace std;

int main() {
    int t, K, C, S;

    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        printf("Case #%d: ", tc);
        scanf("%d %d %d", &K, &C, &S);
        if (C * S < K) {
            printf("IMPOSSIBLE\n");
        } else {
            int start = 0;
            int finished = 0;
            for (int i = 1; i <= S && !finished; i++) {
                long long pos = start++;
                if (start >= K) {
                    finished = 1;
                    start = K - 1;
                }
                for (int j = 2; j <= C; j++) {
                    pos *= (long long)K;
                    pos += (long long)start++;
                    if (start >= K) {
                        finished = 1;
                        start = K - 1;
                    }
                }
                if (i > 1) printf(" ");
                printf("%lld", pos + 1);
            }
            printf("\n");
        }
    }
    return 0;
}
