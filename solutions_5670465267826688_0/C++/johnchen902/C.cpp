#include <cstdio>
#include <cstdlib>
using namespace std;

struct Quaternions {
    signed char c;
    Quaternions(signed char cc) : c(cc) {}
};
Quaternions multiply(signed char lhs, signed char rhs) {
    if(lhs == '1') return rhs;
    if(rhs == '1') return lhs;
    if(lhs == rhs) return -'1';

    switch(lhs) {
    case 'i':
        switch(rhs) {
        case 'j': return  'k';
        case 'k': return -'j';
        }
    case 'j':
        switch(rhs) {
        case 'i': return -'k';
        case 'k': return  'i';
        }
    case 'k':
        switch(rhs) {
        case 'i': return  'j';
        case 'j': return -'i';
        }
    }
    __builtin_unreachable();
}
Quaternions operator * (Quaternions lhs, Quaternions rhs) {
    Quaternions q = multiply(abs(lhs.c), abs(rhs.c));
    return (lhs.c > 0) == (rhs.c > 0) ? q : -q.c;
}

char s[10001];

bool solve(int l, long long x) {
    if(x >= 12) {
        // For all S, SSSS = 1.
        // For all x solution (x >= 12), at least one of the three substrings contains SSSS,
        // which can be removed to obtain a (x - 4) solution.
        // For all x solution, we can append the last substring by SSSS to obtain a (x + 4) solution.
        x = 8 + x % 4;
    }
    // Find i
    int i = 0;
    for(Quaternions q = '1'; i < l * x && q.c != 'i'; i++)
        q = q * s[i % l];
    if(i == l * x)
        return false;

    // Find j
    for(Quaternions q = '1'; i < l * x && q.c != 'j'; i++)
        q = q * s[i % l];
    if(i == l * x)
        return false;

    // Check if the remained is k
    Quaternions q = '1';
    for(; i < l * x; i++)
        q = q * s[i % l];
    return q.c == 'k';
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int l;
        long long x;
        scanf("%d %lld %s", &l, &x, s);
        printf("Case #%d: %s\n", i, solve(l, x) ? "YES" : "NO");
    }
}
