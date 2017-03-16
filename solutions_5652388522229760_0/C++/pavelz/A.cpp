// Description
// URL

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

bool used[10];
int totalUsed;

void check(int x) {
    while (x > 0) {
        int d = x % 10;
        if (!used[d]) {
            used[d] = true;
            totalUsed++;
        }
        x /= 10;
    }
}

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int c=1;c<=cases;c++) {
        int n;
        scanf("%d", &n);
        if (n > 0) {
            totalUsed = 0;
            FOR(i, sizeof(used) / sizeof(used[0])) used[i] = false;
            int x = n;
            while (true) {
                check(x);
                if (totalUsed == 10) break;
                x += n;
            }
            printf("Case #%d: %d\n", c, x);
        } else {
            printf("Case #%d: INSOMNIA\n", c);
        }
    }
}
