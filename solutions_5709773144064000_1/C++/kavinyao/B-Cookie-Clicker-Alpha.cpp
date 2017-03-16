#include <iostream>
#include <cmath>

using namespace std;

#define CLICK_SPEED 2.0

double solve(double C, double F, double X) {
    double min_elapsed = X / CLICK_SPEED;
    if (X <= C) return min_elapsed;

    int n = int(ceil(X/C - 2/F - 1));
    double elapsed = 0.0, speed = CLICK_SPEED;
    for (int i = 0;i <= n;++i) {
        double no_buy = X / speed;
        double buy = C / speed + X / (speed + F);

        if (no_buy <= buy) {
            min_elapsed = min(min_elapsed, elapsed+no_buy);
        } else {
            elapsed += C/speed;
            speed += F;
        }

    }

    return min_elapsed;
}

int main() {
    int n;
    cout.precision(7);
    cin >> n;

    for (int i = 0;i < n;++i) {
        double C, F, X;
        cin >> C >> F >> X;
        cout << "Case #" << (i+1) << ": ";
        cout << fixed << solve(C, F, X);
        cout << endl;
    }
}
