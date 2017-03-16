//
// https://code.google.com/codejam/contest/6224486/dashboard#s=p1
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_P 1010

int count[MAX_P];

char c = 0;
int getInt() {
    int r = 0;
    while (!(c >= '0' && c <= '9')) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return r;
}

int solve(int level) {
    while (count[level] == 0) level--;
    if (level <= 2) return level;
    else {
        int result = level;
        count[level]--;
        FORE(i, 2, level - 1) {
            int h1 = i;
            int h2 = level - h1;
            count[h1]++;
            count[h2]++;
            int result1 = solve(level) + 1;
            if (result1 < result) {
                result = result1;
                //if (level == 9) printf("%d = %d, ", i, result);
            }
            count[h1]--;
            count[h2]--;
        }
        count[level]++;

        /*int t = count[0];
        FOR(i, level) count[i] = count[i + 1];
        count[level] = 0;
        int result2 = solve(level - 1) + 1;
        for(int i=level;i>0;i--) count[i] = count[i - 1];
        count[0] = t;
        if (result2 < result) result = result2;*/
        return result;
    }
}

int main(void) {
    int cases = getInt();
    for(int c=1;c<=cases;c++) {
        FOR(i, MAX_P) count[i] = 0;
        int d = getInt();
        FOR(i, d) {
            int x = getInt();
            count[x]++;
            //printf("%d ", x);
        }
        printf("Case #%d: %d\n", c, solve(MAX_P - 1));
    }
}
