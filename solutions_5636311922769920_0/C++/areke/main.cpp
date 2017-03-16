/*
 ID: areke
 PROG: butter
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

using namespace std;

int main() {
    ifstream fin ("D-small-attempt0.in");
    ofstream fout ("output.out");
    long long t;
    fin >> t;
    for (int test = 0; test < t; test++) {
        long long k, c, s;
        fin >> k >> c >> s;
        long long p = 1;
        for (int i = 0; i < c-1; i++) {
            p *= k;
        }
        fout << "Case #" << test+1 << ": ";
        for (int i = 0; i < s; i++) {
            fout << i*p+1;
            if (i == s-1) fout << endl;
            else fout << " ";
        }
    }
    
}