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
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    ofstream cout("/Users/xidui/Documents/xidui/practices/gcj/Coin Jam/Coin Jam/output1.txt");

    
    string div = "3 4 5 6 7 8 9 10 11";
    cout << "Case #1:" << endl;
    cout << "1000000000000001 " << div << endl;
    
    vector<int> vi1{2, 4, 6, 8, 10, 12, 14};
    vector<int> vi2{1, 3, 5, 7, 9, 11, 13};
    
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            string s = "1000000000000001";
            s[vi1[i]] = '1';
            s[vi2[j]] = '1';
            cout << s << " " << div << endl;
        }
    }
    
    return 0;
}
