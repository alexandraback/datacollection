// Start from the lowest shynes and add friends as necessary
// https://code.google.com/codejam/contest/6224486/dashboard#s=p0
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_S 2000

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int c=1;c<=cases;c++) {
        int sm;
        char data[MAX_S];
        scanf("%d %s", &sm, data);
        int add = 0;
        int standing = 0;
        FOR(i, sm + 1) {
            int curr = data[i] - '0';
            if (curr > 0) {
                if (standing < i) {
                    add += i - standing;
                    standing = i;
                }
                standing += curr;
            }
        }
        printf("Case #%d: %d\n", c, add);
    }
}
