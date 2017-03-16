#include <iostream>
using namespace std;

void printOutput(int idx, string text) {
    cout << "Case #" << idx << ": " << text << endl;
}

void handleCase(int idx) {
    long double c, f, x, result_tmp;
    cin >> c >> f >> x;
    int count = 0;
    long double result = x / 2.0;
    long double cost = 0;
    long double rate = 2;
    while (true) {
        cost += c / rate;
        rate += f;
        result_tmp = cost + x / rate;
        if (result_tmp >= result) {
            printf("Case #%d: %.7Lf\n", idx, result);
            break;
        } else {
            result = result_tmp;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        handleCase(i);
    }
}
