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

bool IsOK(const string &t, int n) {
    int j = 0;
    while (j < t.size()) {
        while (j < t.size() && VOWELS.find(t[j]) != -1) {
            j++;
        }
        int i = j;
        while (i < t.size() && VOWELS.find(t[i]) == -1) {
            i++;
        }
        if (i - j >= n) {
            return true;
        }
        j = i;
    }
    return false;
}

string t;

int Solve(const string &s, int n) {
    int res = 0;
    for (int i = 0; i <= s.size() - n; i++) {
        for (int i_len = n; i_len <= s.size() - i; i_len++) {
            t = s.substr(i, i_len);
            res += IsOK(t, n);
        }
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
        int res = Solve(s, n);
        cout << "Case #" << i_t << ": " << res << "\n";
    }
}