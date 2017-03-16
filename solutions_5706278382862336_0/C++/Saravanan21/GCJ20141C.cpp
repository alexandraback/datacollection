//
//  GCJ20141A.cpp
//  Console Application
//
//  Created by Vanan on 25/04/2014.
//  Copyright (c) 2014 Elly Works. All rights reserved.
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

ifstream fin("/Users/Vanan/Downloads/A-small-attempt0.in");
ofstream fout("/Users/Vanan/Downloads/output.out");

void problemA();
void problemB();
void problemC();

long long ancestors = (1L << 40);

void problemA() {
    long long p, q;
    fin >> p;
    char temp;
    fin >> temp;
    fin >> q;
    
    while (p % 2 == 0 && q % 2 == 0) {
        p /= 2;
        q /= 2;
    }
    
    for (int i=3; i<p && i<q; i += 2) {
        while (p % i == 0 && q % i == 0) {
            p /= i;
            q /= i;
        }
    }
    
    if ((ancestors*p) % q == 0) {
        int answer = 1;
        p = (p*ancestors)/q;
        while ((p << 1) < ancestors) {
            ++answer;
            p = (p << 1);
        }
        fout << answer << endl;
    }
    else {
        fout << "Impossible" << endl;
    }
}

void problemB() {
    
}

void problemC() {
    
}

int main (int argc, const char * argv[])
{
    cout << "Start" << endl;
    int T;
    fin >> T;
    for (int t=1; t<=T; ++t)
    {
        fout << "Case #" << t << ": ";
        
        problemA();
        //problemB();
        //problemC();
    }
    cout << "Done" << endl;
    return 0;
}