#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int M;

int A[120][60];

const int maxN = 2600;

int C[maxN];

void solve() {
    memset(C, 0, sizeof(C));
    for (int i = 0; i < M; ++ i)
        for (int j = 0; j < N; ++ j)
            ++ C[A[i][j]];
    for (int i = 1; i <= 2500; ++ i)
        if (C[i] % 2 != 0)
            printf(" %d", i);
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++ test) {
        scanf("%d", &N);
        M = 2 * N - 1;
        for (int i = 0; i < M; ++ i)
            for (int j = 0; j < N; ++ j)
                scanf("%d", &A[i][j]);
        printf("Case #%d:", test);
        solve();
    }
    return 0;
}
