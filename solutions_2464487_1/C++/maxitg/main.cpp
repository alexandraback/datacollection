//
//  main.cpp
//  CodeJam.2013.A1.A
//
//  Created by Maxim Piskunov on 27.04.2013.
//  Copyright (c) 2013 Maxim Piskunov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <gmpxx.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

class testCase {
    unsigned long r;
    unsigned long t;
    string n;
    
    mpz_class paint (mpz_class n) {
        mpz_class rl = r;
        return 2*n*rl + n*(2*n-1);
    }
    
public:
    void solve() {
        mpz_class nlow = 0;
        mpz_class nhigh = 1000000001L;
        while (nhigh - nlow > 1) {
            mpz_class nmid = (nhigh + nlow) / 2;
            if (paint(nmid) > t) nhigh = nmid;
            else nlow = nmid;
        }
        n = nlow.get_str();
    }
    
    void read(istream &in) {
        in >> r >> t;
    }
    
    void write(ostream &out) {
        out << n;
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

int main(int argc, const char * argv[])
{
    vector <testCase> tests = read();
    solve(tests);
    write(tests);
    return 0;
}