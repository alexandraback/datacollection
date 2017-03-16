#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std ;
int A, B, K ;

int main() {
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    int T, cas = 1 ;
    scanf("%d", &T) ;

    while (T--) {
        scanf("%d %d %d", &A, &B, &K) ;
        int ans = 0 ;
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                if ((i & j) < K)
                    ans++ ;
            }
        }
        printf("Case #%d: %d\n", cas++, ans) ;
    }
    return 0 ;
}
