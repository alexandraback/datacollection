#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(){
    int T;
    scanf("%d", &T);
    for(int case_t=1 ; case_t<=T ; case_t++){
        int R, C, W;
        scanf("%d %d %d", &R, &C, &W);
        int res = 0;
        res += (C/W) * R;
        res += W;
        if(C%W==0) res--;
        printf("Case #%d: %d\n", case_t, res);
    }
    return 0;
}