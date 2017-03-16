#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX_N = 100100;

double p[MAX_N];
double prod[MAX_N];
int A, B, T;

void read_data() {
    cin >> A >> B;
    for (int i = 0; i < A; ++i)
        cin >> p[i];
}

void computeProd() {
    prod[0] = 1;
    for (int i = 1; i <= A; ++i)
        prod[i] = p[i - 1] * prod[i - 1];
}

double enterStrategy() {
    return (1 + B + 1); 
}

double backSpaceStrategy(int spaces) {
    return 
        (1 - prod[A-spaces]) * (2*spaces + (B - A + 1) + (B + 1)) + 
        (prod[A-spaces]) * (2*spaces + (B - A + 1));
}

double solve() {
    computeProd();
    double strokes = enterStrategy();

    for (int spaces = 0; spaces <= A; ++spaces)
        strokes = min(strokes, backSpaceStrategy(spaces));

    return strokes;
}

int main() {
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        read_data();
        double res = solve();
        cout << "Case #" << t << ": " << fixed << setprecision(7) << res << endl;
    }

    return 0;
}

