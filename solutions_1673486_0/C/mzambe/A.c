#include<stdio.h>
#include<stdlib.h>
#define N 10000

double p[N];

double prob_of_bad(int A, int j){
    double prevmult = 1;
    double result = 0;
    int i;
    for( i = 0; i < (A - j); i++ ){
        result += prevmult*(1 - p[i]);
        prevmult *= p[i];
    }

    return result;
}

int good(int A, int B, int j){
    return (B - A + 2*j + 1);
}

int bad(int A, int B, int j){
    return (2*B - A + 2*j + 2);
}

int main(){
    double res = -1, pbad, pgood, posres;
    int T, A, B, i, j;
    scanf("%d", &T);
    for( i = 0; i < T; i++ ){
        res = -1;
        scanf("%d %d", &A, &B);
        for( j = 0; j < A; j++ ){
            scanf("%lf", p + j);
        }

        for( j = 0; j < A; j++ ){
            pbad = prob_of_bad(A, j);
            pgood = 1 - pbad;
            posres = pgood*good(A, B, j) + pbad*bad(A, B, j);
            if ( (posres < res) || (res < 0) ){
                res = posres;
            }
        }

        if (res > (B + 2)){
            res = B + 2;
        }

        printf("Case #%d: %.6lf\n", i + 1, res);
    }

    return 0;
}
