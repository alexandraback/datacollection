#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <bits/stl_set.h>

using namespace std;
int T;
string s;

int calc() {
}

int main () {

    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> s;
        int state = -1;
        int total = 0;

        for (char c : s) {
            if (c == '-' && state != 1) {
                state = 1;
                total++;
            } else if (c == '+' && state != 0) {
                state = 0;
                total++;
            }
        }

        if (state == 0)
            total--;

        printf("Case #%d: %d\n", t + 1, total);
    }
}