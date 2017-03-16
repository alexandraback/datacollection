// Description
// https://code.google.com/codejam/contest/11254486/dashboard#s=p1

#include <bits/stdc++.h>
using namespace std;

#define FOR(c, m) for(int c=0;c<(int)(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)
#define LLI long long int
#define MOD 1000000007

int power(int a, int b) {
    int sq = a;
    int result = 1;
    while (b > 0) {
        if ((b & 1) == 1) result = result * (LLI)sq % MOD;
        sq = sq * (LLI)sq % MOD;
        b >>= 1;
    }
    return result;
}

int inv(int a) {
    return power(a, MOD - 2);
}

void fail() {
    *((char *)0) = 0;
}


#define MAX_L 20
char ci[MAX_L], ji[MAX_L];
char cr[MAX_L], jr[MAX_L];

int pp(int x) {
    int result = 1;
    FOR(i, x) result *= 10;
    return result;
}

void conv(int v, char *dst, int l) {
    dst[l] = 0;
    while (--l >= 0) {
        dst[l] = v % 10 + '0';
        v /= 10;
    }
    //printf("Converting %d, result: %s\n", tt, dst);
}

bool eq(int v, char *input, int l) {
    char tmp[MAX_L];
    //printf("Eq: %d %s %d\n", v, input, l);
    conv(v, tmp, l);
    FOR(i, l) if (tmp[i] != input[i] && input[i] != '?') return false;
    return true;
}

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int cc=1;cc<=cases;cc++) {
        scanf("%s %s", ci, ji);
        int lc = strlen(ci);
        int lj = strlen(ji);
        int mc = pp(lc);
        int mj = pp(lj);

        //printf("%d %d\n", mc, mj);
        int mm = mc + mj;
        FOR(i, mc) FOR(j, mj) {
            if (eq(i, ci, lc) && eq(j, ji, lj) && abs(i - j) < mm) {
                mm = abs(i - j);
                conv(i, cr, lc);
                conv(j, jr, lj);
            }
        }
        printf("Case #%d: %s %s\n", cc, cr, jr);
    }
}

