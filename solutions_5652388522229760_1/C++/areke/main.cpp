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

int main() {
    ifstream fin ("A-large.in");
    ofstream fout ("output.out");
    long long tests;
    fin >> tests;
    for (long long test = 0; test < tests; test++) {
        long long n;
        fin >> n;
        long long x = n;
        long long arr[10] = {0};
        if (n == 0) {
            fout << "Case #" << test+1 << ": INSOMNIA" << endl;
            continue;
        }
        while (true) {
            string s = toString(x);
            for (long long i = 0; i < s.length(); i++) {
                arr[s[i]-'0'] = 1;
            }
            bool b = true;
            for (long long i = 0; i < 10; i++) {
                if (arr[i] == 0) {
                    b = false;
                    break;
                }
            }
            if (b) {
                fout << "Case #" << test+1 << ": " << x << endl;
                break;
                
            }
            x += n;
        }
    }
    
}