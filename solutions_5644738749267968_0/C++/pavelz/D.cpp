//
// https://code.google.com/codejam/contest/2974486/dashboard#s=p3
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_N 1500

double naomi[MAX_N], ken[MAX_N];
int n;


int cmp(const void *p1, const void *p2) {
    double d1 = (*(double *)p1);
    double d2 = (*(double *)p2);
    return d1 < d2 ? -1 : 1;
}

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int c=1;c<=cases;c++) {
        scanf("%d", &n);
        FOR(i, n) scanf("%lf", &naomi[i]);
        FOR(i, n) scanf("%lf", &ken[i]);

        qsort(naomi, n, sizeof(naomi[0]), cmp);
        qsort(ken, n, sizeof(ken[0]), cmp);

        int origWin = 0;
        int j = 0;
        FOR(i, n) {
            while (ken[j] < naomi[i] && j < n) j++;
            if (j == n) {
                origWin = n - i;
                break;
            } else {
                j++;
            }
        }

        int cheatWin = 0;
        int kStart = 0, kEnd = n - 1;
        FOR(i, n) {
            if (naomi[i] < ken[kStart]) {
                kEnd--;
            } else {
                cheatWin++;
                kStart++;
            }
        }
        printf("Case #%d: %d %d\n", c, cheatWin, origWin);
    }
}
