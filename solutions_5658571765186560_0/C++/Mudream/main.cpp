#include <cstdio>
#include <cstdlib>

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int X, R, C; scanf("%d %d %d", &X, &R, &C);
        int ans = 0;
        if((R*C)%X != 0)
            ans = 0;
        else if(X <= 2)
            ans = 1;
        else if(X == 3)
            ans = R > 1 and C > 1;    
        else if(X == 4)
            ans = (R > 2 and C > 2);
        printf("Case #%d: %s\n", lt, ans ? "GABRIEL": "RICHARD");
    }
    return 0;
}
