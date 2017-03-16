//
// https://code.google.com/codejam/contest/6224486/dashboard#s=p3
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
    for(int cc=1;cc<=cases;cc++) {
        int x, r, c;
        scanf("%d %d %d", &x, &r, &c);
        bool firstWins = false;
        if (x == 1) firstWins = false;
        else if (x == 2) firstWins = r * c % 2 != 0;
        else if (x == 3) {
            if (r * c % 3 != 0) firstWins = true;
            else firstWins = r * c == 3;
        } else if (x == 4) {
            if (r * c % 4 != 0) firstWins = true;
            else firstWins = r * c == 4 || r * c == 8;
        }

        printf("Case #%d: %s\n", cc, firstWins ? "RICHARD" : "GABRIEL");
    }
}
