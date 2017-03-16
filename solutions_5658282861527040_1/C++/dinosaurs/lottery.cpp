#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXBITS = 33, LASTBIT = 30;

int T, A, B, K;
long long dp[MAXBITS][2][2][2]; // index of next bit to add, whether val LESS THAN a; b; k

int get(int val, int pos) {
    if ((1 << pos) & val) {
        return 1;
    } else {
        return 0;
    }
}

bool less_than(int cur, int next_bit, int actual_val, int pos) {
    bool less_than = (cur == 1);
    if (next_bit == 0 && get(actual_val, pos) == 1) {
        less_than = true;
    } else if (next_bit == 1 && get(actual_val, pos) == 0) {
        less_than = false;
    }
    return less_than;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &A, &B, &K);

        for (int i = 0; i < MAXBITS; i++) {
            for (int a = 0; a <= 1; a++) {
                for (int b = 0; b <= 1; b++) {
                    for (int k = 0; k <= 1; k++) {
                        dp[i][a][b][k] = 0;
                    }
                }
            }
        }

        dp[0][0][0][0] = 1;
        for (int i = 0; i < LASTBIT; i++) {
            for (int a = 0; a <= 1; a++) {
                for (int b = 0; b <= 1; b++) {
                    for (int k = 0; k <= 1; k++) {
                        if (dp[i][a][b][k] == 0) {
                            continue;
                        }

                        for (int next_a = 0; next_a <= 1; next_a++) {
                            for (int next_b = 0; next_b <= 1; next_b++) {
                                int next_k = next_a & next_b;

                                bool less_than_a = less_than(a, next_a, A, i);
                                bool less_than_b = less_than(b, next_b, B, i);
                                bool less_than_k = less_than(k, next_k, K, i);

                                dp[i + 1][less_than_a][less_than_b][less_than_k] += dp[i][a][b][k];
                            }
                        }
                    }
                }
            }
        }

        printf("Case #%d: %lld\n", t, dp[LASTBIT][1][1][1]);
    }

    return 0;
}
