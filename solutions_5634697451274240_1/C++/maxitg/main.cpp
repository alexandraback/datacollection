#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>

//#define filename "B-small-attempt0"
#define filename "B-large"

using namespace std;

struct input {
    string S;
};

struct output {
    int n;
};

void read(ifstream &in, input &test) {
    in >> test.S;
}

void write(ofstream &out, output test) {
    out << test.n;
}

bool allUp (string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') return false;
    }
    return true;
}

output solve (input test) {
    output result;
    result.n = 0;
    
    string s = test.S + "+";
    
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] != s[i+1]) result.n++;
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