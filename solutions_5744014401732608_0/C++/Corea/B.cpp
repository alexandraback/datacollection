#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void process(long long B, long long M) {
    long long t = 1;
    for (int i = 0; i < B - 2; i ++) {
        t *= 2;
    }

    if (M > t) {
        printf( "IMPOSSIBLE\n" );
        return;
    }
    printf( "POSSIBLE\n" );
    int D[53][53] = {0, };

    for (int i = 0; i < B - 1; i ++) {
        for (int j = i + 1; j < B - 1; j ++) {
            D[i][j] = 1;
        }
    }

    for (int i = B - 2; i > 0; i --) {
        t /= 2;
        if (M >= t) {
            D[i][B - 1] = 1;
            M -= t;
        }
    }
    if (M == 1) {
        D[0][B - 1] = 1;
    }
    for (int i = 0; i < B; i ++) {
        for (int j = 0; j < B; j ++) {
            printf( "%d", D[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int T;
    scanf( "%d", &T );
    for (int test = 1; test <= T; test ++) {
        long long B, M;
        scanf( "%lld %lld", &B, &M );

        printf( "Case #%d: ", test );
        process(B, M);
    }
    return 0;
}
