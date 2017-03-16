#include <iostream>
#include <cstdlib>
#include <set>
using namespace std;

typedef unsigned int uint128_t __attribute__((mode(TI)));

long isPrime(uint128_t x) {
    for (long i = 2; i <= 1000; i++) {
        if (x % i == 0) return i;
    }
    return -1;
}

int main() {
    int nc;
    cin >> nc;
    for (int ni=0; ni<nc; ni++) {
        int n, m;
        cin >> n >> m;
        cout << "Case #" << (ni + 1) << ":" << endl;

        int total = 0;
        int buf[n];
        buf[0] = 1;
        buf[n-1] = 1;
        set<long> used;
        while (true) {
            long val = 0;
            for (int i=1; i<n - 1; i++) {
                buf[i] = rand() % 2;
                val = val * 2 + buf[i];
            }
            if (used.count(val) != 0) continue;
            used.insert(val);

            long factors[10];
            bool is = false;
            for (int base = 2; base <= 10; base++) {
                uint128_t sum = 0;
                uint128_t idx = 1;
                for (int i=0; i<n; i++) {
                    sum += buf[i] * idx;
                    idx *= base;
                }

                long factor = isPrime(sum);
                if (factor < 0) {
                    is = true;
                    break;
                }
                factors[base - 1] = factor;
            }
            if (!is) {
                for (int i = n-1; i>=0; i--) {
                    cout << buf[i];
                }
                for (int i = 2; i <= 10; i++) {
                    cout << " " << factors[i - 1];
                }
                cout << endl;
                total ++;
                if (total == m) break;
            }
        }
    }
}
