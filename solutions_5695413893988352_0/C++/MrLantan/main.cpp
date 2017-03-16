//
//  main.cpp
//  B
//
//  Created by Andrey Cherevko on 4/30/16.
//  Copyright © 2016 Andrey Cherevko. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int poww (int x) {
    int ans = 1;
    for (int i = 0; i < x; i++)
        ans *= 10;
    return ans;
}

string s1, s2;

bool check (int a, int b) {
    bool f = true;
    string ss1 = to_string(a);
    string ss2 = to_string(b);
    while (ss1.length() != s1.length()) {
        ss1 = '0' + ss1;
    }
    while (ss2.length() != s2.length()) {
        ss2 = '0' + ss2;
    }
    for (int i = 0; i < s1.length(); i++) {
        if (ss1[i] == s1[i] || s1[i] == '?')
            continue;
        else
            f = false;
    }
    for (int i = 0; i < s2.length(); i++) {
        if (ss2[i] == s2[i] || s2[i] == '?')
            continue;
        else
            f = false;
    }
    return f;
}

string myToString (int x, int length) {
    string ans = to_string(x);
    while ((int)ans.length() < length) {
        ans = '0' + ans;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 0;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int minDiff = 1000000;
        string left = "";
        string right = "";
        cin >> s1 >> s2;
        for (int i = 0; i < poww((int)s1.length()); i++) {
            for (int j = 0; j < poww((int)s1.length()); j++) {
                if (abs (i - j) < minDiff && check(i, j)) {
                    left = myToString(i, (int)s1.length());
                    right = myToString(j, (int)s2.length());
                    minDiff = abs (i - j);
                }
            }
        }
        cout << "Case #" << tt + 1 << ": " << left << " " << right << endl;
    }
    return 0;
}
