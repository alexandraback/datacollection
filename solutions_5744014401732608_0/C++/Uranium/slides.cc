#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <algorithm>

#define MAXB 50

void solve(int t_case, int B, int64_t M)
{
    if (M > (1LL << (B-2))) {
        printf("Case #%d: IMPOSSIBLE\n", t_case);
        return;
    }

    bool E[MAXB][MAXB];
    std::fill(&E[0][0], &E[MAXB][0], false);

    for (int i = 1; i < B; ++i) {
        E[0][i] = true;
    }

    for (int i = 1; i < B-1; ++i) {
        for (int j = i+1; j < B-1; ++j) {
            E[i][j] = true;
        }
    }

    M--;

    int deg = B-2;
    while (deg >= 0) {
        int64_t pw = 1LL << deg;
        if (pw <= M) {
            E[deg+1][B-1] = true;
            M -= pw;
        }
        deg--;
    }

    printf("Case #%d: POSSIBLE\n", t_case);
    for (int i = 0; i < B; ++i) {
        for (int j = 0; j < B; ++j) {
            printf("%d", E[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

int main()
{
    int T, B;
    int64_t M;

    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d%" SCNd64, &B, &M);
        solve(i, B, M);
    }

    return 0;
}
