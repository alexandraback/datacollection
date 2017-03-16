#include <stdio.h>
#include <string.h>
#include <math.h>

int cases, kejs;
long long i;
int j;
long long A, B;
long long q[100];
int nq;

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

int main() {
    for (i = 1; i <= 10000000; i++) {
        if (ispal(i) && ispal(i*i)) {
            q[nq++] = i*i;
        }
    }

    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        scanf("%lld", &A);
        scanf("%lld", &B);
        j = 0;
        for (i = 0; i < nq; i++) {
            j += (q[i] >= A && q[i] <= B);
        }
        printf("%d\n", j);
    }
   
    return 0;
}
