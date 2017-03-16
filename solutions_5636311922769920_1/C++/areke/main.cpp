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
    ifstream fin ("D-large.in");
    ofstream fout ("output.out");
    long long t;
    fin >> t;
    for (int test = 0; test < t; test++) {
        long long k, c, s;
        fin >> k >> c >> s;
        fout << "Case #" << test+1 << ": ";
        if (c*s >= k) {
            long long m;
            long long tot = 1;
            for (int i = 0; i < c; i++) {
                tot *= k;
            }
            if (k < c) m = k;
            else m = c;
            long long p = 1;
            long long pc = 1;
            long long next = 0;
            for (int i = 0; i < m; i++) {
                p *= k;
            }
            p /= k;
            pc = p;
            long long num = 0;
            for (int i = 0; i < m; i++) {
                num += i * p;
                next += p;
                p /= k;
            }
            num++;
            long long d = k/m;
            if (k % m != 0) d++;
            
            for (int i = 0; i < d; i++) {
                long long x = 0;
                if (i == d-1 && d*m > k) {
                    x += (d*m-k)*next;
                }
                fout << num+(next)*i*m-x;
                if (i == d-1) fout << endl;
                else fout << " ";
            }
            
        }
        else {
            fout << "IMPOSSIBLE" << endl;
        }
    }
    
}