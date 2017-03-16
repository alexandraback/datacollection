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

string solve(string &s) {
    int cnt[26] = {0};
    int res[10] = {0};
    for (char ch : s) {
        cnt[ch - 'A']++;
    }
    
    res[8] = cnt['G' - 'A'];
    res[4] = cnt['U' - 'A'];
    res[2] = cnt['W' - 'A'];
    res[6] = cnt['X' - 'A'];
    res[0] = cnt['Z' - 'A'];
    
    string first[] = {"ZERO", "TWO", "FOUR", "SIX", "EIGHT"};
    for (char ch : first[0]) {
        cnt[ch - 'A'] -= res[0];
    }
    for (char ch : first[1]) {
        cnt[ch - 'A'] -= res[2];
    }
    for (char ch : first[2]) {
        cnt[ch - 'A'] -= res[4];
    }
    for (char ch : first[3]) {
        cnt[ch - 'A'] -= res[6];
    }
    for (char ch : first[4]) {
        cnt[ch - 'A'] -= res[8];
    }
    
    res[5] = cnt['F' - 'A'];
    res[3] = cnt['H' - 'A'];
    res[7] = cnt['S' - 'A'];
    
    for (char ch : "FIVE") {
        cnt[ch - 'A'] -= res[5];
    }
    for (char ch : "THREE") {
        cnt[ch - 'A'] -= res[3];
    }
    for (char ch : "SEVEN") {
        cnt[ch - 'A'] -= res[7];
    }
    
    res[9] = cnt['I' - 'A'];
    
    
    for (char ch : "NINE") {
        cnt[ch - 'A'] -= res[9];
    }
    
    res[1] = cnt['O' - 'A'];
    
    
    string qq = "";
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < res[i]; ++j)
            qq += char(i + '0');
    return qq;
}

int main(int argc, const char * argv[]) {

//    int cnt[26] = {0};
//    string ss[] = {"ONE", "NINE"};
//    for (int i = 0; i < 5; ++i) {
//        for (char ch : ss[i]) {
//            cnt[ch - 'A']++;
//        }
//    }
//    for (int i = 0; i < 26; ++i)
//        cout << char(i + 'A') << " ";
//    cout << endl;
//    for (int i = 0; i < 26; ++i)
//        cout << cnt[i] << " ";
//    cout << endl;
    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        string s;
        cin >> s;
        cout << "Case #" << tt + 1 << ": " << solve(s) << endl;
    }
    return 0;
}
