//
//  main.cpp
//  Revenge of the Pancakes
//
//  Created by 王越 on 16/4/9.
//  Copyright © 2016年 王越. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

void generate_digit(set<int>& si, long long i) {
    while (i != 0) {
        si.insert(i % 10);
        i /= 10;
    }
}

int main(int argc, const char * argv[]) {
    ofstream cout("/Users/xidui/Documents/xidui/practices/gcj/Revenge of the Pancakes/Revenge of the Pancakes/output1.txt");
    ifstream cin("/Users/xidui/Documents/xidui/practices/gcj/Revenge of the Pancakes/Revenge of the Pancakes/B-small-attempt0.in");
    int T, t = 0;
    cin >> T;
    while (t++ != T){
        string s;
        cin >> s;
        int count = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != s[i - 1]) ++count;
        }
        if (s[s.length() - 1] == '-') count++;
        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}