//
//  main.cpp
//  Infinite House of Pancakes
//
//  Created by apple on 15/4/11.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

typedef map<int, int> mii;
typedef map<int, int>::iterator mit;
typedef map<int, int>::reverse_iterator rmit;

#define MIN(a, b) (a > b ? b : a)

int best;

void recur(mii mi, int special){
    best = MIN(best, mi.rbegin()->first + special);
    if (mi.rbegin()->first <= 3){
        return;
    }
    int p = mi.rbegin()->first;
    int num = mi.rbegin()->second;
    mi.erase((++mi.rbegin()).base());
    for (int i = 1; i <= p / 2; ++i){
        int part1, part2;
        part1 = i; part2 = p - i;
        mii temp = mi;
        temp[part1] += num;
        temp[part2] += num;
        recur(temp, special + num);
//        mi[part1] -= num;
//        mi[part2] -= num;
//        mit it;
//        it = mi.find(part1);
//        if (it != mi.end() && it->second == 0){
//            mi.erase(it);
//        }
//        it = mi.find(part2);
//        if (it != mi.end() && it->second == 0){
//            mi.erase(it);
//        }
    }
}

int main(int argc, const char * argv[]) {
    ofstream cout("/Users/apple/Documents/coding/Xcode/Google Code Jam/Infinite House of Pancakes/Infinite House of Pancakes/output1.txt");
    ifstream cin("/Users/apple/Documents/coding/Xcode/Google Code Jam/Infinite House of Pancakes/Infinite House of Pancakes/B-small-attempt1.in.txt");
    int t = 0, T;
    cin >> T;
    while(t++ != T){
        mii m;
        best = INT32_MAX;
        int d = 0, D;
        cin >> D;
        while (d++ != D){
            int P; cin >> P;
            m[P]++;
        }
        best = m.rbegin()->first;
        recur(m, 0);
        cout << "Case #" << t << ": " << best << endl;
    }
    return 0;
}
