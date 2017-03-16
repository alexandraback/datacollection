#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    cout << setprecision(12);
    for (int t = 1; t <= T; ++t) {
        double c, f, x;
        cin >> c >> f >> x;
        double cur = 0, v = 2;
        double ct = 0;
        while (true) {
            if (cur >= x) {
                break;
            }
            double toX = (x - cur) / v;
            double toXwithC = 0;
            double toC = 0;
            if (cur < c) {
                toC = (c - cur) / v;
                toXwithC = toC + x / (v + f);
            } else {
                toC = 0;
                toXwithC = (x - cur + c) / (v + f);
            }
            if (toX < toXwithC) {
                ct += toX;
                cur = x;
            } else {
                ct += toC;
                cur += toC * v;
                cur -= c;
                v += f;
            }
        }
        cout << "Case #" << t << ": " << ct << "\n";
    }
}
