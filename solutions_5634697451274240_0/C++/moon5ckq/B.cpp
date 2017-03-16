/*
 * B.cpp
 * Copyright (C) 2016 mlckq <moon5ckq@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void filp(string& p, int c) {
    string n(c, ' ');
    for (int i = 0; i <= c; ++i)
        if (p[i] == '+')
            n[i] = '-';
        else
            n[i] = '+';
    for (int i = 0; i <= c; ++i)
        p[c - i] = n[i];
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);

        string p;
        cin >> p;
        for (int c = 0; ; ++c) {
            int last = p.length() - 1;
            while (last >=0 && p[last] == '+')
                last --;
            if (last == -1) {
                printf("%d\n", c);
                break;
            }
            if (p[0] == '+') {
                int front = 1;
                while (front < p.length() && p[front] == '+')
                    front ++;
                filp(p, front - 1);
                continue;
            } else
                filp(p, last);
        }
    }

    return 0;
}
