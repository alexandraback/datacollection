
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_P = 1000000;
const int MAX_N = 16;

int main() {

    vector<uint64_t> primes;

    vector<bool> isprime(MAX_P, true);
    for (uint64_t p = 2; p < MAX_P; p ++) {
        if (isprime[p]) {
            primes.push_back(p);
            for (uint64_t q = p*p; q < MAX_P; q += p) {
                isprime[q] = false;
            }
        }
    }

    int T;
    cin >> T;

    for (int t = 0; t < T; t ++) {
        int N, J;
        cin >> N >> J;

        int dup = 1;
        if (N > MAX_N) {
            N /= 2;
            dup = 2;
        }

        cout << "Case #" << (t+1) << ":\n";

        int digits[MAX_P];
        digits[0] = 1;
        digits[N-1] = 1;
        for (int k = 1; k < N-1; k ++) {
            digits[k] = 0;
        }

        while (J > 0) {

            uint64_t divs[9];
            int divs_count = 0;

            for (int b = 2; b <= 10; b ++) {
                uint64_t n = 0;
                for (int k = 0; k < N; k ++) {
                    n = n*b + digits[k];
                }

                for (const auto& p : primes) {
                    if (p*p > n)
                        break;
                    if (n % p == 0) {
                        divs[divs_count++] = p;
                        break;
                    }
                }
                if (divs_count < b-1)
                    break;
            }

            if (divs_count == 9) {
                for (int k = 0; k < dup; k ++) {
                    for (int j = 0; j < N; j ++) {
                        cout << digits[j];
                    }
                }
                for (int k = 0; k < 9; k ++) {
                    cout << ' ' << divs[k];
                }
                cout << '\n';

                J --;
            }

            int l = N-2;
            while (l > 0 && digits[l] == 1) {
                digits[l] = 0;
                l --;
            }
            digits[l] = 1;
        }
    }

}

