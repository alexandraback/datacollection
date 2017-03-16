#include <cstdio>
#include <algorithm>

#define MAXN 1100

using namespace std;

int main() {
    int T;
    freopen("test.in","rt",stdin);
    freopen("test.out","wt",stdout);
    scanf("%d", &T );
    for( int z = 1; z <= T; z++ ) {
        int A, B, K, ans = 0;
        scanf("%d%d%d", &A, &B, &K );
        for( int i = 0; i < A; i++ ) {
            for( int j = 0; j < B; j++ ) {
                if( ( i & j ) < K ) ans++;
            }
        }
        printf("Case #%d: %d\n", z, ans );
    }
    return 0;
}
