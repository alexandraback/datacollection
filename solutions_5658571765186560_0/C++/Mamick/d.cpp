#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
int t, x, r, c;

void printR(int t) {
    cout << "Case #" << t << ": RICHARD" << endl;
}

void printG(int t) {
    cout << "Case #" << t << ": GABRIEL" << endl;
}


int main() {
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> x >> r >> c;
        if (x >= 7 || r * c % x != 0 || (r < x && c < x)) {
            printR(test);
            continue;
        }
        if (r > x && c > x) {
            printG(test);
            continue;
        }
        // At this point, x < 7, r <= 7, c <= 7
        int mins = min(r,c);
        int maxs = max(r,c);
        switch (mins) {
            case 1:
                if (x > 2) {
                    printR(test);
                } else {
                    printG(test);
                }
                break;
            case 2:
                if (x < 4) {
                    printG(test);
                } else {
                    printR(test);
                }
                break;
            case 3: 
                if (x <= 4) {
                    printG(test);
                } else {
                    if (x == 5) {
                        if (maxs == 5) {
                            printR(test);
                        } else {
                            printG(test);
                        }
                    } else {
                        printR(test);
                    }
                }
                break;
            default:
                printG(test);
                break;

        }
    }
}