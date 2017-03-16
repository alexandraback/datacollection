#include <cmath>
#include <fstream>
#include <iostream>
#define ull unsigned long long
using namespace std;
fstream fsi("in.txt", fstream::in);
fstream fso("out.txt", fstream::out);

const ull mx = 10;
ull divisors[mx];

void fillDivisors(ull n) {
    ull i;
    for (i = 2; i <= mx; i++) divisors[i] = ((ull)pow(i, (n/2)))+1;
}

void printBinary(ull a) {
    if (a == 0) return;
    printBinary(a>>1);
    fso << (a&1);
}

void printDivisors() {
    ull i;
    for (i = 2; i <= mx; i++) fso << ' ' << divisors[i];
}

void solve() {
    ull aux, i, j, n;
    n = 32;
    j = 500;
    fillDivisors(n);
    fso << "Case #1:" << '\n';
    aux = (divisors[2]/2)+1;
    for (i = 0; i < j; i++) {
        printBinary(divisors[2]*(aux+i+i));
        printDivisors();
        fso << '\n';
    }
}

int main() {
    solve();
    return 0;
}
