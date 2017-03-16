//
//  main.cpp
//  CodeJam.2013.A1.C
//
//  Created by Maxim Piskunov on 27.04.2013.
//  Copyright (c) 2013 Maxim Piskunov. All rights reserved.
//

#include <iostream>

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
    int R;
    int N;
    int M;
    int K;
    vector <vector <int> > products;
    
    vector <int> statistics[6][6][6];
    
    vector <vector <int> > results;
    
public:
    void solve() {
        for (int i = 2; i <= 5; i++) {
            for (int j = 2; j <= 5; j++) {
                for (int k = 2; k <= 5; k++) {
                    vector <int> sample = {i, j, k};
                    for (int q = 0; q < 2; q++) {
                        for (int w = 0; w < 2; w++) {
                            for (int e = 0; e < 2; e++) {
                                int product = 1;
                                if (q) product *= i;
                                if (w) product *= j;
                                if (e) product *= k;
                                statistics[i][j][k].push_back(product);
                            }
                        }
                    }
                }
            }
        }
        
        results.resize(R);
        for (int t = 0; t < R; t++) {
            double bestScore = 0.;
            int bi, bj, bk;
            for (int i = 2; i <= 5; i++) {
                for (int j = 2; j <= 5; j++) {
                    for (int k = 2; k <= 5; k++) {
                        double score = 0.;
                        for (int q = 0; q < products[t].size(); q++) {
                            for (int w = 0; w < statistics[i][j][k].size(); w++) {
                                if (products[t][q] == statistics[i][j][k][w]) {
                                    score += 1.;
                                }
                            }
                        }
                        if (bestScore < score) {
                            bi = i;
                            bj = j;
                            bk = k;
                            bestScore = score;
                        }
                    }
                }
            }
            results[t].push_back(bi);
            results[t].push_back(bj);
            results[t].push_back(bk);
        }
    }
    
    void read(istream &in) {
        in >> R >> N >> M >> K;
        products.resize(R);
        for (int i = 0; i < R; i++) {
            products[i].resize(K);
            for (int j = 0; j < K; j++) {
                in >> products[i][j];
            }
        }
    }
    
    void write(ostream &out) {
        for (int i = 0; i < R; i++) {
            out << endl;
            for (int j = 0; j < N; j++) out << results[i][j];
        }
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