#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdio.h>
#include <set>
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int O[4] = {0}, X[4] = {0}, xd1 = 0, od1 = 0, xd2 = 0, od2 = 0;
        string ans = "";
        bool point = false, ansFound = false;
        for (int i = 0; i < 4; i++) {
            string s;
            cin >> s;
            int o = 0, x = 0;
            if (!ansFound) {
                for (int j = 0; j < 4; j++) {
                    if (s[j] == 'O') {
                        o++, O[j]++;
                        if (i == j) od1++;
                        if (i == 3 - j) od2++;
                    } else if (s[j] == 'X') {
                        x++, X[j]++;
                        if (i == j) xd1++;
                        if (i == 3 - j) xd2++;
                    } else if (s[j] == 'T') {
                        o++, x++, O[j]++, X[j]++;
                        if (i == j) od1++, xd1++;
                        if (i == 3 - j) od2++, xd2++;
                    } else if (s[j] == '.') {
                        point = true;
                    }
                }
                if (o == 4) {
                    ansFound = true;
                    ans = "O won";
                }
                if (x == 4) {
                    ansFound = true;
                    ans = "X won";
                }
            }
        }
        if (!ansFound) {
            if (xd1 == 4 || xd2 == 4) {
                ans = "X won";
                ansFound = true;
            } else if (od1 == 4 || od2 == 4) {
                ans = "O won";
                ansFound = true;
            }
            if (!ansFound) {
                for (int j = 0; j < 4; j++) {
                    if (O[j] == 4) {
                        ans = "O won";
                        ansFound = true;
                        break;
                    }
                    if (X[j] == 4) {
                        ans = "X won";
                        ansFound = true;
                        break;
                    }
                }
            }
        }
        if (!ansFound) {
            ans = point ? "Game has not completed" : "Draw";
        }
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}
