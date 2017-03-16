#include <stdio.h>
int main() {
    int T; scanf("%d", &T);
    int c = 1;
    while (T--) {
        int A, B; scanf("%d %d", &A, &B);
        int n = 0;
        int x[] = {1,4,9,121,484};
        int i;
        for (i = 5; i--;)
            if (A <= x[i] && B >= x[i])
                n++;
        printf("Case #%d: %d\n", c++, n);
    }
}
