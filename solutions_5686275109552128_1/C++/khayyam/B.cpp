#include <stdio.h>
int P[1001];
int D;
int maxt;

int needed(int h){
    int total = 0;
    for(int i=0;i<D;++i){
        total += P[i] / h;
        total -= ((P[i]%h) == 0);
    }
    return h + total;
}

int solve(){
    int best = maxt;
    for(int h=1;h<maxt;++h){
        int opt = needed(h);
        if(opt<best){
            best = opt;
        }
    }
    return best;
}

int main(){
    int T;
    scanf("%d", &T);
    maxt=0;
    for(int c=1;c<=T;++c){
        scanf("%d", &D);
        for(int i=0;i<D;++i){
            scanf("%d", &P[i]);
            if(P[i]>maxt){
                maxt = P[i];
            }
        }
        int sol = solve();
        printf("Case #%d: %d\n", c, sol);
    }
    return 0;
}
