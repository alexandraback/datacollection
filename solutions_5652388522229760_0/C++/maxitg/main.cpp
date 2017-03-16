#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>

#define filename "A-small-attempt0"

using namespace std;

struct input {
    long N;
};

struct output {
    long N;
};

void read(ifstream &in, input &test) {
    in >> test.N;
}

void write(ofstream &out, output test) {
    if (test.N == 0) out << "INSOMNIA";
    else out << test.N;
}

bool allTrue(bool digits[10]) {
    for (int i = 0; i < 10; i++) {
        if (digits[i] == 0) return false;
    }
    return true;
}

output solve (input test) {
    output result;
    
    bool digits[10];
    for (int i = 0; i < 10; i++) digits[i] = false;
    
    long n;
    
    if (test.N == 0) n = 0;
    else {
        for (n = test.N; !allTrue(digits); n += test.N) {
            string str = to_string(n);
            for (int i = 0; i < str.length(); i++) {
                digits[str[i] - '0'] = true;
            }
        }
    }
    
    result.N = n - test.N;
    
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