//
//  main.cpp
//  CodeJam0C
//
//  Created by Maxim Piskunov on 4/8/16.
//  Copyright © 2016 Maksim Piskunov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// https://gmplib.org
#include <gmpxx.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>

#define filename "C-small-attempt0"

using namespace std;

struct input {
    int N;
    int J;
};

struct coin {
    vector <int> digits;
    vector <int> divisors;
};

struct output {
    vector<struct coin> coins;
};

void read(ifstream &in, input &test) {
    in >> test.N >> test.J;
}

void write(ofstream &out, output test) {
    for (int i = 0; i < test.coins.size(); i++) {
        out << "\n";
        for (int j = 0; j < test.coins[i].digits.size(); j++) {
            out << test.coins[i].digits[j];
        }
        for (int j = 0; j < test.coins[i].divisors.size(); j++) {
            out << " " << test.coins[i].divisors[j];
        }
    }
}

struct coin coinN (int n, int size) {
    struct coin result;
    
    result.digits.resize(size);
    result.divisors.resize(9);
    
    result.digits[0] = 1;
    for (int i = size - 2; i >= 1; i--) {
        result.digits[i] = n % 2;
        n /= 2;
    }
    result.digits[size - 1] = 1;
    
    return result;
}

output solve (input test) {
    output result;
    
    int n = 0;
    while (result.coins.size() < test.J) {
        struct coin newCoin = coinN(n++, test.N);
        
        bool anyPrime = false;
        
        for (int base = 2; base <= 10; base++) {
            mpz_class number = 0;
            mpz_class power = 1;
            for (int i = (int)newCoin.digits.size() - 1; i >= 0; i--) {
                number += power * newCoin.digits[i];
                power *= base;
            }
            
            bool prime = true;
            
            for (int i = 2; i * i <= number && i <= 10000; i++) {
                if (number % i == 0) {
                    prime = false;
                    newCoin.divisors[base - 2] = i;
                    break;
                }
            }
            
            if (prime) anyPrime = true;
        }
        
        if (!anyPrime) {
            result.coins.push_back(newCoin);
            cout << result.coins.size() << endl;
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