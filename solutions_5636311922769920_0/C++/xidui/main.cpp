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

using namespace std;


int main(int argc, const char * argv[]) {
    ofstream cout("/Users/xidui/Documents/xidui/practices/gcj/Fractiles/Fractiles/output1.txt");
    ifstream cin("/Users/xidui/Documents/xidui/practices/gcj/Fractiles/Fractiles/D-small-attempt0.in");
    int T, t = 0;
    cin >> T;
    while (t++ != T){
        int K, C, S;
        cin >> K >> C >> S;
        cout << "Case #" << t << ":";
        for (int i = 1; i <= S; ++i) {
            cout << " " << i;
        }
        cout << endl;
    }
    return 0;
}