//
//  main.cpp
//  CodeJam.2013.A1.B
//
//  Created by Maxim Piskunov on 27.04.2013.
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

using namespace std;

class testCase {
    int E;
    int R;
    int N;
    vector <int> v;
    
    long gain;
    
public:
    long solveRec(int start, int curE) {
        if (start == N) return 0;
        long best = 0;
        for (int i = 0; i <= curE; i++) {
            long cur = i * v[start] + solveRec(start+1, min(E, curE - i + R));
            if (cur > best) best = cur;
        }
        return best;
    }
    
    void solveSlow() {
        gain = solveRec(0, E);
    }
    
    void solve() {
        sort(v.rbegin(), v.rend());
        if (R > E) R = E;
        
        vector <long> power;
        int e = E;
        for (int i = 0; i < N; i++) {
            if (i == N-1) {
                power.push_back(e);
            }
            else if (e == E) {
                power.push_back(e);
                e = e - E + R;
            } else if (e + R <= E) {
                power.push_back(0);
                e = e + R;
            } else {
                power.push_back(e + R - E);
                e = E;
            }
        }
        
        sort(power.rbegin(), power.rend());
        for (int i = 0; i < N; i++) {
            cout << power[i] << " ";
        }
        cout << endl;
        gain = 0;
        for (int i = 0; i < N; i++) {
            gain += (long)v[i] * (long)power[i];
        }
        
        long result = gain;
        solveSlow();
        if (gain != result) {
            cout << "error" << endl;
            cout << E << " " << R << " " << N << endl;
            cout << result << " " << gain << endl;
            exit(0);
        }
    }
    
    void read(istream &in) {
        in >> E >> R >> N;
        v.resize(N);
        for (int i = 0; i < N; i++) {
            in >> v[i];
        }
    }
    
    void write(ostream &out) {
        out << gain;
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
        tests[i].solveSlow();
    }
}

int main(int argc, const char * argv[])
{
    vector <testCase> tests = read();
    solve(tests);
    write(tests);
    return 0;
}