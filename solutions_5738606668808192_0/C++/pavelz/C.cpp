// Description
// https://code.google.com/codejam/contest/6254486/dashboard#s=p2

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


int calcMod(int base, int mod, int *data, int dataSize) {
    int result = 0;
    int power = 1;
    for(int i=dataSize - 1;i>=0;i--) {
        result = (result + data[i] * power) % mod;
        power = power * base % mod;
    }
    return result;
}

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int c=1;c<=cases;c++) {
        int n, jj;
        int bits[40];
        int proof[11];
        scanf("%d %d", &n, &jj);

        printf("Case #%d:\n", c);

        bits[0] = bits[n - 1] = 1;
        FOR(i, 1 << (n- 2)) {
            int temp = i;
            FOR(j, n - 2) {
                bits[j + 1] = temp & 1;
                temp >>= 1;
            }
            bool ok2 = true;
            FORE(j, 2, 11) {
                bool ok = false;
                FORE(k, 2, 200)
                    if (calcMod(j, k, bits, n) == 0) {
                        proof[j] = k;
                        ok = true;
                        break;
                    }
                if (!ok) {
                    ok2 = false;
                    break;
                }
            }
            if (ok2) {
                FOR(j, n) printf("%d", bits[j]);
                FORE(j, 2, 11) printf(" %d", proof[j]);
                printf("\n");
                jj--;
                if (jj == 0) break;
            }
        }
    }
}
