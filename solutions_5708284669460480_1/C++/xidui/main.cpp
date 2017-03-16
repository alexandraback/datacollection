//
//  main.cpp
//  2015R1C_B
//
//  Created by apple on 15/5/10.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

int checkstring(string s){
    int count = 0;
    for (int i = 1; i < s.length(); ++i){
        if (s.substr(0, i) == s.substr(s.length() - i, i)){
            count = i;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    freopen("/Users/apple/Documents/coding/Xcode/Google Code Jam/2015R1C_B/2015R1C_B/output2.txt", "w", stdout);
    freopen("/Users/apple/Documents/coding/Xcode/Google Code Jam/2015R1C_B/2015R1C_B/B-large.in.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t){
        // each test case starts here
        int K, L, S; cin >> K >> L >> S;
        string keys; cin >> keys;
        string target; cin >> target;
        map<char, int> mci;
        for (int i = 0; i < keys.length(); ++i){
            mci[keys[i]]++;
        }
        bool flag = true;
        for (int i = 0; i < target.length(); ++i){
            if (mci.find(target[i]) == mci.end()){
                flag = false;
                break;
            }
        }
        if (flag == false){
            cout << "Case #" << t << ": " << 0 << endl;
            continue;
        }
        
        int count = checkstring(target);
        int max = (S - count) / ((int)target.length() - count);
        
        double prob = 1;
        for (int i = 0; i < target.size(); ++i){
            prob *= (double)mci[target[i]] / K;
        }
        cout << "Case #" << t << ": " << std::fixed << setprecision(10) << max - prob * (S - L + 1) << endl;
    }

    return 0;
}