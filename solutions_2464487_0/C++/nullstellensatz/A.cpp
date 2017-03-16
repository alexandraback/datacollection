


/*
    Prob:   Google code jam Round 1A 2013 A
    Author: peanut
    Time:   27/04/13 08:58
    Description:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int T;
long long r, t;

bool check(long long lim) {
    long long begin = r, end = r + lim + lim - 1, num = lim + lim;
    return ((t + t) / num >= (begin + end));
}

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        string input_file  = string(argv[1]) + ".in",
               output_file = string(argv[1]) + ".out";
        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);
    }
    
    cin >> T;
    for (int testcase = 1; testcase <= T; ++ testcase) {
        cin >> r >> t;
        long long l = 1, h = t + 1;
        while (l < h - 1) {
            long long m = (l + h) >> 1;
            if (check(m)) l = m; else h = m;
        }
        while (l < h && !check(h)) -- h;
        cout << "Case #" << testcase << ": " << h << endl;
    }
    
    return 0;
}
