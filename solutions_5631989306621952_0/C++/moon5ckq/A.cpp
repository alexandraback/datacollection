/*
 * A.cpp
 * Copyright (C) 2016 mlckq <moon5ckq@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);

        string s, r;
        cin >> s;
        r = s[0];
        for (int j = 1; j < s.length(); ++j) {
            if ( r + s[j] > s[j] + r)
                r = r + s[j];
            else
                r = s[j] + r;
        }
        cout << r << endl;
    }
    return 0;
}

