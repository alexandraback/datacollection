#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <cstdio>
#include <cstdlib>

using namespace std;


int main(){
    ifstream ulazniTok("B-large.in");

    int T;

    int i;
    int j;

    FILE *f;
    f = fopen("out.txt", "w");


    ulazniTok >> T;
for( i = 0; i < T ; i++ ){
    double C, F, X;
    double Xtemp, VrijemeTemp, IncomeTemp;
    double Income;
    double Vrijeme;
    double VrijemeC;
    double VrijemeTotal;

    ulazniTok >> C;
    ulazniTok >> F;
    ulazniTok >> X;

    Income = 2;
    Vrijeme = X/Income;
    VrijemeTotal = 0;
    VrijemeC = C/Income;

    while(1){

            VrijemeC = C/Income;
            IncomeTemp = Income+F;

            VrijemeTemp = X/IncomeTemp;
            VrijemeTemp+=VrijemeC;

            if( Vrijeme > VrijemeTemp ){

                Income = IncomeTemp;

                VrijemeTotal+=VrijemeC;
                Vrijeme = X/Income;
            }
            else break;

                }

    VrijemeTotal+=X/Income;

    fprintf(f, "Case #%d: %lf\n", i+1, VrijemeTotal);
    }



fclose(f);

return 0;

}
