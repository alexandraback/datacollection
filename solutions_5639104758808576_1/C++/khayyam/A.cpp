#include <stdio.h>

char buffer[1002];
int N[1001];
int smax;
int solve(){
    N[1] = buffer[0]-'0';
    int best = 0;
    if(N[1] < 1){
        best=1;
    }
    for(int i=2;i<=smax;++i){
        N[i] = N[i-1] + buffer[i-1] - '0';
        if((buffer[i]>0) && (N[i] < i)){
            int opt = i - N[i];
            if(opt>best){
                best = opt;
            }
        }
    }
    return best;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int c=1;c<=T;++c){
        scanf("%d", &smax);
        scanf("%s", buffer);
        int sol = solve();
        printf("Case #%d: %d\n", c, sol);
    }
    return 0;
}
