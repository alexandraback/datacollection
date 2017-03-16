#include <iostream>
#include <algorithm>
#include <cmath>
#include "memory.h"


using namespace std;


int n;
double p[10101][10100];


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, x, y;
        cin >> n >> x >> y;
        cout << "Case #" << t + 1 << ": ";
        if (n == 1) {
            if (x == 0 && y == 0)
                cout << "1.0\n";
            else
                cout << "0.0\n";
            continue;
        }
        int step = 2, side = 1;
        int sum = 1;
        while (1) {
            int nsum = side * 2 + 3 + sum;
            if (nsum > n)
                break;
            sum = nsum;
            ++step;
            side += 2;
        }
        int dstep, dk = y + 1;
        if (x <= 0)
            dstep = (y - x) / 2 + 1;
        else
            dstep = (x + y) / 2 + 1;
        if (dstep > step) {
            cout << "0.0\n";
            continue;
        }
        if (dstep < step) {
            cout << "1.0\n";
            continue;
        }
        n -= sum;
        memset(p, 0, sizeof(p));
        p[0][0] = 1.0;
        for (int i = 0; i <= side + 1; ++i) {
            for (int j = 0; j <= side + 1; ++j) {
                if (i == 0 && j == 0)
                    continue;
                if (i > 0) {
                    if (j < side + 1)
                        p[i][j] += 0.5 * p[i - 1][j];
                    else
                        p[i][j] += p[i - 1][j];
                }
                if (j > 0) {
                    if (i < side + 1)
                        p[i][j] += 0.5 * p[i][j - 1];
                    else
                        p[i][j] += p[i][j - 1];
                }
            }
        }
        double res = 0;
        for (int i = dk; i <= side + 1; ++i)
            if (n - i >= 0)
                res += p[i][n - i];
        printf("%.9lf\n", res);
    }
    
    
    return 0;
}