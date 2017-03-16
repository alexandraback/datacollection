#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double p[100001];
int main() {
    int T, casenum, A, B, i;
    scanf("%d", &T);
    for(casenum=1; casenum<=T; casenum++) {
        scanf("%d%d", &A, &B);
        for(i=0; i<A; i++) 
            scanf("%lf", &p[i]);
        double mn = 2 + B, x=1, v;
        for(i=0; i<=A; i++) {
            v = (A-i +-i+B +1) + (1-x)*(B+1);
            if (v < mn) mn = v;
            x *= p[i];
        }
        printf("Case #%d: %lf\n", casenum, mn);
    }
    return 0;
}
