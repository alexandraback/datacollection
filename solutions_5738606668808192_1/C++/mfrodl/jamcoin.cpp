#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * Compute a^n
 */
int intPow(int a, int n) {
    return (n == 0) ? 1 : a * intPow(a, n - 1);
}

/*
 * Convert '11' from base 2 through 10 to decimal representations and print
 */
void factors() {
    for (int b = 2; b <= 10; b++) {
        cout << " " << b + 1;
    }
}

/*
 * Generate j jamcoins of length n
 */
void compute(int n, int j) {
    int done = 0;
    for (int i = 0; i < j; i++) {
        cout << "11";
        for (int k = 0; k < (n-4)/2; k++) {
            if (i / intPow(2, k) % 2 == 1) {
                cout << "11";
            }
            else {
                cout << "00";
            }
        }
        cout << "11";
        factors();
        cout << endl;
    }
}

int main() {
    int t;
    int n, j;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> j;
        cout << "Case #" << i + 1 << ":" << endl;
        compute(n, j);
    }

    return 0;
}
