/* 
 * File:   main.cpp
 * Author: NQH
 * Google Code Jam 2012
 * Round 1A
 * Prob A.
 * Created on April 28, 2012, 8:52 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#define MAXAB 100000
#define EPSILON 1e-6;

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream fin ("A-small-attempt0.in");
    ofstream fout ("a.out");
    
    int test,ntest;
    fin >> ntest;
    cout << ntest << '\n';
    for (test=1; test<=ntest; test++) {
        int a,b;
        double p[MAXAB];
        double E[MAXAB];
        double pcorrect, pwrong;
        int i,j,k;
        
        fin >> a >> b;
        for (i=0; i<a; i++) 
            fin >> p[i];
        //type back k times
        k = 0;
        pcorrect = 1;
        for (j=0; j<a-k; j++) {
            pcorrect *= p[j];
        }
        E[k] = pcorrect*(b-a+1) + (1-pcorrect)*(b-a+1+b+1);
        for (k=1; k<=a; k++) {
            pcorrect = pcorrect/p[a-k];
            E[k] = pcorrect*(2*k+b-a+1) + (1-pcorrect)*(2*k+b-a+1+b+1);
        }
        E[a+1] = 1 + b + 1;
        
        double mine = MAXAB;
        for (k=0; k<=a+1; k++) {
            if (mine>E[k]) mine = E[k];
        }
        fout << "Case #" << test << ": " << mine << '\n';
    }
    return 0;
}

