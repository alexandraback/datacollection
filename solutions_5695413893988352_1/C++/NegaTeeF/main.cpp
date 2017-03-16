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

ll res1 = -1, res2;

string q1, q2;

bool QQ;

void rec(string &cur1, string &cur2, int pos, bool eq) {
    if (pos == q1.length()) {
        ll first = stoll(cur1);
        ll second = stoll(cur2);
        assert(first <= second);
        if (res1 == -1) {
            res1 = first;
            res2 = second;
            QQ = true;
            return;
        }
        if (abs(first - second) < abs(res1 - res2)) {
            res1 = first;
            res2 = second;
            QQ = true;
            return;
        }
        
        if (abs(first - second) > abs(res1 - res2)) {
            return;
        }
        
        if (first < res1 || (first == res1 && second < res2)) {
            res1 = first;
            res2 = second;
            QQ = true;
        }
            
        return;
        
        
    }
    
    if (q1[pos] == '?' && q2[pos] == '?') {
        if (eq) {
            cur1.push_back('0');
            cur2.push_back('0');
            rec(cur1, cur2, pos + 1, true);
            cur1.pop_back();
            cur2.pop_back();
            
            cur1.push_back('0');
            cur2.push_back('1');
            rec(cur1, cur2, pos + 1, false);
            cur1.pop_back();
            cur2.pop_back();
        } else {
            cur1.push_back('9');
            cur2.push_back('0');
            rec(cur1, cur2, pos + 1, false);
            cur1.pop_back();
            cur2.pop_back();
        }
    }
    if (q1[pos] == '?' && q2[pos] != '?') {
        if (eq) {
            cur1.push_back(q2[pos]);
            cur2.push_back(q2[pos]);
            rec(cur1, cur2, pos + 1, true);
            cur1.pop_back();
            cur2.pop_back();
            
            if (q2[pos] != '0') {
                cur1.push_back(q2[pos] - 1);
                cur2.push_back(q2[pos]);
                rec(cur1, cur2, pos + 1, false);
                cur1.pop_back();
                cur2.pop_back();
            }
        } else {
            cur1.push_back('9');
            cur2.push_back(q2[pos]);
            rec(cur1, cur2, pos + 1, false);
            cur1.pop_back();
            cur2.pop_back();
        }
    }
    if (q1[pos] != '?' && q2[pos] == '?') {
        if (eq) {
            cur1.push_back(q1[pos]);
            cur2.push_back(q1[pos]);
            rec(cur1, cur2, pos + 1, true);
            cur1.pop_back();
            cur2.pop_back();
            
            if (q1[pos] != '9') {
                cur1.push_back(q1[pos]);
                cur2.push_back(q1[pos] + 1);
                rec(cur1, cur2, pos + 1, false);
                cur1.pop_back();
                cur2.pop_back();
            }
        } else {
            cur1.push_back(q1[pos]);
            cur2.push_back('0');
            rec(cur1, cur2, pos + 1, false);
            cur1.pop_back();
            cur2.pop_back();
        }
    }
    if (q1[pos] != '?' && q2[pos] != '?') {
        if (eq) {
            if (q1[pos] < q2[pos]) {
                cur1.push_back(q1[pos]);
                cur2.push_back(q2[pos]);
                rec(cur1, cur2, pos + 1, false);
                cur1.pop_back();
                cur2.pop_back();
            }
            if (q1[pos] == q2[pos]) {
                cur1.push_back(q1[pos]);
                cur2.push_back(q2[pos]);
                rec(cur1, cur2, pos + 1, true);
                cur1.pop_back();
                cur2.pop_back();
            }
            if (q1[pos] > q2[pos]) {
                return;
            }
        } else {
            cur1.push_back(q1[pos]);
            cur2.push_back(q2[pos]);
            rec(cur1, cur2, pos + 1, false);
            cur1.pop_back();
            cur2.pop_back();
        }
    }
}


string solve_clever(string s1, string s2) {
    q1 = s1;
    q2 = s2;
    res1 = -1;    
    string cur1, cur2;
    rec(cur1, cur2, 0, true);
    QQ = false;
    swap(q1, q2);
    rec(cur1, cur2, 0, true);
    
    string a = to_string(res1);
    string b = to_string(res2);
    while (a.length() < q1.length()) 
        a = "0" + a;
    while (b.length() < q1.length()) 
        b = "0" + b;
    if (QQ)
        return b + " " + a; 
    else
        return a + " " + b;
}

void Test() {
    srand(time(0));
    int id = 0;
    while (true) {
        id++;
        int len = rand() % 3 + 1;
        string s1 = "";
        string s2 = "";
        for (int i = 0; i < len; ++i) {
            if (rand() % 2 == 0) {
                s1 += char('0' + rand() % 10);
            } else {
                s1 += '?';
            }
            if (rand() % 2 == 0) {
                s2 += char('0' + rand() % 10);
            } else {
                s2 += '?';
            }
        }
        string stupid = solve(s1, s2);
        string clever = solve_clever(s1, s2);
        
        if (stupid == clever) {
            cout << "OK " << id <<  endl;
        } else {
            cout << "WA" << endl;
            cout << s1 << " " << s2 << endl;
            cout << "STUPID: " << stupid << endl;
            cout << "CLEVER: " << clever << endl;
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
//    Test();
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; ++t) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << "Case #" << t + 1 << ": " << solve_clever(s1, s2) << endl;
    }
    return 0;
}
