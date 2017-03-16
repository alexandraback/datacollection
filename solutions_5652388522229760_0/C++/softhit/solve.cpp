//
// Created by mark on 4/8/16.
//
#include "includes.h"
#include <vector>
#include <iterator>
#include <algorithm>
bool checktrack(int * track) {
    for(int i = 0 ; i<10; i++) {
        if(track[i] !=1)
            return true;
    }
    return false;
}
int solve(int casenum) {
    int num ;
    cin >> num;
    int cnt = 1;
    int tmp = num;
    int ans;
    int track[10] = {0};
    if(num == 0) {
        tmp = -1;
    } else {
        while( checktrack(track)) {
            tmp = num * cnt;
            vector<int> array ;
            ostringstream convert;
            convert << tmp;
            for(auto &c: convert.str()) {
                array.push_back(int(c - '0'));
            }
//            cout << print_vector<int>(array);
            for(int j = 0; j < array.size();++j) {
                int p = array[j];
                if( p >=0 and p <=9) {
                   track[p] = 1;
                }
            }
            cnt ++;
        }
    }


    return tmp;
}