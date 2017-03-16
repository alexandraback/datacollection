/*
 * File:   main.cpp
 * Author: mehmetfatihuslu
 *
 * Created on April 12, 2014, 4:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <iomanip>

using namespace std;

/*
 *
 */

int NumDigits(int n) {
    int digits = 0;
    if (n <= 0) {
        n = -n;
        ++digits;
    }
    while (n) {
        n /= 10;
        ++digits;
    }
    return digits;
}

int main(int argc, char** argv) {

    fstream inputFile, outputFile, logFile;
    int T = 3;

    inputFile.open("input",ios::in);
    //FILE *out = fopen ("output","w");
    outputFile.open("output",ios::out);
    logFile.open("log",ios::out);

    inputFile >> T;

    for(int dongu=1; dongu<=T; dongu++) {

        double C,F,X;
        inputFile >>C>>F>>X;

        //fprintf(out,"Case #%d: ",dongu);
        outputFile << "Case #" <<dongu <<": ";

        double farm= X/C-2/F-1;
        double result = 0;

        if(farm<0){

            farm=0;
            result = X/2;
            outputFile.precision(NumDigits(floor(result))+7);
            //fprintf(out,"%.7f",result);
            outputFile << result;
        }
        else{

            double result1 = X/(2+ceil(farm)*F);
            double result2 = X/(2+floor(farm)*F);

            for(int i=0;i<ceil(farm);i++)
                result1+=C/(2+i*F);

            for(int i=0;i<floor(farm);i++)
                result2+=C/(2+i*F);
            outputFile.unsetf(std::ios::floatfield);

            outputFile.precision(NumDigits(floor(min(result1,result2)))+7);
            //fprintf(out,"%.7f",min(result1,result2));
            outputFile << min(result1,result2);
        }

        //fprintf("\n");
        outputFile << endl;
    }

    return 0;
}

