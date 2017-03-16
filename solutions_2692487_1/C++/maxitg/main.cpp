//
//  main.cpp
//  CodeJam.2013.1B.A
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

using namespace std;

class testCase {
    int A;
    vector <int> motes;
    
    int result;
    
public:
    void solve() {
        sort(motes.begin(), motes.end());
        
        if (A == 1) {
            result = (int)motes.size();
            return;
        }
        
        result = 1000;
        for (int i = 0; i <= motes.size(); i++) {
            long long curSize = A;
            int curResult = (int)motes.size()-i;
            for (int j = 0; j < i; j++) {
                if (curSize > motes[j]) curSize += motes[j];
                else {
                    curSize += curSize-1;
                    curResult++;
                    j--;
                }
            }
            if (curResult < result) result = curResult;
        }
    }
    
    void read(istream &in) {
        int N;
        in >> A >> N;
        motes.resize(N);
        for (int i = 0; i < N; i++) {
            in >> motes[i];
        }
    }
    
    void write(ostream &out) {
        out << result;
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