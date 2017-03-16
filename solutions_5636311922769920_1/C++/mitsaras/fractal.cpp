#include<cstdio>

using namespace std;

int main(){
    int T;
    int K, C, S;

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &K, &C, &S);
        if (S *C >= K) {
            long long K_to[101];
            K_to[0] = 1;
            for (int i = 1; i <= C; i++) {
                K_to[i] = K * K_to[i-1];
            }
            printf("Case #%d:", t);
            for (int i = 1; i <= K; i += C) {
                long long idx = 1;
                for (int j = i; j <= i + C - 1; j++) {
                    if (j > K) break;
                    idx += (j - 1) * K_to[C + i - j - 1];
                }
                printf(" %lld", idx);
            }
            printf("\n");
        } else {
            printf("Case #%d: IMPOSSIBLE\n", t);
        }
    }
    return 0;
}
