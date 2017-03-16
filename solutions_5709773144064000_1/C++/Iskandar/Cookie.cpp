#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int T;

    cin >> T;

    for (int i = 1; i <= T; i++) {
        double C, F, X, rate = 2, min_time = 1000000, current_time = 0, overhead = 0;

        cin >> C;
        cin >> F;
        cin >> X;

        for (int j = 0; j < (int) (ceil(X/C)) + 1; j++) { // bruteforce
            /** Without buying time */
            current_time = overhead + (X/rate);

            if (current_time < min_time) min_time = current_time;
            /** Buying */
            overhead += (C/rate);
            rate += F;
        }

        cout << "Case #" << i << ": ";

        cout.precision(8);
        cout << fixed << min_time << endl;
    }

    return 0;
}
/** Created by freedomofkeima */
