//#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <deque>

using namespace std;

typedef double ld;
typedef long long ll;

const ld EPS = 1e-2;
const int INF = (int) 1e9;
const int N = (int) 2e3 + 5;
const ll M = (long long) 1e9 + 7;

bool good(int x, string &s) {
    int n = s.length();
    while (n) {
        if (!(x % 10 == (s[n - 1] - '0') || s[n - 1] == '?'))
            return 0;
        x /= 10, n--;
    }
    return 1;
}

string norm(int x, string &s) {
    int n = s.length();
    string res = "";
    while (n) {
        res += char(x % 10 + '0');
        x /= 10, n--;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve(string &s1, string &s2) {
    int mn = 100000, fs = 100000, a2;
    int tw = 10, n = s1.length();
    if (n == 2)
        tw = 100;
    if (n == 3)
        tw = 1000;

    for (int i = 0; i < tw; i++)
        for (int j = 0; j < tw; j++)
            if (good(i, s1) && good(j, s2) && abs(i - j) < mn) {
                mn = abs(i - j);

                fs = i;
                a2 = j;
            }
            else if (good(i, s1) && good(j, s2) && abs(i - j) == mn && i < fs)
                fs = i;
    //cout << mn << ' ' << fs << ' ' << a2 << ' ';
    cout << norm(fs, s1)  << ' ' << norm(a2, s1);

}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T = 10;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << "Case #" << t + 1 << ": ";
        solve(s1, s2);

        cout << endl;

    }
	return 0;
}

