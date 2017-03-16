#include <cstdio>
#include <cstdlib>

int B;
long long M;

long long cache[55];
bool slide[55][55];

long long f(int b, long long m) {
    // printf("calling f(%d, %lld)\n", b, m);
    if (b == B - 1) return 1;
    if (cache[b]) return cache[b];

    long long best = 0;
    for (int i = b + 1; i < B; ++i) {
        // printf("b = %d, i = %d\n", b, i);

        slide[b][i] = true;

        long long r = f(i, m - best);
        if (best + r > m) {
            continue;
        }
        if (best + r == m) {
            best = m;
            break;
        }
        best += r;
    }

    cache[b] = best;
    // printf("f(%d, %lld) = %lld\n", b, m, best);
    return best;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int c = 1; c <= T; ++c) {
        scanf("%d %lld", &B, &M);

        for (int i = 0; i < 55; ++i) {
            cache[i] = 0;
            for (int j = 0; j < 55; ++j) {
                slide[i][j] = false;
            }
        }
        
        if (f(0, M) == M) {
            printf("Case #%d: POSSIBLE\n", c);
            for (int i = 0; i < B; ++i) {
                for (int j = 0; j < B; ++j) {
                    if (slide[i][j]) {
                        printf("1");
                    } else {
                        printf("0");
                    }
                }
                printf("\n");
            }
        } else {
            printf("Case #%d: IMPOSSIBLE\n", c);
        }
    }
}
