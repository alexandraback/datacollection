#include <stdio.h>
#define LL long long
#define R 1
#define G 2

int get_winner(int x, int r, int c){
    if((r*c)%x != 0){
        return R;
    }
    if(x==1){
        return G;
    }
    if(x==2){
        return G;
    }
    if(x==3){
        if((r==1) || (c==1)){
            return R;
        }
        return G;
    }
    if(r*c>=12){
        return G;
    }
    return R;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;++t){
        int x, r, c;
        scanf("%d%d%d", &x, &r, &c);
        int winner = get_winner(x, r, c);
        if(winner == R){
            printf("Case #%d: RICHARD\n", t);
        }else{
            printf("Case #%d: GABRIEL\n", t);
        }
    }
    return 0;
}
