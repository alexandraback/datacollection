//
//  main.cpp
//  15a
//
//  Created by dawn on 15-4-11.
//  Copyright (c) 2015å¹?dawn. All rights reserved.
//


#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t,i = 0;
    cin >> t;
    while (i++ < t) {
        cout << "Case #" << i << ": ";
        int s;
        cin >> s;
        string cc;
        cin >> cc;
        int now = 0, need = 0;
        for (int j = 0; j <= s; ++j) {
            int a = cc[j] - '0';
            now += a;
            if (!a && now < j + 1 && j + 1 - now > need) {
                need = j + 1 - now;
            }
        }
        cout << need << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
