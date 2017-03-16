//
//  main.cpp
//  Coin Jam
//
//  Created by 王越 on 16/4/9.
//  Copyright © 2016年 王越. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int c = 0;

int main(int argc, const char * argv[]) {
    ofstream cout("/Users/xidui/Documents/xidui/practices/gcj/Coin Jam/Coin Jam/output2.txt");
    cout << "Case #1:" << endl;
    set<string> ss;
    
    // (15 * 14 / 2)^2
    for (int i = 1; i < 31; i += 2) {
        for (int i1 = i + 2; i1 < 31; i1 += 2) {
            for (int j = 2; j < 31; j += 2) {
                for (int j1 = j + 2; j1 < 31; j1 += 2) {
                    string s = "10000000000000000000000000000001";
                    s[i] = '1'; s[i1] = '1'; s[j] = '1'; s[j1] = '1';
                    ss.insert(s);
                }
            }
        }
    }
    
    set<string>::iterator it = ss.begin();
    for (int i = 0; i < 500; ++i) {
        cout << *it << " 3 4 5 6 7 8 9 10 11" << endl;
        it++;
    }
    return 0;
}
