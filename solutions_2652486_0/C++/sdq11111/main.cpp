#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int R, N, M, K;
int a[100], v[100], p[100], o[100];

int d(int s, int e) {
    if (e == N) {
        memset(v, 0, sizeof(v));
        for (int i = 0; i < (1 << N); ++i) {
            int temp = 1;
            for (int j = 0; j < N; ++j)
                if (i & (1 << j))
                    temp *= p[j];
            for (int j = 0; j < K; ++j)
                if (temp == o[j])
                    v[j] = 1;
        }
        for (int i = 0; i < K; ++i)
            if (!v[i])
                return 0;
        for (int i = 0; i < N; ++i)
            a[i] = p[i];
        return 1;
    }
    for (int i = s; i <= M; ++i) {
        p[e] = i;
        if (d(i, e + 1))
            return 1;
    }
    return 0;
}

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d:\n", t);
        scanf("%d%d%d%d", &R, &N, &M, &K);
        while (R--) {
            for (int i = 0; i < K; ++i)
                scanf("%d", &o[i]);
            d(2, 0);
            for (int i = 0; i < N; ++i)
                printf("%d", a[i]);
            printf("\n");
        }
    }
    return 0;
}
