#include<cstdio>
#include<algorithm>
using namespace std;

int popcount[1 << 21];

void initPopcount() {
    popcount[0] = 0;
    for (int i=1; i<1<<21; i++) {
        popcount[i] = 1 + popcount[i & (i-1)];
    }
}

int pow2(int n) {
    int ans =1;
    while (n--) {
        ans *= 2;
    }
    return ans;
}


int abs(int n) {
    return n>0?n:(-1 * n);
}

int countK(int n) {
    int k=1;
    while (true) {
        if (k * (k+1) > 2*n) {
            k -= 2;
            return k;
        }
        k += 2;
    }
}

int main() {
    initPopcount();
    int Cssc; scanf("%d", &Cssc);
    for (int Case = 1; Case <= Cssc; Case++) {
        int N, X, Y;
        scanf("%d%d%d", &N, &X, &Y);
        int K = countK(N);
        if (abs(X) + abs(Y) <= K-1) {
            printf("Case #%d: 1.0\n", Case);
            continue;
        }
        if (abs(X) + abs(Y) > K+1) {
            printf("Case #%d: 0.0\n", Case);
            continue;
        }
        if (0 == X) {
            printf("Case #%d: 0.0\n", Case);
            continue;
        }
        int T = N - ((K * (K+1)) / 2);
        if (Y + 1 > T) {
            printf("Case #%d: 0.0\n", Case);
            continue;
        }
        if (Y + 1 <= (T - K) - 1) {
            printf("Case #%d: 1.0\n", Case);
            continue;
        }
        int W = max(0, (T - K) - 1);
        int S = K + 1 - W;
        T = T - (2*W);
        Y = Y + 1 - W;
        int poss = 0;
        for (int i=0; i<(1<<T); i++) {
            if (popcount[i] >= Y)
                poss++;
        }
        double nom = poss;
        double den = pow2(T);
        printf("Case #%d: %lf\n", Case, nom/den);
    }
}


