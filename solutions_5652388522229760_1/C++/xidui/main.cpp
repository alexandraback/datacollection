//
//  main.cpp
//  Counting Sheep
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
    ofstream cout("/Users/xidui/Documents/xidui/practices/gcj/Counting Sheep/Counting Sheep/output2.txt");
    ifstream cin("/Users/xidui/Documents/xidui/practices/gcj/Counting Sheep/Counting Sheep/A-large.in");
    int T, t = 0;
    cin >> T;
    while (t++ != T){
        set<int> si;
        int N; cin >> N;
        int i = 0;
        for (; i < 1000000; ++i){
            generate_digit(si, N * i);
            if (si.size() == 10) break;
        }
        cout << "Case #" << t << ": ";
        if (si.size() == 10) cout << i * N << endl;
        else cout << "INSOMNIA" << endl;
    }
    return 0;
}