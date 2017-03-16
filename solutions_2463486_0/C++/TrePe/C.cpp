#include <stdio.h>
#include <string.h>
#include <math.h>

int cases, kejs;
int i, j;
long long A, B;

bool ispal(long long a) {
    static char s[1000];
    static int i, n;
    sprintf(s, "%lld", a);
    n = strlen(s);
    for (i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

bool issquare(long long a) {
    static long long s;
    s = (long long) sqrt((double) a);
    return s*s == a;
}

int main() {
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        scanf("%lld", &A);
        scanf("%lld", &B);
        j = 0;
        for (i = A; i <= B; i++) {
            j += (issquare(i) && ispal(i) && ispal(sqrt((double)i)));
        }
        printf("%d\n", j);
    }
    return 0;
}
