//
//  c.cpp
//  
//
//  Created by Xiang Fei Ding on 4/9/16.
//
//

#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::bitset;
using std::vector;

const unsigned int sieve_size = 65536;
const unsigned long long masks[33] = {
    0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80,
    0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000,
    0x10000, 0x20000, 0x40000, 0x80000, 0x100000, 0x200000, 0x400000, 0x800000,
    0x1000000, 0x2000000, 0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000,
    0x100000000
};
vector<unsigned int> primes;

void generate_primes() {
    bitset<sieve_size + 1> sieve;
    sieve.set(0); sieve.set(1);
    for (unsigned int i = 2; i <= sieve_size; ++i)
        if (!sieve[i])
            for (unsigned int j = i * 2; j <= sieve_size; j += i)
                sieve.set(j);
    for (unsigned int i = 2; i <= sieve_size; ++i)
        if (!sieve[i])
            primes.push_back(i);
}

long long int find_factor(unsigned long long int n) {
    unsigned long long int limit = sqrt(n);
    for (vector<unsigned int>::const_iterator it = primes.begin(), end = primes.end(); *it <= limit && it != end; ++it)
        if (n % *it)
            continue;
        else
            return *it;
    return -1;
}

long long int factors[9];

int main() {
    generate_primes();
    int n, j, c = 0;
    cin>>n;
    cin>>n>>j;
    cout<<"Case #1:"<<endl;
    for (unsigned long long int i = masks[n - 1] + 1; i < masks[n] && c < j; i += 2) {
        factors[0] = find_factor(i);
        if (factors[0] < 0)
            continue;
        bool success = true;
        for (int b = 3; b < 11; ++b) {
            unsigned long long int s = 0, e = 1;
            for (int m = 0; i >= masks[m]; ++m, e *= b)
                if (i & masks[m])
                    s += e;
            
            factors[b - 2] = find_factor(s);
            if (factors[b - 2] < 0) {
                success = false;
                break;
            }
        }
        if (success) {
            ++c;
            cout << '1';
            for (int k = n - 2; k; --k)
                if (i & masks[k])
                    cout << '1';
                else
                    cout << '0';
            cout << '1';
            for (int k = 0; k < 9; ++k)
                cout << ' ' << factors[k];
            cout << endl;
        }
    }
    return 0;
}