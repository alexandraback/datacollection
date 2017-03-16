//
//  main.cpp
//  CodeJamAC
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
#include <queue>

#define filename "C-small-attempt1"

using namespace std;

struct input {
    int n;
    vector <int> bbf;
};

struct output {
    int largestCircle;
};

void read(ifstream &in, input &test) {
    in >> test.n;
    test.bbf.resize(test.n);
    for (int i = 0; i < test.n; i++) {
        in >> test.bbf[i];
        test.bbf[i]--;
    }
}

void write(ofstream &out, output test) {
    out << test.largestCircle;
}

output solve (input test) {
    output result;
    result.largestCircle = 0;
    
    vector<vector<int> > inverse;
    inverse.resize(test.n);
    for (int i = 0; i < test.n; i++) {
        inverse[test.bbf[i]].push_back(i);
    }
    
    int legTotal = 0;
    
    vector<bool> legVisited(test.n, false);
    
    for (int i = 0; i < test.n; i++) {
        vector<int> visited(test.n, false);
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = test.bbf[j];
        }
        
        int k = test.bbf[j];
        int length = 1;
        while (k != j) {
            k = test.bbf[k];
            length++;
        }
        
        if (length == 2) {
            
            if (legVisited[k]) continue;
            
            legVisited[k] = true;
            
            int leg1Length = -2;
            vector<int> distances(test.n, -1);
            distances[k] = 0;
            queue<int> q;
            q.push(k);
            while (!q.empty()) {
                int current = q.front();
                for (int v = 0; v < inverse[current].size(); v++) {
                    if (inverse[current][v] == test.bbf[k]) continue;
                    distances[inverse[current][v]] = distances[current] + 1;
                    q.push(inverse[current][v]);
                }
                q.pop();
            }
            for (int i = 0; i < distances.size(); i++) {
                leg1Length = max(leg1Length, distances[i] + 1);
            }
            
            
            /*int leg2Length = -2;
            vector<int> distances2(test.n, -1);
            distances2[test.bbf[k]] = 0;
            queue<int> q2;
            q2.push(test.bbf[k]);
            while (!q2.empty()) {
                int current = q2.front();
                for (int v = 0; v < inverse[current].size(); v++) {
                    if (inverse[current][v] == k) continue;
                    distances2[inverse[current][v]] = distances2[current] + 1;
                    q2.push(inverse[current][v]);
                }
                q2.pop();
            }
            for (int i = 0; i < distances2.size(); i++) {
                leg2Length = max(leg2Length, distances2[i] + 1);
            }*/
            
            legTotal += leg1Length;
        }
        
        result.largestCircle = max(result.largestCircle, length);
    }
    
    if (legTotal > result.largestCircle) result.largestCircle = legTotal;
    
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
    for (int i = 0; i < tests.size(); i++) {
        cout << "test " << i << endl;
        results[i] = solve(tests[i]);
    }
}

int main(int argc, const char * argv[]) {
    vector <input> tests;
    vector <output> results;
    
    readAll(tests);
    solveAll(tests, results);
    writeAll(results);
    
    return 0;
}