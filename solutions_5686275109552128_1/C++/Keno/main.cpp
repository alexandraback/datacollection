//
//  main.cpp
//  GCJ
//
//  Created by Keno on 2015/04/11.
//  Copyright (c) 2015年 Keno. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream fin;
//    fin.open("example.txt", ios::in);
    fin.open("B-large.in.txt", ios::in);
    
    ofstream fout;
    fout.open("output-B-l.txt", ios::out);
    
    string s;
    string out;
    
    // read parameters and calculate
    
    int T;
    fin >> T;
    
    for (int i = 0; i < T; i++) {
        int D;
        fin >> D;
        int *P;
        P = (int *)malloc(sizeof(int) * D);
        
        int maxP = 0;
        for (int j = 0; j < D; j++) {
            fin >> P[j];
            maxP = max(P[j], maxP);
        }
        
        int minCost = maxP;
        for (int t = 2; t < maxP; t++) {
            int time = 0;
            for (int j = 0; j < D; j++) {
                time += ceilf(P[j] / (float)t) - 1;
            }
            minCost = min(time + t, minCost);
        }
        
        fout << "Case #" << (i+1) << ": " << minCost << endl;
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
