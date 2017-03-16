#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
using namespace std;

#define LIM 2000
double C[LIM + 1][LIM + 1];

bool inPyr(int x, int y, int lev, int extra = 0) {
    int cy = 0, f = 2 * lev + 1;
    if (!extra) extra = f;
    while (f && extra) {
        if (y == cy) {
            int mx = f / 2 * 2 - (cy % 2);
            if (x <= mx) return true;
        }
        cy++, f--, extra--;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    cout.setf(ios::floatfield, ios::fixed);
    cout.precision(7);
    C[0][0] = 1;
    for (int i = 1; i <= LIM; i++) {
        C[i][0] = C[i - 1][0] / 2;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) / 2;
    }

    double p = 0;
    int Y = 20;
    for (int i = 0; i <= Y; i++) p += C[Y][i];

    for (int test = 1; test <= T; test++) {
        int X, Y, N;
        double p = 0;
        cin >> N >> X >> Y;
        X = abs(X);
        int lev = 0;

        while (N >= 1 + 4 * lev) N -= 1 + 4 * lev, lev++;
        lev--;

        if (inPyr(X, Y, lev)) p = 1;
        else {
            if (inPyr(X, Y, lev + 1) && X) {
                int side = 2 * (lev + 1);
                int extra = N - side;
                if (extra < 0) extra = 0;
                N -= extra * 2;
                if (extra > Y) p = 1;
                else {
                    Y -= extra;
                    p = 1;
                    for (int left = 0; left <= Y; left++)
                        p -= C[N][left];
                }
            }
        }

        cout << "Case #" << test << ": " << p << endl;
    }

    return 0;
}
