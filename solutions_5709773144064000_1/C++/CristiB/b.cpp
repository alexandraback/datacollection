#include <iostream>

using namespace std;

double timeTo(double val, double rate) {
    return val / rate;
}

double solve(double c, double f, double x) {
    double rate = 2.0;
    double time = 0.0;

    while (true) {
        if (timeTo(c, rate) + timeTo(x, rate + f) < timeTo(x, rate)) {
            time += timeTo(c, rate), 
            rate += f;
        }
        else {
            time += timeTo(x, rate);
            break;
        }
    }

    return time;
}

int main() {
    cout.precision(9);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        double c, f, x;
        cin >> c >> f >> x;
        cout << "Case #" << t << ": " << fixed << solve(c, f, x) << endl;
    }

    return 0;
}
