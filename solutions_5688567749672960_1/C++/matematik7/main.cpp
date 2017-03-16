/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Mafijski praktikum naloga
 *  =========================
 *  Copyright 2015 Domen Ipavec <domen.ipavec@z-v.si>
 *
 *  Licensed under the MIT License (the "License");
 */


#include <iostream>
#include <cmath>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <stdint.h>
using namespace std;

uint64_t count(uint64_t N) {
    int length10 = ceil(log10(N+1));
    
    uint64_t steps = 0;
    
    // cannot do with zeros at the end
    if ((N % ((uint64_t)pow(10, ceil(length10/2.0)))) == 0) {
        N = N-1;
        steps += 1;
        length10 = ceil(log10(N+1));
    }
    
    // break on digits
    int * digits = new int[length10];
    uint64_t ntemp = N;
    for (int i = 0; i< length10; i++) {
        digits[i] = ntemp %10;
        ntemp = ntemp / 10;
    }
    
    // count all counts
    for (int i = 0; i < ceil(length10/2.0); i++) {
        steps += pow(10, i)*digits[i];
        if (length10 - i - 1 > i) {
            steps += pow(10, i)*digits[length10 - i -1];
        }
    }
    
    // add one flip if necessary
    cerr << N << ' ' << pow(10, length10-1)+pow(10, ceil(length10/2.0)) << endl;
    if (N >= (pow(10, length10-1)+pow(10, ceil(length10/2.0)))) {
        steps += 1;
    }
    
    if (length10 > 1) {
        steps += count(pow(10, length10-1)-1);
    }
        
    delete[] digits;
    
    return steps;
}


int main(int argc, char *argv[]) {
    cout.precision(10);
    ifstream input;
   
    if (argc < 2) {
        input.open("data.dat");
    } else {
        input.open(argv[1]);
    }
    
    
    uint64_t n;
    input >> n;
    
    for (uint64_t u = 0; u < n; u++) {
        cerr << "Start " << u << endl;
        
        uint64_t N, steps;
        input >> N;
        
        steps = count(N);
        
        cout << "Case #" << u+1 << ": ";
        cout << steps;
        cout << endl;
        cerr << "done" << endl;

    }

    return 0;
}
