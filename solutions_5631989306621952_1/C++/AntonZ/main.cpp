#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include <map>

using namespace std;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int T;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        string str, lw;
        cin >> str;
        lw.resize(2020);
        int ptr_beg = 1010;
        int ptr_end = ptr_beg+1;
        lw[ptr_beg] = str[0];
        for (int i = 1; i < (int)str.length(); i++) {
            char let = str[i];
            if (let >= lw[ptr_beg]) {
                ptr_beg--;
                lw[ptr_beg] = let;
            }
            else {
                lw[ptr_end] = let;
                ptr_end++;
            }
        }

        printf("Case #%d: ", test);
        for (int i = ptr_beg; i < ptr_end; i++) {
            printf("%c", lw[i]);
        }
        cout << endl;
    }

    return 0;
}

