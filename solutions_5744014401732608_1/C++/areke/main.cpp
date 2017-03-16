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

string toBinary(long long num, long long b) {
    string s;
    while (num != 0) {
        s = (num % 2 == 0 ? "0" : "1") + s;
        num /= 2;
    }
    while (s.length() < b) {
        s = "0" + s;
    }
    return s;
}

int main() {
    
    
    ifstream fin ("B-large.in");
    ofstream fout ("output.out");
    
    long long tests;
    fin >> tests;
    for (int test = 0; test < tests; test++) {
        
        
        
        fout << "Case #" << test+1 << ": ";
        long long b, m;
        fin >> b >> m;
        long long x = 1;
        for (int i = 0; i < b-2; i++) {
            x *= 2;
        }
        if (m == x) {
            fout << "POSSIBLE" << endl;
            for (int i = 0; i < b-1; i++) {
                for (int j = 0; j < b; j++) {
                    if (j > i) fout << 1;
                    else fout << 0;
                    if (j == b-1) fout << endl;
                }
            }
            for (int i = 0; i < b; i++) {
                fout << 0;
                if (i == b-1) fout << endl;
            }
        }
        else if (m < x) {
            fout << "POSSIBLE" << endl;
            string s = toBinary(m, b-2);
            for (int i = 0; i < b; i++) {
                if (i == 0 || i == b-1) fout << 0;
                else {
                    if (s[i-1] == '1') fout << 1;
                    else fout << 0;
                }
                if (i == b-1) fout << endl;
            }
            for (int i = 0; i < b-2; i++) {
                for (int j = 0; j < b; j++) {
                    if (j > i+1) fout << 1;
                    else fout << 0;
                    if (j == b-1) fout << endl;

                }
            }
            for (int i = 0; i < b; i++) {
                fout << 0;
                if (i == b-1) fout << endl;
            }
            
        }
        else {
            fout << "IMPOSSIBLE" << endl;
        }

        
    
        
        
        
        
        
    }
    
}