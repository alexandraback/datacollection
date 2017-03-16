#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

#define MAX_K 12
using namespace std;

int N, M, K;
long long P[MAX_K];

int f2[MAX_K];
int f3[MAX_K];
int f5[MAX_K];
int f7[MAX_K];

int digit[9];

void solve() {
    memset(f2, 0, sizeof(f2));
    memset(f3, 0, sizeof(f3));
    memset(f5, 0, sizeof(f5));
    memset(f7, 0, sizeof(f7));

    for (int i = 0; i < K; i++) {
        while (P[i] % 2 == 0) {
            P[i] /= 2;
            f2[i]++;
        }
        while (P[i] % 3 == 0) {
            P[i] /= 3;
            f3[i]++;
        }
        while (P[i] % 5 == 0) {
            P[i] /= 5;
            f5[i]++;
        }
        while (P[i] % 7 == 0) {
            P[i] /= 7;
            f7[i]++;
        }
    }

    memset(digit, 0, sizeof(digit));
    int sum2 = 0;
    int sum3 = 0;
    int sum5 = 0;
    int max2 = 0;
    int max3 = 0;
    int max5 = 0;
    for (int i = 0; i < K; i++) {
        sum2 += f2[i];
        sum3 += f3[i];
        sum5 += f5[i];
        max2 = max(max2, f2[i]);
        max3 = max(max3, f3[i]);
        max5 = max(max5, f5[i]);
    }
    digit[3] = max3;
    digit[5] = max5;

    int slot = N - digit[3] - digit[5];
    if (max2 == slot * 2) {
        digit[4] = slot;
        return;
    } else if (max2 > slot) {
        digit[4] = max2 - slot;
        slot -= digit[4];
    }

    double p2 = max(0., (double)sum2 / (double)K - digit[4] * 2 * 0.5);
    double p3 = max(0., (double)sum3 / (double)K - digit[3] * 0.5);
    double p5 = max(0., (double)sum5 / (double)K - digit[5] * 0.5);
    double p4 = 0.;

    if (p2 + p3 + p5 > slot) {
        p4 = (p2 + p3 + p5 - slot) / 2;
        p2 -= p4*2;
    }
        
    if (p2 + p3 + p4 + p5 == 0.)
        p2 = 1.;
    double p2n = p2 / (p2 + p3 + p4 + p5) * slot;
    double p3n = p3 / (p2 + p3 + p4 + p5) * slot;
    double p4n = p4 / (p2 + p3 + p4 + p5) * slot;
    double p5n = p5 / (p2 + p3 + p4 + p5) * slot;

    for (int i = 1; i <= slot; i++) {
        if (p2n >= i)
            digit[2]++;
        else if (p2n + p3n >= i)
            digit[3]++;
        else if (p2n + p3n + p4n >= i)
            digit[4]++;
        else
            digit[5]++;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; testcase++) {
        printf("Case #%d:\n", testcase);

        int R;
        scanf("%d%d%d%d", &R, &N, &M, &K);
        for (int r = 0; r < R; r++) {
            for (int i = 0; i < K; i++)
                scanf("%lld", &P[i]);
            solve();
            for (int i = 2; i <= M; i++)
                for (int j = 0; j < digit[i]; j++)
                    printf("%d", i);
            printf("\n");
        }
    }
    return 0;
}
