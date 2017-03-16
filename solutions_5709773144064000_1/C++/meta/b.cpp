#include <iostream>

using namespace std;

int main() {
    int tcc;
    cin >> tcc;
    for (int tc = 1; tc <= tcc; tc++) {
        double c, f, x;
        cin >> c >> f >> x;
        double v = 2.0;
        double tf = 0.0;
        double t = x / v;
        double best = t + 1;
        while (best > t) {
            best = t;
            tf += c / v;
            v += f;
            t = tf + x / v;
        }
        printf("Case #%d: %0.7f\n", tc, best);
    }
    return 0;
}
