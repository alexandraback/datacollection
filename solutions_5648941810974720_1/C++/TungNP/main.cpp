//
//  main.cpp
//  A
//
//  Created by ianto on 4/30/16.
//  Copyright © 2016 TungNguyen. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<int> veci;
typedef vector<string> vecs;

veci read_int(int N){
    veci vi(N);
    for (int i = 0; i < N; i++) {
        cin >> vi[i];
    }
    return vi;
}

vecs read_string(int N){
    vecs vs(N);
    for (int i = 0; i < N; i++) {
        cin >> vs[i];
    }
    return vs;
}

int count_chs(string *s, string chs){
    string str = *s;
    string strl = str;
    int count = 0;
    while (str.length() > 0) {
        bool found = true;
        strl = str;
        for (int i = 0; i < chs.length(); i++) {
            for (int j = 0; j < str.length(); j++) {
                if (chs[i] == str[j]) {
                    str.erase(str.begin() + j);
                    break;
                }
                if (j == str.length() - 1) {
                    found = false;
                }
            }
            if (!found) {
                *s = strl;
                return count;
            }
        }
        count++;
    }
    return count;
}

int main(int argc, const char * argv[]) {
//    freopen("test.txt", "r", stdin);
    
    int T; cin >> T;
    for (int Case = 1; Case <= T; Case++) {
        string S; cin >> S;
        
        veci count(10);
        count[0] = count_chs(&S, "ZERO");
        count[2] = count_chs(&S, "TWO");
        count[4] = count_chs(&S, "FOUR");
        count[6] = count_chs(&S, "SIX");
        count[8] = count_chs(&S, "EIGHT");
        count[1] = count_chs(&S, "ONE");
        count[3] = count_chs(&S, "THREE");
        count[5] = count_chs(&S, "FIVE");
        count[7] = count_chs(&S, "SEVEN");
        count[9] = count_chs(&S, "NINE");
        
        string re = "";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < count[i]; j++) {
                re += to_string(i);
            }
        }
        
        cout << "Case #" << Case << ": " << re << endl;
    }
    
    return 0;
}
