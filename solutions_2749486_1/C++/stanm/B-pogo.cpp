#include <iostream>
#include <cmath>

using namespace std;

int T;
const int MAXK = 10000;

int findK(int kspo) {
    int l = 0, r = MAXK;
    int m = (r + l) / 2;
    while (m > l) {
        if (m * (m + 1) / 2 > kspo) {
            r = m;
        } else if (m * (m + 1) / 2 < kspo) {
            l = m;
        } else if (m * (m + 1) / 2 == kspo) {
            break;
        }
        m = (r + l) / 2;
    }
    if ((m + 1) * (m + 2) / 2 - kspo < kspo - (m + 1) * m / 2) {
        ++m;
    }
    return m;
}

int main() {
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int X, Y;
        const int N = 1048576;
        char answ[N];
        for (int i = 0; i < N; ++i) {
            answ[i] = 0;
        }
        cin >> X >> Y;
        int k = findK(abs(X) + abs(Y));

        int kx = findK(abs(X));
        if (kx * (kx + 1) / 2 < abs(X)) ++kx;
        int miss = kx * (kx + 1) / 2 - abs(X);
//        cout << "X=" << X << " kx=" << kx << " miss=" << miss <<'\n';
        for (int i = 1; i <= kx; ++i) {
            if (i != miss) {
                answ[i-1] = X > 0? 'E': 'W';
                X = X > 0? X - i: X + i;
            } else {
                answ[i-1] = Y > 0? 'N': 'S';
                Y = Y > 0? Y - i: Y + i;
            }
        }

        while (abs(Y) * 2 > (kx + 1)) {
            if (Y > 0) {
                answ[kx] = 'N';
                Y -= ++kx;
            } else {
                answ[kx] = 'S';
                Y += ++kx;
            }
        }

        for (int i = kx + 1; Y != 0; ++i) {
            if (Y > 0) {
                answ[(i++)-1] = 'S';
                answ[i-1] = 'N';
                --Y;
            } else {
                answ[(i++)-1] = 'N';
                answ[i-1] = 'S';
                ++Y;
            }
        }

//        cout << "X=" << X << " Y=" << Y << " k=" << k << '\n';
        cout << "Case #" << test << ": " << answ << '\n';
    }
}