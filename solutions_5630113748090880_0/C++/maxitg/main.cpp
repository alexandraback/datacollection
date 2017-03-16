//
//  main.cpp
//  CodeJamAB
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

#define filename "B-small-attempt0"

using namespace std;

struct input {
    int n;
    vector<vector<int> > lines;
};

struct output {
    vector<int> missingLine;
};

void read(ifstream &in, input &test) {
    in >> test.n;
    test.lines.resize(2*test.n-1);
    for (int i = 0; i < 2 * test.n - 1; i++) {
        test.lines[i].resize(test.n);
        for (int j = 0; j < test.n; j++) {
            in >> test.lines[i][j];
            test.lines[i][j]--;
        }
    }
}

void write(ofstream &out, output test) {
    for (int i = 0; i < test.missingLine.size(); i++) {
        out << " " << test.missingLine[i] + 1;
    }
}

output solve (input test) {
    output result;
    
    int heightCounts[2500];
    for (int i = 0; i < 2500; i++) {
        heightCounts[i] = 0;
    }
    
    for (int i = 0; i < test.lines.size(); i++) {
        for (int j = 0; j < test.lines[i].size(); j++) {
            heightCounts[test.lines[i][j]]++;
        }
    }
    
    for (int i = 0; i < 2500; i++) {
        if (heightCounts[i] % 2 == 1) result.missingLine.push_back(i);
    }
    
    if (result.missingLine.size() != test.n) cout << "trouble" << endl;
    
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