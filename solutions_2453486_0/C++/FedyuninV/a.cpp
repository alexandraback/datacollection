#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <utility>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        char c;
        vector <int> x, o;
        int dots = 0;
        x.clear(); x.resize(10, 0);
        o.clear(); o.resize(10, 0);
        forn(i, 4) {
            forn(j, 4) {
                cin >> c;
                if (c == 'T'  ||  c == 'X') {
                    x[i]++;
                    x[4 + j]++;
                    if (i == j) {
                        x[8]++;
                    }
                    if (i + j == 3) {
                        x[9]++;
                    }
                }
                if (c == 'T'  ||  c == 'O') {
                    o[i]++;
                    o[4 + j]++;
                    if (i == j) {
                        o[8]++;
                    }
                    if (i + j == 3) {
                        o[9]++;
                    }
                }
                if (c == '.') {
                    dots++;
                }
            }
        }
        bool finished = false;
        cout << "Case #" << test << ": ";
        forn(i, 10) {
            if (x[i] == 4) {
                finished = true;
                cout << "X won\n";
                break;
            }
            if (o[i] == 4) {
                finished = true;
                cout << "O won\n";
                break;
            }
        }
        if (!finished) {
            if (dots) {
                cout << "Game has not completed\n";
            } else {
                cout << "Draw\n";
            }
        }
    }
	return 0;
}
