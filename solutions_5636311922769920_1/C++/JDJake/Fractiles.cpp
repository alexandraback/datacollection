#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int K,C,S;
        scanf("%d %d %d", &K, &C, &S);

        printf("Case #%d: ", i);

        if (C == 1) {
            if (S < K) printf("IMPOSSIBLE");
            else {
                for (int j = 1; j <= K; j++) {
                    printf("%d", j);
                    if (j < K) printf(" ");
                }
            }
        }
        else if (S < ((K % 2) ? (K + 1)/2 : K/2)) printf("IMPOSSIBLE");
        else {
            for (int j = 1; j <= K; j += 2) {
                if (j+1 <= K) printf("%d", (j-1)*K + j + 1);
                else printf("%d", j);
                if (j + 2 <= K) printf(" ");
            }
        }

        printf("\n");
    }
}