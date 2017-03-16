//
//  main.cpp
//  CodeJamAA
//
//  Created by Maxim Piskunov on 4/15/16.
//  Copyright © 2016 Maksim Piskunov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>

#define filename "A-large"

using namespace std;

struct input {
    string S;
};

struct output {
    string last;
};

void read(ifstream &in, input &test) {
    in >> test.S;
}

void write(ofstream &out, output test) {
    out << test.last;
}

output solve (input test) {
    output result;
    result.last = "";
    
    for (int i = 0; i < test.S.length(); i++) {
        char firstDifferent = '0';
        for (int j = (int)result.last.length() - 1; j >= 0; j--) {
            if (result.last[j] != test.S[i]) firstDifferent = result.last[j];
        }
        
        if (test.S[i] < firstDifferent) result.last = result.last + test.S[i];
        else if (test.S[i] > firstDifferent) result.last = test.S[i] + result.last;
        else {
            cout << "bad";
            result.last = test.S[i] + result.last;
        }
    }
    
    return result;
}

void readAll(vector <input> &tests) {
    ifstream in("/Users/maxitg/Downloads/" + (string)filename + ".in.txt");
    
    int T;
    in >> T;
    tests.resize(T);
    for (int i = 0; i < T; i++) {
        read(in, tests[i]);
    }
    
    in.close();
}

void writeAll(vector <output> &results) {
    ofstream out("/Users/maxitg/Downloads/" + (string)filename + ".out.txt");
    
    out << "Case #1: ";
    write(out, results[0]);
    for (int i = 1; i < results.size(); i++) {
        out << endl << "Case #" << i+1 << ": ";
        write(out, results[i]);
    }
    
    out.close();
}

void solveAll(vector <input> &tests, vector <output> &results) {
    results.resize(tests.size());
    for (int i = 0; i < tests.size(); i++) results[i] = solve(tests[i]);
}

int main(int argc, const char * argv[]) {
    vector <input> tests;
    vector <output> results;
    
    readAll(tests);
    solveAll(tests, results);
    writeAll(results);
    
    return 0;
}