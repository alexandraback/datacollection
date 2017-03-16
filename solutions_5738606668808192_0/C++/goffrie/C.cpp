#include <iostream>
#include <vector>

using namespace std;

const int N = 16;
const int J = 50;
const int MAXP = 100000000;

int factor[MAXP];
vector<int> primes;

void init() {
    primes.reserve(MAXP / 10);
    for (int i = 2; i < MAXP; ++i) if (!factor[i]) {
        primes.push_back(i);
        for (int j = i*2; j < MAXP; j += i) factor[j] = i;
    }
}

bool test(unsigned n) {
    vector<int> factors;
    factors.reserve(9);
    unsigned long long k, l;
    //cerr << endl << n << ':';
    for (int b = 2; b <= 10; ++b) {
        k = 0;
        l = 1;
        for (int i = 0; i < N; ++i) {
            if (n & (1<<i)) k += l;
            l *= b;
        }
        //cerr << k << ' ';
        if (k < MAXP) {
            if (factor[k]) {
                factors.push_back(factor[k]);
            } else {
                return false;
            }
        } else {
            for (int i = 0; i < primes.size(); ++i) {
                if (primes[i] * primes[i] > k) break;
                if (k % primes[i] == 0) {
                    factors.push_back(primes[i]);
                    goto ok;
                }
            }
            return false;
ok: ;
        }
    }
    cout << k;
    for (int i = 0; i < factors.size(); ++i) {
        cout << ' ' << factors[i];
    }
    cout << endl;
    return true;
}

int main() {
    cout << "Case #1:" << endl;
    init();
    int c = 0;
    for (unsigned i = (1<<(N-1)) + 1; i < (1<<N); i += 2) {
        if (test(i)) ++c;
        if (c == J) break;
    }
}
