#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stdlib.h>

using namespace std;

int k, l, s;

string keyboard, target;

int g() {
    
    set<char> alphabet(keyboard.begin(), keyboard.end());

    for (auto c : target) {
        if (!alphabet.count(c)) {
            return 0;
        }
    }

    string str = "";
    if (str.length() > s) {
        return 0;
    }

    for (int i = 0; i < s; ++i) {
        if (i < str.length()) {
            if (str.substr(i) == target.substr(0, str.length() - i)) {
                str += target.substr(str.length() - i);
            }
        }
        else {
            str += target;
        }
    }
    str = str.substr(0, s);
    int d = 0;
    for (int i = 0; i < s; ++i) {
        if (str.substr(i, target.length()) == target) {
            ++d;
        }
    }
    return d;
}

double f(int k, int l, int s) {
    map<char, int> m;
    for (auto c : keyboard) {
        if (!m.count(c)) {
            m[c] = 0;
        }
        ++m[c];
    }
    map<char, double> md;
    for (auto c : m) {
        double x = (double)c.second / keyboard.length();
        md[c.first] = x;
    }
    double p = 1;
    for (auto c : target) {
        p *= md[c];
    }
    if (target.length() > s) {
        p = 0;
    }

    int y = max(0, s - l + 1);

    return g() - p * y;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        
        cin >> k >> l >> s;
        
        cin >> keyboard >> target;
        printf("Case #%d: %.7lf\n", i, f(k, l, s));
    }
    return 0;
}
