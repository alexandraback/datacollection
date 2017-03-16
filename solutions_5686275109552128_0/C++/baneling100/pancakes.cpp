#include <stdio.h>
#define INF 0x7fffffff

int T, D, P[1001], Ans;

int main(void) {

    int i, j, k, mmax, res;

    scanf("%d",&T);
    for(i=1 ; i<=T ; i++) {
        Ans=INF, mmax=0;
        scanf("%d",&D);
        for(j=1 ; j<=D ; j++) {
            scanf("%d",&P[j]);
            if(mmax<P[j]) mmax=P[j];
        }
        for(j=1 ; j<=mmax ; j++) {
            res=0;
            for(k=1 ; k<=D ; k++) res+=(P[k]-1)/j;
            if(Ans>res+j) Ans=res+j;
        }
        printf("Case #%d: %d\n",i,Ans);
    }

    return 0;
}
