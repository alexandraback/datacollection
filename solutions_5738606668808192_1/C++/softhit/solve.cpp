//
// Created by mark on 4/8/16.
//
#include "includes.h"
#include <vector>
#include <iterator>
#include <algorithm>

int solve(int num) {
    int n,j;
    cin >> n >> j;
    cout << endl;
    int sols = 0;
    for( int i = 1; i < n /2; ++i) {
        for(int j = 0; j < (n-3-2*i+2); ++j) {
            cout << "1" ;
            for (int x=0;x < j; ++x )
                cout<< "0";
            for (int x=0; x< i; ++x ) {
                cout << "11";
            }
            for (int x=0; x < (n-2-2*i-j);++x) {
                cout << "0" ;
            }
            cout << "1" ;
            cout << " 3 4 5 6 7 8 9 10 11" << endl;
            sols ++;
            if(sols >= 500) {
                return 0;
            }
        }

    }
    for (int i = 2; i< (n-4); ++i ){
        for(int j = i+3; j < n-1; ++j) {
            cout << "1" ;
            for (int x=0;x < i-2; ++x )
                cout<< "0";
            cout << "11";
            for (int x=0; x< j-i-2; ++x ) {
                cout << "0";
            }
            cout << "11";
            for (int x=0; x < (n-j-2);++x) {
                cout << "0" ;
            }
            cout << "1" ;
            cout << " 3 4 5 6 7 8 9 10 11" << endl;
            sols ++;
            if(sols >= 500) {
                return 0;
            }
        }
    }
    return 0;
}