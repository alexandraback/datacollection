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

    ifstream fin("A-small-attempt0.in");
    ofstream fout("output.out");
    int tests;
    fin >> tests;
    for (int test = 0; test < tests; test++) {
        
        string s;
        fin >> s;
        string t = "";
        t += s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] >= t[0]) {
                t = s[i]+t;
            }
            else {
                t += s[i];
            }
        }
        fout << "Case #" << test+1 << ": " << t << endl;
        
    }
    
}
