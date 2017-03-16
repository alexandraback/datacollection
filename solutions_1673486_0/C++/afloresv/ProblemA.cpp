#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int T, A, B;
    double res, prob[10], temp;
    scanf("%d\n", &T);
    for (int i=1 ; i<=T ; i++) {
        scanf("%d %d\n", &A, &B);
        for (int j=0 ; j<A ; j++) {
            scanf("%lf",&prob[j]);
            if (j>0)
                prob[j] *= prob[j-1];
        }
        scanf("\n");
        
        res = prob[A-1]*(B-A+1)+(1-prob[A-1])*(2*B-A+2);
        
        for (int j=A-1 ; j>=0 ; j--) {
            //printf("%lf\n",prob[j]*(A-j+B-j-1)+(1-prob[j])*(A-j+2*B-j));
            res = min(res,prob[j]*(A-j+B-j-1)+(1-prob[j])*(A-j+2*B-j));
        }
        
        res = min(res,B+2.0);
        
        printf("Case #%d: %lf\n",i,res);
    }
    return 0;
}