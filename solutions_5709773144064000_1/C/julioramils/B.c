#include <stdio.h>

int main(){
    freopen ("B-large.in","r",stdin);
    freopen ("B_out_large","w",stdout);
    int T;
    int caso=0;
    double sol;
    double C;
    double F;
    double X;
    double G;
    double now;
    double nex;
    double remain;
    double aux;

    scanf("%d", &T);

    while(T--){
        caso++;
        scanf("%lf %lf %lf", &C, &F, &X);
        remain = X;
        now=0.0;
        G=2.0;
        nex=100000.0;

        aux=X/G+now;
        //printf("%f %f %f\n", aux, X, G);

        while(nex>aux){
            nex=aux;
            now+=C/G;
            G+=F;
            aux=X/G+now;
           // printf("%f %f %f\n", aux, X, G);
        }


        printf("Case #%d: %5.7f\n", caso, nex);
    }
    return 0;
}
