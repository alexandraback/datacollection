#include <iostream>
#include <stdio.h>
#include <algorithm>
#define s(n) scanf("%lld", &n)
#define lli long long int

using namespace std;

int main() {
    lli T, B, M;
    lli p[50];
    p[1] = 1;
    p[2] = 1;
    for (int i = 3; i <= 50; i++) {
        p[i] = p[i - 1] * 2;
    }
    s(T);
    int ans[52][52];
    lli j, k;
    for (j = 1; j < 52; j++) {
        for (k = j + 1; k < 52; k++)
            ans[j][k] = 1;
    }
    for (lli i = 1; i <= T; i++) {
        s(B);
        s(M);
        if (M > p[B])
            printf("Case #%lld: IMPOSSIBLE\n", i);
        else {
            printf("Case #%lld: POSSIBLE\n", i);

            for (k = 0; k < B; k++)
                ans[0][k] = 0;
            // for (j = 1; j < B; j++) {
            // for (k = 0; k < B; k++) {
            // ans[j][k] = 1;
            //}
            //}

            for (j = B - 1; j >= 1; j--) {
                if (M >= p[j]) {
                    ans[0][B - j] = 1;
                    M -= p[j];
                }
            }

            for (j = 0; j < B; j++) {
                for (k = 0; k < B; k++) {
                    printf("%d", ans[j][k]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
