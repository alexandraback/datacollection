/*
 * =====================================================================================
 *
 *       Filename:  B.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12.05.2013 14:29:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrey Timoshpolsky (shpolsky), shpolsky@yandex-team.ru (shpolsky@gmail.com)
 *        Company:  Russia, Yandex
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

void solve() {
    int X, Y;
    cin >> X >> Y;
    string hor = "EW", vert = "SN";
    if (X < 0) {
        hor = "WE";
    }
    if (Y < 0) {
        vert = "NS";
    }
    for (int i = 0; i < abs(X); ++i) {
        if (i == abs(X) - 1) {
            cout << hor[0];
        } else {
            cout << hor;
        }
    }
    for (int i = 0; i < abs(Y); ++i) {
        cout << vert;
    }
}

int main( int argc, char *argv[] ) {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
}

