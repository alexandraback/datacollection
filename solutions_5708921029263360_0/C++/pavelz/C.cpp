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

int j, p, s, k;
bool usedTriple[100];
int usedDouble[3][100];
int mx = 0;
int result[1000][3];

void deuse(int a, int b, int c) {
    usedTriple[a * p * s + b * s + c] = false;
    usedDouble[0][a * p + b]--;
    usedDouble[1][a * s + c]--;
    usedDouble[2][b * s + c]--;
}

bool use(int a, int b, int c) {
    if (usedTriple[a * p * s + b * s + c]) return false;
    if (usedDouble[0][a * p + b] >= k || usedDouble[1][a * s + c] >= k || usedDouble[2][b * s + c] >= k) return false;
    usedTriple[a * p * s + b * s + c] = true;
    usedDouble[0][a * p + b]++;
    usedDouble[1][a * s + c]++;
    usedDouble[2][b * s + c]++;
    return true;
}

void getMax(int level, int lastA) {
    if (level > mx) mx = level;
    FORE(a, lastA, j) FOR(b, p) FOR(c, s) {
        if (use(a, b, c)) {
            getMax(level + 1, a);
            deuse(a, b, c);
        }
    }
    //return result;
}

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int cc=1;cc<=cases;cc++) {
        scanf("%d %d %d %d", &j, &p, &s, &k);
        mx = 0;
        /*use(0, 0, 0);
        getMax(0, 0);*/
        int total = j * p * s;
        if (k >= 3) {
            mx = total - 1;
            int pos = 0;
            FOR(a, j) FOR(b, p) FOR(c, s) {
                result[pos][0] = a;
                result[pos][1] = b;
                result[pos][2] = c;
                pos++;
            }
        } else {
            FOR(i, 1 << (total - 1)) {
                FOR(a, 3) FOR(b, 9) usedDouble[a][b] = 0;
                usedDouble[0][0] = usedDouble[1][0] = usedDouble[2][0] = 1;
                int t = i;
                int res = 0;
                bool ok = true;
                FORE(x, 1, total) {
                    if ((t & 1) == 1) {
                        int a = x / p / s;
                        int b = (x - a * p * s) / s;
                        int c = x % s;
                        //printf("%d %d %d\n", a, b, c);
                        if (usedDouble[0][a * p + b] >= k || usedDouble[1][a * s + c] >= k || usedDouble[2][b * s + c] >= k) {
                            ok = false;
                            break;
                        }
                        usedDouble[0][a * p + b]++;
                        usedDouble[1][a * s + c]++;
                        usedDouble[2][b * s + c]++;
                        res++;
                    }
                    t >>= 1;
                }
                if (ok && res > mx) {
                    mx = res;
                    int pos = 0;
                    int t = i;
                    FORE(x, 1, total) {
                        if ((t & 1) == 1) {
                            int a = x / p / s;
                            int b = (x - a * p * s) / s;
                            int c = x % s;
                            result[pos][0] = a;
                            result[pos][1] = b;
                            result[pos][2] = c;
                            pos++;
                        }
                        t >>= 1;
                    }
                    result[pos][0] = result[pos][1] = result[pos][2] = 0;
                }

            }
        }

        printf("Case #%d: %d\n", cc, mx + 1);
        FOR(i, mx + 1) printf("%d %d %d\n", result[i][0] + 1, result[i][1] + 1, result[i][2] + 1);
    }
}
