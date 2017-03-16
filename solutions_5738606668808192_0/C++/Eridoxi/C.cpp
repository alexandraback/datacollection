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

using namespace std;

typedef unsigned long long ul;
typedef long long ll;

// 2**32 - 1
//#define UP 4294967295
#define UP 429675

// 2**16 - 1
#define MAX 100000000
ul primes[MAX];
ul prime[MAX];
ul psize=0;
int N, J;
int cnt = 0;
ul values[9]; // values in base 2 to 10
ul bpower[9][16]; // precompute base powers SMALL INSTANCE
ul divisors[9];

void print_divisors() {
    cout << values[8];
    for (int i = 0; i < 9; ++i) {
        cout << " " << divisors[i];
    }
    cout << endl;
}

void bpowerf() {
    ul base;
    for (int i = 0; i < 9; ++i) {
        base = 1;
        for (int j = 0; j < 16; ++j) { // SMALL INSTANCE
            bpower[i][j] = base;
            base *= (i+2);
        }
    }
}

bool is_prime() {
    for (unsigned i = 0; i < 9; ++i) {
        ll j = 0;
        const ul val = values[i];
        const double rt = sqrt(val);

        while (prime[j] < rt) {
            if (val % prime[j] == 0) { // cool
                divisors[i] = prime[j];
                j = -1;
                break;
            }
            ++j;
        }


        if (j >= 0) { // prime!
            return true;
        }
    }
    return false;
}


void update_values(ul base2) {
    values[0] = base2;
    unsigned i, j;

    for (i = 1; i < 9; ++i) {
        values[i] = 0;
    }

    j = 0;
    while(base2 > 0) {
        if (base2 & 1) {
            for (i = 1; i < 9; ++i) {
                values[i] += bpower[i][j];
            }
        }
        base2 >>= 1;
        ++j;
    }
}

void solve() {
    ul base2 = (1 << (N-1)) + 1;

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

    for(ul i=MAX; i <= UP; i+=2) {
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
    ul i,j; 
    for(i=0;i<MAX;i++) primes[i] = 1;
    for(i=2;i<=(ul)sqrt(MAX);i++) {
        if (primes[i])  {
            for(j=i;j*i<MAX;j++) primes[i*j] = 0; 
        }
    }
    primes[0] = primes[1] = 0;
    
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

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    //freopen("C-large.in", "r", stdin);
    //freopen("C-large.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> N >> J;
        cout << "Case #" << i + 1 << ":" << endl;
        solve();
    }
    return 0;
}
