//Copyright (c) Nguyen Huy Truong Nam
#pragma comment(linker, "/STACK:0x04000000")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <climits>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;
typedef unsigned int uint;
typedef long long i64;
typedef unsigned long long ui64;
typedef long double ld;

string Solve(int x, int y) {
    string res;
    if (x > 0) {
        for (int i = 0; i < x; i++) {
            res += "WE";
        }
    } else {
        for (int i = 0; i < -x; i++) {
            res += "EW";
        }
    }
    if (y > 0) {
        for (int i = 0; i < y; i++) {
            res += "SN";
        }
    } else {
        for (int i = 0; i < -y; i++) {
            res += "NS";
        }
    }
    return res;
}

string res;

int main() {
#ifdef NOVACO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i_t = 1; i_t <= t; i_t++) {
        int x;
        int y;
        cin >> x >> y;
        res = Solve(x, y);
        cout << "Case #" << i_t << ": " << res << "\n";
    }
}