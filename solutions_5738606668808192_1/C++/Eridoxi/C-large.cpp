#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>

// STL
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>

#include <gmpxx.h>

using namespace std;

typedef unsigned long long ul;
typedef long long ll;

// 2**32 - 1
//#define UP 4294967295
#define UP 429675

// 2**16 - 1
#define MAX 100000000
bool primes[MAX];
mpz_class prime[MAX];
unsigned psize=0;
int N, J;
int cnt = 0;
mpz_class values[9]; // values in base 2 to 10
mpz_class bpower[9][32]; // precompute base powers
mpz_class divisors[9];

const mpz_class gmp2(2);
const mpz_class gmp0(0);

void print_divisors() {
    cout << values[8];
    for (int i = 0; i < 9; ++i) {
        cout << " " << divisors[i];
    }
    cout << endl;
}

void bpowerf() {
    mpz_class base;
    for (int i = 0; i < 9; ++i) {
        base = 1;
        for (int j = 0; j < 32; ++j) {
            bpower[i][j] = base;
            base *= (i+2);
        }
    }
}

bool is_prime() {
    for (unsigned i = 0; i < 9; ++i) {
        ll j = 0;
        const mpz_class val = values[i];
        const mpz_class rt = sqrt(val);

        while (prime[j] <= rt && j < psize) {
            if (val % prime[j] == 0) { // cool
                divisors[i] = prime[j];
                j = -1;
                break;
            }
            ++j;
        }


        if (j >= 0) { // non divisible by tested primes
            return true;
        }
    }
    return false;
}


void update_values(mpz_class base2) {
    values[0] = base2;
    unsigned i, j;

    for (i = 1; i < 9; ++i) {
        values[i] = 0;
    }

    j = 0;
    while(base2 > 0) {
        if (base2 % gmp2 > gmp0) {
            for (i = 1; i < 9; ++i) {
                values[i] += bpower[i][j];
            }
        }
        base2 >>= 1;
        ++j;
    }
}

void solve() {
    mpz_class base2(2);
    // base2 = (1 << (N-1)) + 1;
    mpz_ui_pow_ui (base2.get_mpz_t(), 2, N-1);
    base2 += 1;

    update_values(base2);
    
    while(cnt < J) {
        if (!is_prime()) {
            print_divisors();
            ++cnt;
        }

        update_values(base2 += 2);
    }
}

void sieve_up() {
    ul pps = psize;

    for(mpz_class i=MAX; i <= UP; i+=2) {
        bool prm = true;
        for (ul j = 0; j < pps; ++j) {
            if ((i % prime[j]) == 0) { // divisible
                prm = false;
                break;
            }
        }

        if (prm) {
            prime[psize++] = i;
        }
        cout << psize << endl;
    }
}

void sieve() { 
    unsigned i,j; 
    for(i=0;i<MAX;i++) primes[i] = true;
    for(i=2;i<=(ul)sqrt(MAX);i++) {
        if (primes[i])  {
            for(j=i;j*i<MAX;j++) primes[i*j] = false; 
        }
    }
    primes[0] = primes[1] = false;
    
    for(i=2;i<=MAX;i++) {
        if (primes[i]) {
            prime[psize++]=i; 
        }
    }

    sieve_up();
} 



int main() {
    int numcase;
    sieve();
    bpowerf();

    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C-small-GMP.out", "w", stdout);
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> N >> J;
        cout << "Case #" << i + 1 << ":" << endl;
        solve();
    }
    return 0;
}
