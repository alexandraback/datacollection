//GTK是我男神！！男神嘤嘤嘤TT
//  main.cpp
//  15d
//
//  Created by dawn on 15-4-12.
//  Copyright (c) 2015年 dawn. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    int t,i = 0;
    cin >> t;
    while (i++ < t) {
        cout << "Case #" << i << ": ";
        int x,r,c;
        bool res = true;
        cin >> x >> r >> c;
        if (x > r && x > c) res = false;
        else if (x > r * c) res = false;
        else if (r * c % x) res = false;
        else if ((x+1)/2 > r || (x+1)/2 > c) res = false;
        else if (x >= 7) res = false;
        else if (x < 4) res = true;
        else if (x == 4) {
            if (r < 3 || c < 3) res = false;
        }
        else if (x == 5) {
            if ((r==3 && c==5)||(r==5 && c==3)) res = false;
        }
        else if (x == 6) {
            if (r < 4 || c < 4) res = false;
        }
        if (res)
            cout << "GABRIEL" << endl;
        else
            cout << "RICHARD" << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
