//
//  main.cpp
//  CodeJam.Q.B
//
//  Created by Maxim Piskunov on 13.04.2013.
//  Copyright (c) 2013 Maxim Piskunov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct test_case {
    int N;
    int M;
    vector <vector <int> > a;
};

void read(vector <test_case> *tests)
{
    ifstream in("input");
    
    int T;
    in >> T;
    tests->resize(T);
    for (int i = 0; i < T; i++) {
        in >> (*tests)[i].N >> (*tests)[i].M;
        (*tests)[i].a.resize((*tests)[i].N);
        for (int j = 0; j < (*tests)[i].N; j++) {
            (*tests)[i].a[j].resize((*tests)[i].M);
            for (int k = 0; k < (*tests)[i].M; k++) {
                in >> (*tests)[i].a[j][k];
            }
        }
    }
    
    in.close();
}

void write(vector <string> *results)
{
    ofstream out("output");
    
    out << "Case #1: " << (*results)[0];
    for (int i = 1; i < results->size(); i++) {
        out << endl << "Case #" << i+1 << ": " << (*results)[i];
    }
    
    out.close();
}

string solve_test (test_case test)
{
    vector <int> minHorizontalCut(test.N, 0);
    vector <int> minVerticalCut(test.M, 0);
    for (int i = 0; i < test.N; i++) {
        for (int j = 0; j < test.M; j++) {
            minHorizontalCut[i] = max(minHorizontalCut[i], test.a[i][j]);
            minVerticalCut[j] = max(minVerticalCut[j], test.a[i][j]);
        }
    }
    
    for (int i = 0; i < test.N; i++) {
        for (int j = 0; j < test.M; j++) {
            if (test.a[i][j] != min(minHorizontalCut[i], minVerticalCut[j])) return "NO";
        }
    }
    
    return "YES";
}

void solve(vector <test_case> *tests, vector <string> *results)
{
    results->resize(tests->size());
    for (int i = 0; i < tests->size(); i++) (*results)[i] = solve_test((*tests)[i]);
}

int main(int argc, const char * argv[])
{
    vector <test_case> tests;
    vector <string> results;
    
    read(&tests);
    solve(&tests, &results);
    write(&results);
    
    return 0;
}