#include <stdio.h>

int main() {
    int T, A,B,K;
    scanf("%d", &T);
    for(int i =0; i < T; ++i) {
        scanf("%d %d %d", &A, &B, &K);
        long long int c = 0;
        for (int x = 0; x < A; ++x)
            for (int y = 0; y < B; ++y)
                if ((x&y) < K) ++c;
        printf("Case #%d: %lld\n", i+1, c);
    }
}
