//
//  main.cpp
//  CodeJam0D
//
//  Created by Maxim Piskunov on 4/8/16.
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

#define filename "D-small-attempt0"

using namespace std;

struct input {
    int K;
    int C;
    int S;
};

struct output {
    vector <int64_t> tiles;
};

void read(ifstream &in, input &test) {
    in >> test.K >> test.C >> test.S;
}

void write(ofstream &out, output test) {
    if (test.tiles.empty()) out << " IMPOSSIBLE";
    else for (int i = 0; i < test.tiles.size(); i++) {
        out << " " << test.tiles[i] + 1;
    }
}

int64_t fromDigits(vector <int> digits, int base) {
    int64_t result = 0;
    int64_t multiplier = 1;
    for (int i = (int)digits.size() - 1; i >= 0; i--) {
        result += multiplier * digits[i];
        multiplier *= base;
    }
    return result;
}

output solve (input test) {
    output result;
    
    int groupSize = test.C;
    int digitCount = test.K;
    
    int maxDigit = 0;
    while (maxDigit < digitCount) {
        vector <int> digits;
        for (int i = 0; i < groupSize; i++) {
            digits.push_back((maxDigit++) % digitCount);
        }
        result.tiles.push_back(fromDigits(digits, digitCount));
    }
    
    if (result.tiles.size() > test.S) result.tiles.clear();
    
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
    
    out << "Case #1:";
    write(out, results[0]);
    for (int i = 1; i < results.size(); i++) {
        out << endl << "Case #" << i+1 << ":";
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