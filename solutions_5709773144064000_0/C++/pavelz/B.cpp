// Buy farm as long as it lowers the time to get X cookies
// https://code.google.com/codejam/contest/2974486/dashboard#s=p1
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
        double c, f, x;
        scanf("%lf%lf%lf", &c, &f, &x);

        double speed = 2;
        double totalTime = 0;
        while (x / speed > c / speed + x / (speed + f)) {
            totalTime += c / speed;
            speed += f;
        }
        totalTime += x / speed;
        printf("Case #%d: %.8lf\n", cc, totalTime);
    }
}
