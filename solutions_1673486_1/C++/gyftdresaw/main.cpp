/*
 * File:   main.cpp
 * Author: herman
 *
 * Created on April 27, 2012, 8:31 PM
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream infile;
ofstream outfile;

/*
 *  password problem
 */
int main(int argc, char** argv) {
    infile.open("input.txt");
    outfile.open("output.txt");

    int trials;
    infile >> trials;
    for (int i = 0; i < trials; i++){
        int A,B;
        infile >> A;
        infile >> B;
        double pcorr[A];
        for (int j = 0; j < A; j++){
            infile >> pcorr[j];
            if (j > 0)
                pcorr[j] *= pcorr[j-1];
        }
        double min_count = 200000;
        for (int b = 0; b < A; b++){
            double count;
            count = pcorr[A-1-b]*((double) B - (A-b) + 1 + b) + (1.0 - pcorr[A-1-b])*((double) B - (A-b) + 1 + b + B + 1);
            // cout << b << " " << count << " " << ((double) B - (A-b) + 1 + b) << " " << ((double) B - (A-b) + 1 + b + B + 1) << " " << pcorr[A-1-b] << endl;
            if (count < min_count)
                min_count = count;
        }
        if ((double)(B + 2) < min_count)
            min_count = (double) B + 2;
        
        cout << "Case #" << (i+1) << ": " << setiosflags(ios::fixed) << setprecision(6) << min_count << endl;
        outfile << "Case #" << (i+1) << ": " << setiosflags(ios::fixed) << setprecision(6) << min_count << endl;
    }

    infile.close();
    outfile.close();

    return (EXIT_SUCCESS);
}

