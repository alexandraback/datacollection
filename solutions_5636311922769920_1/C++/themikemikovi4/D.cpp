#include <iostream>
#include <vector>


using namespace std;

long long int ipow(long long int n, long long int p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        return ipow(n * n, p / 2);
    }
    return n * ipow(n, p - 1);
}

int main() {
    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; ++test_num) {
        long long int k, c, s;
        cin >> k >> c >> s;
        cout << "Case #" << test_num << ": ";
        if ((k + c - 1) / c > s) {
            cout << "IMPOSSIBLE\n";
        } else {
            long long int ci = 0;
            for (long long int i = 0; i < k; ++i) {
                ci *= k;
                ci += i;
                if ((i + 1) % c == 0) {
                    cout << ci + 1 << ' ';
                    ci = 0;
                }
            }
            if (k % c != 0) {
                cout << ci + 1 << ' ';
            }
            cout << '\n';
        }
    }
    cout << flush;

    return 0;
}
