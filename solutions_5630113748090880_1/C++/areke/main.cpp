/*
 ID: areke
 PROG: cf
 LANG: C++
 */

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <limits>
#include <queue>
#include <stack>

using namespace std;

int main() {

    ifstream fin("B-large.in");
    ofstream fout("output.out");
    int tests;
    fin >> tests;
    for (int test = 0; test < tests; test++) {
        
        int n;
        fin >> n;
        long long heights[3000] = {0};
        long long x;
        for (int i = 0; i < 2*n*n-n; i++) {
            fin >> x;
            heights[x]++;
        }
        vector<long long> v;
        for (int i = 0; i < 3000; i++) {
            if (heights[i] % 2 == 1) v.push_back(i);
        }
        sort(v.begin(), v.end());
        fout << "Case #" << test+1 << ": ";
        for (int i = 0; i < n; i++) {
            fout << v[i];
            if (i == n-1) fout << endl;
            else fout << " ";
        }
        
        
    }
    
}
