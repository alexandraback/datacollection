
#include <cstdio>

int main()
{
    int T ;
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        printf("Case #%d: ", time) ;
        int R, C, W ;
        scanf("%d%d%d", &R, &C, &W) ;
        int ans = 0 ; 
        if(R > 1){
            ans += (R-1)*(C/W) ;
            R = 1 ;
        }
        ans += C/W ;
        ans += W-1 + (C%W ? 1 : 0) ;
        printf("%d\n", ans) ;
    }
}
