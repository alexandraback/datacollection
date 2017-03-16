#include <cstdio>
#include <cstring>

int t, T, N, n, arr[2505];

void solve() {
    int i;
    printf("Case #%d:",t);
    for ( i = 1 ; i <= 2500 ; ++i ) {
        if ( arr[i]%2 ) {
            printf(" %d",i);
        }
    }
    printf("\n");
}

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int i, j;
    scanf("%d",&T);
    for ( t = 1 ; t <= T ; ++t ) {
        scanf("%d",&N);
        memset(arr,0,sizeof(arr));
        for ( i = 0 ; i < 2*N-1 ; ++i ) {
            for ( j = 0 ; j < N ; j ++ ) {
                scanf("%d",&n);
                ++arr[n];
            }
        }
        solve();
    }
    return 0;
}
