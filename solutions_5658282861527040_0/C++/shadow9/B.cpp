#include<cstdio>

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out", "w", stdout);
    int T, cnt = 0;
    int A, B, K;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &A, &B, &K);
        int ans = 0;
        for(int i = 0; i < A; i++){
            for(int j = 0; j < B; j++){
                int gg = i&j;
                if(gg < K) ans++;
            }
        }
        printf("Case #%d: %d\n", ++cnt, ans);
    }
    return 0;
}
