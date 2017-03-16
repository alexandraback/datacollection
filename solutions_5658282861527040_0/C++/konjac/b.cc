#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

void solve(){
    int A, B, K;
    int ans =0;
    scanf("%d%d%d", &A, &B, &K);
    for(int i = 0; i < A; ++i)
        for(int j = 0; j < B; ++j){
            if((i&j)<K)
                ++ans;
        }
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        printf("Case #%d: ", t);
        solve();
    }
}
