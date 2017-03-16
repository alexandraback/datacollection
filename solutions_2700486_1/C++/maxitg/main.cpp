//
//  main.cpp
//  CodeJam.2013.1B.B
//
//  Created by Maxim Piskunov on 04.05.2013.
//  Copyright (c) 2013 Maxim Piskunov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

#include <gmpxx.h>

using namespace std;

vector <vector <mpz_class> > binomials;
int maxn = 1030;

class testCase {
    int N;
    int X;
    int Y;
    
    double prob;
    
    mpz_class binomial(int n, int m) {
        return binomials[n][m];
    }
    
public:
    void solve() {
        int fillingLayer = 0;
        int myLayer;
        
        int currentLevel = 0;
        int difference = 0;
        for (int i = 1; currentLevel < N; i += 4) {
            currentLevel += i;
            difference = N - currentLevel;
            fillingLayer++;
        }
        fillingLayer--;
        myLayer = (abs(X) + Y)/2;
                
        if (fillingLayer < myLayer) {
            prob = 0.;
            return;
        } else if (fillingLayer > myLayer) {
            prob = 1.;
            return;
        }
        
        if (difference == 0) {
            prob = 1.;
            return;
        }
        
        if (Y == myLayer * 2) {
            prob = 0.;
            return;
        }
                
        int layerSize = myLayer * 4 + 1;
        int filled = layerSize + difference;
        
        if ((filled - (layerSize-1)/2) > Y) {
            prob = 1.;
            return;
        }
        
        int n = filled;
        
        mpz_class result = 0;
        for (int m = Y+1; m <= n; m++) {
            result += binomial(n, m);
        }        
        
        mpz_class total = 1;
        for (int i = 0; i < n; i++) {
            total *= 2;
        }
        
        prob = result.get_d() / total.get_d();
    }
    
    void read(istream &in) {
        in >> N >> X >> Y;
    }
    
    void write(ostream &out) {
        out.precision(10);
        out << fixed << prob;
    }
    
};

vector <testCase> read() {
    ifstream in("input.txt");
    
    int T;
    in >> T;
    vector <testCase> tests(T);
    for (int i = 0; i < tests.size(); i++) {
        tests[i].read(in);
    }
    
    in.close();
    
    return tests;
}

void write(vector <testCase> tests)
{
    ofstream out("output.txt");
    
    for (int i = 0; i < tests.size(); i++) {
        out << "Case #" << i+1 << ": ";
        tests[i].write(out);
        if (i != tests.size()-1) out << endl;
    }
    
    out.close();
}

void solve(vector <testCase> &tests) {
    for (int i = 0; i < tests.size(); i++) {
        tests[i].solve();
    }
}

void init() {
    binomials.resize(maxn);
    for (int n = 0; n < maxn; n++) {
        binomials[n].resize(maxn+1);
        for (int m = 0; m <= n; m++) {
            if (m == 0) binomials[n][m] = 1;
            else if (n == 0) binomials[n][m] = 0;
            else binomials[n][m] = binomials[n-1][m-1] + binomials[n-1][m];
        }
    }
}

int main(int argc, const char * argv[])
{
    init();
        
    vector <testCase> tests = read();
    solve(tests);
    write(tests);
    return 0;
}