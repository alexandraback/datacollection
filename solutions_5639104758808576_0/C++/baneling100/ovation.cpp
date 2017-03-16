#include <stdio.h>

int T, N, S[1001];

int calc(void) {

    int i, num=0, res=0;

    for(i=0 ; i<=N ; i++)
        if(S[i]) {
            if(i>num) {
                res+=i-num;
                num=i;
            }
            num+=S[i];
        }
    return res;
}

int main(void) {

    int i, j;

    scanf("%d",&T);
    for(i=1 ; i<=T ; i++) {
        scanf("%d",&N);
        for(j=0 ; j<=N ; j++) scanf("%1d",&S[j]);
        printf("Case #%d: %d\n",i,calc());
    }

    return 0;
}
