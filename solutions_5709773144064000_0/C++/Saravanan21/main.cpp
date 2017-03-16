//
//  main.cpp
//  Console Application
//
//  Created by Saravanan Sathyanandha on 03/12/2011.
//  Copyright (c) 2011 Elly Works. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <sstream>
using namespace std;

ifstream fin("/Users/Vanan/Downloads/B-small-attempt0.in");
ofstream fout("/Users/Vanan/Downloads/output.txt");

void problemA();
void problemB();
void problemC();
void problemD();

void problemA()
{
    int row;
    int possible[4] = { -1, -1, -1, -1 };
    int temp;
    int possibleCount = 0;
    int possibleValue = -1;
    
    fin >> row;
    
    for (int i=1; i<=4; ++i) {
        for (int j=1; j<=4; ++j) {
            if (i == row)
                fin >> possible[j-1];
            else
                fin >> temp;
        }
    }
    
    fin >> row;
    for (int i=1; i<=4; ++i) {
        for (int j=1; j<=4; ++j) {
            fin >> temp;
            if (i == row) {
                for (int k=0; k<4; ++k) {
                    if (possible[k] == temp) {
                        ++possibleCount;
                        possibleValue = temp;
                        break;
                    }
                }
            }
        }
    }
    if (possibleCount == 0)
        fout << "Volunteer cheated!" << endl;
    else if (possibleCount == 1)
        fout << possibleValue << endl;
    else
        fout << "Bad magician!" << endl;
}

void problemB()
{
    double C, F, X;
    fin >> C >> F >> X;
    
    double k = floor((X-C)/C - 2.0f/F) + 1;
    if (k < 0)
        k = 0;
    double t = 0;
    for (int i=0; i<k; ++i) {
        t += C/(2.0 + i*F);
    }
    t += X/(2 + k*F);
    fout.precision(10);
    fout << t << endl;
}

void problemC()
{
    
}

void problemD()
{
    
}

int main (int argc, const char * argv[])
{
    cout << "Start" << endl;
    int T;
    fin >> T;
    for (int t=1; t<=T; ++t)
    {
        fout << "Case #" << t << ": ";
        
        //problemA();
        problemB();
        //problemC();
        //problemD();
    }
    cout << "Done" << endl;
    return 0;
}

