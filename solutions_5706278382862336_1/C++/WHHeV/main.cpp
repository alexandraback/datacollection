//
//  main.cpp
//  r13.a
//
//  Created by Zhu Haifan on 14-5-11.
//  Copyright (c) 2014年 Zhu Haifan. All rights reserved.
//

#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <map>
#include <unordered_map>

using namespace std;
long long gcd(long long a, long long b) {
    return (b > 0) ? gcd(b, a % b) : a;
}

int main() {
    freopen("/Users/whshev/Dropbox/Programs/GCJ2014/Data/R13/A-large.in", "r", stdin);
    freopen("/Users/whshev/Dropbox/Programs/GCJ2014/Data/R13/A-large.out", "w", stdout);
    int T, prob=1;
    for (cin >> T; T--;) {
        long long p, q;
        scanf("%lld/%lld", &p, &q);
//        cout << p << '/' << q << endl;
        long long c = gcd(p, q);
        p /= c;
        q /= c;
        bool flag = false;
        if ((q & (q - 1)) != 0) {
            cout << "Case #" << prob++ << ": " << "impossible";
            cout << endl;
            continue;
        }
        for (int i = 1; i <= 40; ++i) {
            if ((p << 1) >= q) {
                cout << "Case #" << prob++ << ": " << i << endl;
                flag = true;
                break;
            }
            p <<= 1;
        }
        if (flag) continue;
        cout << "Case #" << prob++ << ": " << "impossible";
        
        
        cout << endl;
    }
    return 0;
}
