#include <stdio.h>
#include <string.h>

void solve() {
    int len, generations, selections;
    scanf("%d%d%d", &len, &generations, &selections);

    if (len > selections * generations) {
        printf(" IMPOSSIBLE\n");
        return;
    }

    for (int i = 0; i < len; i += generations) {
        unsigned long long pos = 0;
        for (int j = i; j < i + generations && j < len; ++j) {
            pos *= (unsigned long long)len;
            pos += (unsigned long long)j;
        }
        printf(" %llu", pos + 1);
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