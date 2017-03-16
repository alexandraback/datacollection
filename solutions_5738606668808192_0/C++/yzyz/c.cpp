#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,j;
long long d[11];

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> n >> j;

        // assume n is even and sufficiently large
        n /= 2;

        for (int i = 2; i <= 10; i++) {
            d[i] = 1;
            for (int k = 0; k < n; k++)
                d[i] *= i;
            d[i]++;
        }

        cout << "Case #" << TC << ":\n";

        for (int i = 0; i < j; i++) {
            int x = i;
            cout << 1;
            for (int k = 0; k < n - 2; k++) {
                cout << x % 2;
                x /= 2;
            }
            cout << 1;

            x = i;
            cout << 1;
            for (int k = 0; k < n - 2; k++) {
                cout << x % 2;
                x /= 2;
            }
            cout << 1;

            for (int k = 2; k <= 10; k++) {
                cout << ' ' << d[k];
            }
            cout << '\n';
        }
    }
}
