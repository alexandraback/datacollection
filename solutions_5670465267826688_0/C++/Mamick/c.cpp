#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <queue>
#include <cstdlib>

using namespace std;

long long t, l, x;
string s;

long long multiply(long long a, long long b) {
    long long neg = a * b < 0 ? -1 : 1;
    a = abs(a);
    b = abs(b);
    switch (a) {
        case 1: return neg * b;
        case 2:
            switch (b) {
                case 1: return neg * 2;
                case 2: return neg * -1;
                case 3: return neg * 4;
                case 4: return neg * -3;
                default: throw 5;
            }
        case 3:
            switch (b) {
                case 1: return neg * 3;
                case 2: return neg * -4;
                case 3: return neg * -1;
                case 4: return neg * 2;
                default: throw 4;
            }
        case 4:
            switch (b) {
                case 1: return neg * 4;
                case 2: return neg * 3;
                case 3: return neg * -2;
                case 4: return neg * -1;
                default: throw 3;
            }
        default: throw 2;
    }
}

long long convert(char c) {
    switch(c) {
        case 'i':
            return 2;
        case 'j':
            return 3;
        case 'k':
            return 4;
        default: cout << c << endl;
            throw 1;
    }
}

bool encountered[10005][15];

int main() {
    cin >> t;
    for (long long test = 1; test <= t; test++) {
        cin >> l >> x >> s;
        memset(encountered, 0, sizeof(encountered));
        long long curx = 0, curval = 1, numiterations = 1;
        bool failed = false;
        while (true) {
            if (curx >= l) {
                if (numiterations + 1 > x) {
                    failed = true;
                    break;
                }
                numiterations++;
                curx = 0;
            }
            if (encountered[curx][curval+5]) {
                failed = true;
                break;
            }
            encountered[curx][curval+5] = true;
            curval = multiply(curval, convert(s[curx]));
            // cout << s[curx];
            curx++;
            if (curval == 2) {
                curval = 1;
                break;
            }
        }
                memset(encountered, 0, sizeof(encountered));
                    // cout << endl;

        if (!failed) {
        while (true) {
            if (curx >= l) {
                if (numiterations + 1 > x) {
                    failed = true;
                    break;
                }
                numiterations++;
                curx = 0;
            }
            if (encountered[curx][curval+5]) {
                failed = true;
                break;
            }
            encountered[curx][curval+5] = true;
            curval = multiply(curval, convert(s[curx]));
            // cout << s[curx];
            curx++;
            if (curval == 3) {
                curval = 1;
                break;
            }
        }
        }
                memset(encountered, 0, sizeof(encountered));
                    // cout << endl;

        if (!failed) {
        while (true) {
            if (curx >= l) {
                // cout << endl << curx << " " << l << endl;
                numiterations++;
                break;
            }
            // cout << endl << curx << " " << curval << endl;
            if (encountered[curx][curval+5]) {
                // cout << endl << encountered[curx][curval] << endl;
                failed = true;
                break;
            }
            encountered[curx][curval+5] = true;
            curval = multiply(curval, convert(s[curx]));
            // cout << s[curx];
            curx++;
        }
        }
                    // cout << endl;
        if (!failed) {
            // cout << curval << endl;
            long long calcs[61];
            calcs[0] = 1; 
            for (long long i = 0; i < l; i++) {
                calcs[0] = multiply(calcs[0], convert(s[i]));
            }
            long long cur = 1;
            for (long long i = 1; i <= 60; i++) {
                calcs[i] = multiply(calcs[i-1], calcs[i-1]);
                cur *= 2;
            }
            long long interationsLeft = x - numiterations + 1;
            for (int i = 60; i >= 0; i--) {
                if (cur <= interationsLeft) {
                    interationsLeft -= cur;
                    curval = multiply(curval, calcs[i]);
                }
                cur /= 2;
            }
            if (curval != 4) {
                failed = true;
            }
        }
        cout << "Case #" << test << ": " << (failed ? "NO" : "YES") << endl;
    }
}