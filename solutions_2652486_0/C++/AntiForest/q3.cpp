#include <cstdio>

int T, R, N, M, K;
int cId, cProd;
int v[100], g[100];
int hasA[10000];

bool foundAns;

void checkAns() {
    cId++;
    for (int i = 0; i < (1<<N); i++) {
        cProd = 1;
        for (int p = 0; p < N; p++) {
            if (i & (1<<p)) {
                cProd *= v[p];
            }
        }
        hasA[cProd] = cId;
    }
    for (int i = 0; i < K; i++) {
        if (hasA[g[i]] != cId) return;
    }
    for (int i = 0; i < N; i++) {
        printf ("%d", v[i]);
    }
    printf ("\n");
    foundAns = true;
    return;
}

void fAns(int c) {
    if (c == N) {
        if (!foundAns) {
            checkAns();
        }
        return;
    }
    for (int i = 2; i <= M; i++) {
        v[c] = i;
        fAns (c+1);
    }
    return;
}

int main() {
    freopen ("q3.in", "r", stdin);
    freopen ("q3.out", "w", stdout);
    scanf ("%d", &T);
    printf ("Case #1:\n");
    scanf ("%d %d %d %d", &R, &N, &M, &K);
    for (int _z = 0; _z < R; _z++) {
        for (int i = 0; i < K; i++) {
            scanf ("%d", &g[i]);
        }
        foundAns = false;
        fAns(0);
        if (!foundAns) {
            for (int i = 0; i < N; i++) {
                printf ("2");
            }
            printf ("\n");
        }
    }
    return 0;
}
