using namespace std;

#include <iostream>
#include <assert.h>

typedef unsigned int uint;
typedef unsigned long ulong;

#define N 100
int some_primes[N];

void init_some_primes() {
    some_primes[0] = 2;
    int next = 3;
    for (int i=1; i<N; i++) {
        int j=0;
        while (some_primes[j]*some_primes[j] <= next) {
            if (next % some_primes[j]) {
                j++;
            } else {
                j = 0;
                next += 2;
            }
        }
        some_primes[i] = next;
        //cout << "Found prime " << next << endl;
        next += 2;
    }
}

bool is_divisor(uint to_test, int prime, int base) {
    int v = 0;
    int f = 1;
    while (to_test) {
        if (to_test&1)
            v = (v+f) % prime;
        to_test >>= 1;
        f = (f*base) % prime;
    }
    return v == 0;
}

bool is_jamcoin(uint to_test) {
    int divisors[11] = {0,0,0,0,0,0,0,0,0,0,0};
    for (int base=2; base<=10; base++) {
        for (int j=0; j<N && some_primes[j]<to_test; j++) {
            if (is_divisor(to_test, some_primes[j], base)) {
                divisors[base] = some_primes[j];
                break;
            }
        }
        if (!divisors[base])
            return false;
    }
    for (int i=31; i>=0; i--) {
        if ((uint(1) << i) > to_test)
            continue;
        cout << ((to_test >> i) & 1);
    }
    for (int base=2; base<=10; base++)
        cout << " " << divisors[base];
    cout << endl;
    return true;
}

int main() {
    init_some_primes();
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        int n, j;
        cin >> n >> j;
        cout << "Case #" << i << ":" << endl;
        uint next = 1 | (1 << (n-1));
        for (int i=0; i<j; i++) {
            while (!is_jamcoin(next))
                next += 2;
            next += 2;
        }
    }
}
