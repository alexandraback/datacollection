
#include <iostream>
#include <iomanip>

using namespace std;

double solve() {
    double C, F, X;
    cin >> C >> F >> X;

    double r = 2.0;
    double time_used = 0.0;
    double best = X;
    for (int farms = 0;; farms++) {
        double t = time_used + X / r;
        if (t < best)
            best = t;
        else
            break;

        time_used += C / r;
        r += F;
    }
    return best;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << fixed << setprecision(10) << solve() << endl;
    }
}

