// Description
// https://code.google.com/codejam/contest/6254486/dashboard#s=p3

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



int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int cc=1;cc<=cases;cc++) {
        int k, c, s;
        scanf("%d %d %d", &k, &c, &s);
        int m = (k + c - 1) / c;
        printf("Case #%d:", cc);
        if (s < m) printf(" IMPOSSIBLE"); else {
            LLI result = 0;
            int group = c;
            FOR(i, k) {
                result = result * k + i;
                if (--group == 0) {
                    printf(" %lld", result + 1);
                    group = c;
                    result = 0;
                }
            }
            if (group != c) printf(" %lld", result + 1);
        }
        printf("\n");
    }
}
