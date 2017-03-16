#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int c=1;c<=cases;c++) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        int total = 0;
        FOR(i, a) FOR(j, b) if ((i & j) < k) total++;
        printf("Case #%d: %d\n", c, total);
    }
}
