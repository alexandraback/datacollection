//
//  c.cpp
//
//
//  Created by Nikifor Zhao on 15/4/11.
//
//

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("output.txt");

int s[4][4] = {
    {1, 1, 1, 1},
    {1, -1, 1, -1},
    {1, -1, -1, 1},
    {1, 1, -1, -1}
};
int f[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};
int main() {
    int T, l, x;
    char tc[20000];
    int a[20000];
    string ans;
    fin >> T;
    for (int ti = 1; ti <= T; ti ++) {
        char *c = new char[20000];
        int i;
        int sign = 1, cur = 0;
        fin >> l >> x >> tc;
        if (l * x <= 2) {
            fout << "Case #" << ti << ": " << "NO" << endl;
            continue;
        }
        for (i = 0; i < x; i ++) strcat(c, tc);
        l *= x;
        for (i = 0; i < l; i ++) a[i] = c[i] - 'h';
        sign = 1; cur = 0;
        for (i = 0; i < l; i ++) {
            sign = s[cur][a[i]] * sign;
            cur = f[cur][a[i]];
            if (sign == 1 && cur == 1) break;
        }
        if (i == l + 1) {
            fout << "Case #" << ti << ": " << "NO" << endl;
            continue;
        }
//        cout << "1 " << i << endl;
        i ++;
        sign = 1; cur = 0;
        for (; i < l; i ++) {
            sign = s[cur][a[i]] * sign;
            cur = f[cur][a[i]];
            if (sign == 1 && cur == 2) break;
        }
        if (i == l + 1) {
            fout << "Case #" << ti << ": " << "NO" << endl;
            continue;
        }
//        cout << "2 " << i << endl;
        i ++;
        sign = 1; cur = 0;
        for (; i < l; i ++) {
            sign = s[cur][a[i]] * sign;
            cur = f[cur][a[i]];
        }
        if (cur != 3 || sign != 1) {
            fout << "Case #" << ti << ": " << "NO" << endl;
            continue;
        }
//        cout << "3 " << i << endl;
        i ++;
        fout << "Case #" << ti << ": " << "YES" << endl;
    }
}
