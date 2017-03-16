//
//  main.cpp
//  Fractiles
//
//  Created by 王越 on 16/4/9.
//  Copyright © 2016年 王越. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <math.h>

using namespace std;


int main(int argc, const char * argv[]) {
    ofstream cout("/Users/xidui/Documents/xidui/practices/gcj/Fractiles/Fractiles/output2.txt");
    ifstream cin("/Users/xidui/Documents/xidui/practices/gcj/Fractiles/Fractiles/D-large (2).in");
    int T, t = 0;
    cin >> T;
    while (t++ != T){
        int K, C, S;
        cin >> K >> C >> S;
        
        int ptr = 1;
        vector<unsigned long long> temp;
        while (S-- != 0 && ptr <= K){
            unsigned long long c = 0;
            int power = 0;
            while (ptr <= K && c + (ptr - 1) * pow(K, power) <= pow(K, C)) {
                c += (ptr++ - 1) * pow(K, power++);
            }
            temp.push_back(c);
        }
        
        cout << "Case #" << t << ":";
        if (ptr <= K) {
            cout << " IMPOSSIBLE";
        } else {
            for (auto i: temp) cout << " " << i;
        }
        cout << endl;
    }
    return 0;
}