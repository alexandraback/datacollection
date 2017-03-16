#include <stdlib.h>
#include <stdio.h>

int main(){

    int T; //Number of test cases (1-100)
    scanf("%d", &T);

    double C; //Farm cost (1-10000)

    double F; //Extra F cookies per second (1-100)

    double X; //Win value (100000)


    int t;
    for(t=1; t<=T; t++){

        scanf("%lf", &C);
        scanf("%lf", &F);
        scanf("%lf", &X);

        //cps = Cookies per Second
        double cps = 2;

        //Estimated time
        double estimated = X / cps;

        //Elapsed time
        double acumTime = C / cps;

        cps += F;

        while(1){
            if( (X / cps) + acumTime > estimated){
                break;
            }
            estimated = X / cps + acumTime;
            acumTime += C / cps;
            cps += F;
        }

        //7 decimal places
        printf("Case #%d: %.*f\n", t, 7, estimated);

    }

    return 0;
}
