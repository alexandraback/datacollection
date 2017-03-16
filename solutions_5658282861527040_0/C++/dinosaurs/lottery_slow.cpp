#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int T, A, B, K;

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &A, &B, &K);

        long long answer = 0;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if ((i & j) < K) {
                    answer++;
                }
            }
        }

        printf("Case #%d: %lld\n", t, answer);
    }

    return 0;
}
