// Just brute force solution
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

#define MAX_TOTAL_POS 20

struct Hiker {
    int start;
    int time;
} hikers[10];

char cc = 0;
int getInt() {
    int r = 0;
    while (!(cc >= '0' && cc <= '9')) cc = getc_unlocked(stdin);
    while (cc >= '0' && cc <= '9') {
        r = r * 10 + (cc - '0');
        cc = getc_unlocked(stdin);
    }
    return r;
}

int main(void) {
    int cases = getInt();
    for(int cc=1;cc<=cases;cc++) {
        int n = getInt();
        int totalHikers = 0;
        FOR(i, n) {
            int d = getInt();
            int h = getInt();
            int m = getInt();
            FOR(j, h) {
                hikers[totalHikers].start = d;
                hikers[totalHikers].time = m + j;
                totalHikers++;
            }
        }
        int result = 0;
        if (totalHikers == 1) result = 0;
        else if (totalHikers == 2) {
            if (hikers[0].time == hikers[1].time) result = 0;
            else {
                if (hikers[0].time > hikers[1].time) {
                    int t = hikers[0].time;
                    hikers[0].time = hikers[1].time;
                    hikers[1].time = t;

                    t = hikers[0].start;
                    hikers[0].start = hikers[1].start;
                    hikers[1].start = t;
                }
                double slowTime = ((double)(360 - hikers[1].start)) / 360 * hikers[1].time;
                double fastPos = hikers[0].start + slowTime / hikers[0].time * 360;
                //printf("%lf\n", slowTime);
                if (fastPos >= 720) result = 1;
            }
        }

        printf("Case #%d: %d\n", cc, result);
    }
}
