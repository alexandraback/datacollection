#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned int N, T, X, c, zerx;
    int J[201];
    long double y, yprev, ymin, yleft, up, low;
    bool win;
    cin >> T;

    for (unsigned int i = 1; i < T + 1; ++i) {
        cin >> N;
        X = 0;
        zerx = 0;
        for (unsigned int j = 0; j < N; ++j) {
            cin >> c;
            X += c;
            J[j] = c; 
            zerx += (c == 0) ? 1 : 0;
        }
        

        cout << "Case #" << i << ": ";
        for (unsigned int j = 0; j < N; ++j) {
           //if (J[j] == 0) {
           //    y = static_cast<long double>(100) / zerx;
           //    printf("%.6Lf ", y);
           //     continue;
           //}
                
            y = yprev = 0.5;
            up = 1.0;
            low = 0.0;
            while(true) {
                yleft = 1.0 - y;
                win = false;
//A_                cout << "Player " << j << " gets " << y << endl;
                for (unsigned int k = 0; k < N; ++k) {
                    if (j == k) {
                        continue;
                    }
                    ymin = max(static_cast<long double>(0.0), (J[j] - J[k]) / static_cast<long double>(X) + y);
//A_                    cout << "Player " << k << " needs " << ymin << " to beat player " << j << endl;
                    if (ymin <= yleft) {
                        yleft -= ymin;
                    } else {
                        win = true;
                        break;
                    }
                }

//A_                cout << "Low Y Up " << low << " " << y << " " << up << endl;
                if (win) {
                    up = y;
                    y -= (y - low) / 2;
//A_                    cout << "Lowering y" << endl;
                } else {
                    low = y;
                    y += (up - y) / 2;
//A_                    cout << "Upping y" << endl;
                }
//A_                cout << "Low Y Up " << low << " " << y << " " << up << endl;
//A_                cout << "Yprev: " << yprev << endl;
//A_                cout << "Y    : " << y << endl;
                if (fabs(yprev - y) < 0.0000000000001) {
//A_                    cout << "Ending..." << endl;
                    break;
                } else {
                    yprev = y;
//A_                    cout << "Newval: " << y << endl;
                }
            }
            printf("%.6Lf ", 100 * y);
        }
        cout << endl;
    }
}
