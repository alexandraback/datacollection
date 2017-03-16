#include <stdio.h>

int main(){
    int t, a, b, k;

    scanf("%d", &t);
    for(int nt = 0; nt < t; ++nt){
        scanf("%d %d %d", &a, &b, &k);
        int res = 0;
        for(int i = 0; i < a; ++i){
            for(int j = 0; j < b; ++j){
                if((i&j) < k) res++;
            }
        }
        printf("Case #%d: %d\n", nt+1, res);


    }

    return 0;
}
