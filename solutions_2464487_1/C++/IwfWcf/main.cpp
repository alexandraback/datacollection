//
//  main.cpp
//  A
//
//  Created by IwfWcf on 13-4-27.
//  Copyright (c) 2013年 IwfWcf. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

typedef unsigned long long LL;

const double pi = 3.1415926;

int main(int argc, const char * argv[])
{
    freopen("/Users/IwfWcf/Desktop/A/input.txt", "r", stdin);
    freopen("/Users/IwfWcf/Desktop/A/output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        LL r, t;
        cin >> r >> t;
        LL left = 1, right = 1000000000;
        while (left <= right) {
            LL mid = (left + right) >> 1, sum;
            if (t / (r + r) >= mid) {
                sum = 2 * r * mid;
                sum += (2 * mid - 1) * mid;
            } else
                sum = t + 1;
            if (sum <= t) left = mid + 1;
            else right = mid - 1;
        }
        //cout << t - (2 * r * right + (2 * right - 1) * right) << "\n";
        /*
        bool flag = false;
        LL ans = 0;
        for (LL i = 1; !flag; i += 2) {
            LL nr = r + i, pr = nr - 1;
            LL now = nr * nr - pr * pr;
            if (now <= t) {
                t -= now;
                ans++;
            } else
                flag = true;
        }
        */
        cout << "Case #" << cases << ": " << right << "\n";
    }
    return 0;
}

