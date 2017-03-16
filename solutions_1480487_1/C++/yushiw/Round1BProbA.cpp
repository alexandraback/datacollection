//
//  Round1BProbA.cpp
//  CodeJam2012
//
//  Created by Yushi Wang on 5/4/12.
//  Copyright (c) 2012 Stanford University. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int cases;
    ofstream outFile;
    ifstream inFile;
    inFile.open("//Users//yushiwang//Documents//Stanford 2011-2012//Spring11-12//CodeJam1b//A-large.in");
    outFile.open("//Users//yushiwang//Documents//Stanford 2011-2012//Spring11-12//CodeJam1b//A-large.out");
    inFile >> cases;
    inFile.ignore();
    cout << cases;
    int scores[200];
    double percents[200];
    double total, number;
    for (int num = 1; num <= cases; num++) {
        inFile >> number;
        total = 0;
        for (int i = 0; i < number; i++) {
            inFile >> scores[i];
            total += scores[i];
        }
        double total1 = 2 * total;
        double cutoff = total1/number;
        double immune = number;
        for (int i = 0; i < number; i++) {
            if (scores[i] > cutoff) {
                immune--;
                total1 -= ((double) scores[i]);   
            }
        }
        cutoff = (total1)/(immune);
        for (int i = 0; i < number; i++) {
            long double need = cutoff - scores[i];
            if (need < 0) need = 0;
            need /= total;
            percents[i] = need * 100;
        }
        outFile << "Case #" << num << ":";
        for (int i = 0; i < number; i++) {
            outFile << " " << percents[i];
        }
        outFile << endl;
    }
    return 0;
}