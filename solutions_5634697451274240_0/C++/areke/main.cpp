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
string toString(long long n) {
    ostringstream s;
    s << n;
    return s.str();
}

bool good(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') return false;
    }
    return true;
}

string reverse(string s) {
    string t = "";
    for (int i = s.length()-1; i >= 0; i--) {
        t += s[i];
    }
    return t;
}

int main() {
    ifstream fin ("B-small-attempt0.in");
    ofstream fout ("output.out");
    long long tests;
    fin >> tests;
    for (long long test = 0; test < tests; test++) {
        string s;
        fin >> s;
        long long cnt = 0;
        char last = s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != last) cnt++;
            last = s[i];
        }
        if (s[s.length()-1] == '-') cnt++;
        fout << "Case #" << test+1 << ": " << cnt << endl;
        
    }
    
}