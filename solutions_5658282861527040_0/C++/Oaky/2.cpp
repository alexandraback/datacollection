#include <cstdio>

int solve(){
    int a, b, c, cnt = 0;
    scanf("%d %d %d", &a, &b, &c);
    for(int i = 0; i < a; ++i){
        for(int j = 0; j < b; ++j){
            if((i & j) < c){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int allt;
    scanf("%d", &allt);
    for(int t = 1; t <= allt; ++t){
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;
}