#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int i, j, t, T;

    double C, F, X, G;

    cin >> T;

    for(t=0; t<T; t++){
        double time = 0;

        double t0;
        double t1;

        cin >> C >> F >> X;
        G = 2;

        t0 = X / G;

        t1 = t0 - X/G + C/G + X/(G+F);

        while(t1 < t0){
            t0 = t1;

            G+=F;

            t1 = t0 - X/G + C/G + X/(G+F);
        }

        printf("Case #%d: %.7lf\n", t, t0);
    }

    return 0;
}
