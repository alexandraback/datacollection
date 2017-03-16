#include <bits/stdc++.h>

using namespace std;

int ans[100];

void prtAns(int N) {
    for (int i = N - 1; i >= 0; --i) {
        printf("%d", ans[i]);
    }
}

long long calc(int N, int j) {
    long long tmp = 0;
    long long pow = 1;
    for (int i = 0; i < N; ++i) {
        tmp += pow * ans[i];
        pow *= 1LL * j;
    }
    return tmp;
}

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    scanf("%d", &T);
    printf("Case #1:\n");
    int N, J;
    scanf("%d%d", &N, &J);
    int limN = N / 2 - 2;
    int lim = min((1 << limN) - 1, J);
    for (int i = 0; i < lim; ++i) {
        ans[0] = 1;
        for (int j = 0; j < limN; ++j) {
            ans[j + 1] = 0;
            if (i & (1 << j)) ans[j + 1] = 1;
        }
        ans[N / 2 - 1] = 1;
        prtAns(N / 2);
        prtAns(N / 2);
        for (int j = 2; j <= 10; ++j) {
            printf(" %lld", calc(N/2, j));
        }
        printf("\n");
    }
    return 0;
}