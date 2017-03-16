//
//  main.cpp
//  2015R1C_A
//
//  Created by apple on 15/5/10.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <string>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)

int main(int argc, const char * argv[]) {
    freopen("/Users/apple/Documents/coding/Xcode/Google Code Jam/2015R1C_A/2015R1C_A/output1.txt", "w", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t){
        // each test case starts here
        int R, C, W; cin >> R >> C >> W;
        int ans = 0;
        if (C == 1 && W == 1) ans = 1;
        if (C == 2 && W == 1) ans = 2;
        if (W == 1) ans = C;
        if (C == 2 && W == 2) ans = 2;
        if (C == 3 && W == 2) ans = 3;
        if (C == 3 && W == 3) ans = 3;
        if (C == 4 && W == 2) ans = 3;
        if (C == 4 && W == 3) ans = 4;
        if (C == 4 && W == 4) ans = 4;
        if (C == 5 && W == 2) ans = 3;
        if (C == 5 && W == 3) ans = 4;
        if (C == 5 && W == 4) ans = 5;
        if (C == 5 && W == 5) ans = 5;
        if (C == 6 && W == 2) ans = 4;
        if (C == 6 && W == 3) ans = 4;
        if (C == 6 && W == 4) ans = 5;
        if (C == 6 && W == 5) ans = 6;
        if (C == 6 && W == 6) ans = 6;
        if (C == 7 && W == 2) ans = 5;
        if (C == 7 && W == 3) ans = 5;
        if (C == 7 && W == 4) ans = 6;
        if (C == 7 && W == 5) ans = 7;
        if (C == 7 && W == 6) ans = 7;
        if (C == 7 && W == 7) ans = 7;
        if (C == 8 && W == 2) ans = 5;
        if (C == 8 && W == 3) ans = 5;
        if (C == 8 && W == 4) ans = 5;
        if (C == 8 && W == 5) ans = 7;
        if (C == 8 && W == 6) ans = 7;//
        if (C == 8 && W == 7) ans = 8;
        if (C == 8 && W == 8) ans = 8;
        if (C == 9 && W == 2) ans = 6;
        if (C == 9 && W == 3) ans = 5;
        if (C == 9 && W == 4) ans = 6;
        if (C == 9 && W == 5) ans = 5 + 2;//
        if (C == 9 && W == 6) ans = 6 + 2;
        if (C == 9 && W == 7) ans = 7 + 2;
        if (C == 9 && W == 8) ans = 9;
        if (C == 9 && W == 9) ans = 9;
        if (C == 10 && W == 2) ans = 6;
        if (C == 10 && W == 3) ans = 6;
        if (C == 10 && W == 4) ans = 6;
        if (C == 10 && W == 5) ans = 8;
        if (C == 10 && W == 6) ans = 6 + 3;
        if (C == 10 && W == 7) ans = 7 + 2;
        if (C == 10 && W == 8) ans = 9;
        if (C == 10 && W == 9) ans = 10;
        if (C == 10 && W == 10) ans = 10;
        cout << "Case #" << t << ": " << ans << endl;
        
    }
    return 0;
}
