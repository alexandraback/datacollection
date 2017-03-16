//
//  main.cpp
//  Standing Ovation
//
//  Created by apple on 15/4/11.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ofstream cout("/Users/apple/Documents/coding/Xcode/Google Code Jam/Standing Ovation/Standing Ovation/output2.txt");
    ifstream cin("/Users/apple/Documents/coding/Xcode/Google Code Jam/Standing Ovation/Standing Ovation/A-large.in.txt");
    int T, t = 0;
    cin >> T;
    while (t++ != T){
        int S, count = 0;;
        string s;
        cin >> S >> s;
        int shy = 0;
        for (int i = 0; i <= S; ++i){
            if (shy >= i){
                shy += s[i] - '0';
                continue;
            }else{
                ++count;
                ++shy;
                shy += s[i] - '0';
            }
        }
        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}
