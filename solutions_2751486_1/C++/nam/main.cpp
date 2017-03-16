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

const string VOWELS = "aeiou";
const int MAX_L = 1000005;
int len_of_con[MAX_L];
int near_mor_n[MAX_L];

i64 Solve(const string &s, int n) {
    memset(len_of_con, 0, sizeof(len_of_con));
    i64 res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (VOWELS.find(s[i]) == -1) {
            len_of_con[i] = len_of_con[i + 1] + 1;
        }
    }
    memset(near_mor_n, -1, sizeof(near_mor_n));
    for (int i = s.size() - n; i >= 0; i--) {
        if (len_of_con[i] >= n) {
            near_mor_n[i] = i;
        } else {
            near_mor_n[i] = near_mor_n[i + 1];
        }
    }
    for (int i = 0; i <= s.size() - n; i++) {
        if (near_mor_n[i] == -1) {
            break;
        }
        res += s.size() - (near_mor_n[i] + n) + 1;
    }
    return res;
}

string s;

int main() {
#ifdef NOVACO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i_t = 1; i_t <= t; i_t++) {
        int n;
        cin >> s >> n;
        i64 res = Solve(s, n);
        cout << "Case #" << i_t << ": " << res << "\n";
    }
}