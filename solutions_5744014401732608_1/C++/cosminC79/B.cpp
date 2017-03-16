#include <cstdio>
#include <cstring>
const int NMAX = 55;
int tests, N;
long long M;

bool mat[NMAX][NMAX];

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);

    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d: ", test);
        scanf("%d%lld", &N, &M);

        memset(mat, false, sizeof(mat));
        for (int i = 2; i < N; i++) {
            for (int j = 1; j < i; j++) {
                mat[j][i] = true;
            }
        }

        if (M > (1LL << (N - 2))) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("POSSIBLE\n");
            if (M == (1LL << (N - 2))) {
                mat[1][N] = true;
                M--;
            }

            for (int j = 0; j < N - 2; j++) {
                if (M & (1LL << j)) {
                    mat[2 + j][N] = true;
                }
            }

            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    printf("%d", mat[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
