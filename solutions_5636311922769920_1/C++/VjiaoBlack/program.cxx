#include <iostream>
#include <cmath>

using namespace std;

#define MIN(a,b) ((a) < (b) ? (a) : (b))

long myPow(long x, long p) {
    if (p == 0) return 1;
    if (p == 1) return x;

    long tmp = myPow(x, p/2);
    if (p%2 == 0) return tmp * tmp;
    else return x * tmp * tmp;
}

int main() {
    long T;

    cin >> T;

    for (long i = 0; i < T; i++) {
        printf("Case #%ld:", i+1);
        long K, C, S;

        cin >> K >> C >> S;

        // small. Lol.
        // if (S == K) {
        //     for (long j = 1; j <= K; j++) {
        //         printf(" %d", j);
        //     }
        //     printf("\n");
        // } else {
        //     printf(" IMPOSSIBLE\n");
        // }

        // large.
        long min_req = (K + C - 1) / C;

        if (min_req > S) {
            printf(" IMPOSSIBLE\n");
        } else {
            for (long i = 0; i < K; i += C) {
                long ans = 0;
                for (long j = 0; j < C; j++) {
                    long diff = MIN(i+j, K-1) * myPow(K, C-j-1);
                    // printf("\n>%d, %d: %d .. %d<\n", i+j, K-1, MIN(i+j, K-1), myPow(K, K-j-2));
                    ans += diff;
                }
                printf(" %ld", ans+1);

            }
            printf("\n");
        }


    }
}
