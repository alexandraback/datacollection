#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

struct state {
    long long c, d;
};

long long d10[22];
char c[32], d[32];

state dp[32][32][2];

int n;
long long bc, bd;

state getDP(int pc, int pd, int bi) {
    if (dp[pc][pd][bi].c != -1) {
        return dp[pc][pd][bi];
    }
    if (pc >= n && pd >= n) {
        state r;
        r.c = r.d = 0;
        return r;
    }
    state sol;
    sol.c = bc;
    sol.d = bd;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int cq, dq;
            cq = dq = 0;
            if (c[pc] == '?') {
                cq = 1;
                c[pc] = '0' + i;
            }
            if (d[pd] == '?') {
                dq = 1;
                d[pd] = '0' + j;
            }

            if (!bi) {
                if (c[pc] > d[pd]) {
                    state ne = getDP(pc + 1, pd + 1, 1);
                    ne.c = ne.c + d10[n - 1 - pc] * (c[pc] - '0');
                    ne.d = ne.d + d10[n - 1 - pd] * (d[pd] - '0');
                    if (ne.c - ne.d < sol.c - sol.d) {
                        sol = ne;
                    } else if (ne.c - ne.d == sol.c - sol.d) {
                        if (ne.c < sol.c) {
                            sol = ne;
                        }
                    }
                } else if (c[pc] == d[pd]) {
                    state ne = getDP(pc + 1, pd + 1, 0);
                    ne.c = ne.c + d10[n - 1 - pc] * (c[pc] - '0');
                    ne.d = ne.d + d10[n - 1 - pd] * (d[pd] - '0');
                    if (ne.c - ne.d < sol.c - sol.d) {
                        sol = ne;
                    } else if (ne.c - ne.d == sol.c - sol.d) {
                        if (ne.c < sol.c) {
                            sol = ne;
                        }
                    }
                }
            } else {
                state ne;
                ne = getDP(pc + 1, pd + 1, 1);
                ne.c = ne.c + d10[n - 1 - pc] * (c[pc] - '0');
                ne.d = ne.d + d10[n - 1 - pd] * (d[pd] - '0');
                if (ne.c - ne.d < sol.c - sol.d) {
                    sol = ne;
                } else if (ne.c - ne.d == sol.c - sol.d) {
                    if (ne.c < sol.c) {
                        sol = ne;
                    }
                }
            }

            if (cq) {
                c[pc] = '?';
            }
            if (dq) {
                d[pd] = '?';
            }
        }
    }
    dp[pc][pd][bi] = sol;
    // printf("DP %d %d %d :: %lld %lld\n", pc, pd, bi, sol.c, sol.d);
    return sol;
}

int main() {
    d10[0] = 1;
    for (int i = 1; i <= 19; ++i) {
        d10[i] = d10[i - 1] * 10;
    }
    int T;
    scanf("%d", &T);
    for (int te = 1; te <= T; ++te) {
        scanf("%s %s", c, d);
        n = strlen(c);
        bc = d10[18];
        bd = -d10[18];
        memset(dp, -1, sizeof(dp));
        state s1 = getDP(0, 0, 0);
        memset(dp, -1, sizeof(dp));
        swap(c, d);
        state s2 = getDP(0, 0, 0);
        // printf("S1 %lld %lld :: %lld %lld\n", s1.c, s1.d, s2.c, s2.d);
        if (s1.c - s1.d < s2.c - s2.d) {
            bc = s1.c;
            bd = s1.d;
        } else if (s2.c - s2.d < s1.c - s1.d) {
            bc = s2.d;
            bd = s2.c;
        } else {
            if (s1.c < s2.d) {
                bc = s1.c;
                bd = s1.d;
            } else if (s1.c > s2.d) {
                bc = s2.d;
                bd = s2.c;
            } else {
                if (s1.d < s2.c) {
                    bc = s1.c;
                    bd = s1.d;
                } else {
                    bc = s2.d;
                    bd = s2.c;
                }
            }
        }
        cout << "Case #" << te << ": " << setw(n) << setfill('0') << bc << " " << 
            setw(n) << setfill('0') << bd << endl;
    }
    return 0;
}
