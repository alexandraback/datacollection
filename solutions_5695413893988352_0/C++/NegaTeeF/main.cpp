//
//  main.cpp
//  A
//
//  Created by Misha Babenko on 3/28/15.
//  Copyright (c) 2015 Misha Babenko. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <cassert>
#include <unordered_set>

using namespace std;

typedef long long ll;

string solve(string s1, string s2) {
    int len = (int)s1.length();
    
    int res1 = -1, res2 = -1;
    
    for (int first = 0; first < 1000; ++first) { 
        for (int second = 0; second < 1000; ++second) {
            
            string a = to_string(first);
            if (a.length() > len) continue;
            string b = to_string(second);
            if (b.length() > len) continue;
            
            bool ok = true;
            while (a.length() < len) 
                a = "0" + a;
            while (b.length() < len) 
                b = "0" + b;
            
            for (int i = 0; i < len; ++i) {
                if (s1[i] != '?' && a[i] != s1[i]) {
                    ok = false;
                    break;
                }
                if (s2[i] != '?' && b[i] != s2[i]) {
                    ok = false;
                    break;
                }
            }
            
            if (!ok) continue;
            
            
            if (res1 == -1) {
                res1 = first;
                res2 = second;
                continue;
            }
            if (abs(first - second) < abs(res1 - res2)) {
                res1 = first;
                res2 = second;
                continue;
            }
            
            if (abs(first - second) > abs(res1 - res2)) {
                continue;
            }
            
            if (first < res1 || (first == res1 && second < res2)) {
                res1 = first;
                res2 = second;
            }
        }
    }
    
    
    string a = to_string(res1);
    string b = to_string(res2);
    while (a.length() < len) 
        a = "0" + a;
    while (b.length() < len) 
        b = "0" + b;
    return a + " " + b;
}

int main(int argc, const char * argv[]) {
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; ++t) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << "Case #" << t + 1 << ": " << solve(s1, s2) << endl;
    }
    return 0;
}
