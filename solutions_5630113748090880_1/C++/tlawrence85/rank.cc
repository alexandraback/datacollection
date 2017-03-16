#include <stdio.h>
#include <string.h>

void solve() {
    int dim;
    int seen[2501];
    memset(seen, 0, sizeof(seen));
    scanf("%d", &dim);
    for (int i = 0; i < 2 * dim - 1; ++i) {
        for (int j = 0; j < dim; ++j) {
            int num;
            scanf("%d", &num);
            seen[num]++;
        }
    }

    for (int i = 1; i <= 2500; ++i) {
        if (seen[i] % 2 == 1) printf(" %d", i);
    }
    printf("\n");
}

int main(void) {
    int nC;
    scanf("%d", &nC);
    for (int cC = 0; cC < nC; ++cC) {
        printf("Case #%d:", cC + 1);
        solve();
    }
    return 0;
}