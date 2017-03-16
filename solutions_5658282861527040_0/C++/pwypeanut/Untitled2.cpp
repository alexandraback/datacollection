#include <cstdio>
#include <iostream>
using namespace std;

// 0s in bit "bit" from 0 to num
int cnt_bit(long long int num, int bit) {
    return num / (1ll<<(bit+1)) * (1ll<<(bit+1));
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for ( int tc = 1; tc <= T; tc++ ) {
        int A, B, K;
        scanf("%d%d%d", &A, &B, &K);
        int cnt = 0;
        for ( int i = 0; i < A; i++ ) {
            for ( int j = 0; j < B; j++ ) {
                if ( (i&j) < K ) cnt++;
            }
        }
        printf("Case #%d: %d\n", tc, cnt);
    }
}
