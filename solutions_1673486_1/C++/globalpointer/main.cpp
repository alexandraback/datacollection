#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>

#include <cstdlib>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <bitset>

#include <sstream>
#include <string>
#include <utility>
#include <limits>

#include <gmp.h>
#include <gmpxx.h>
using namespace std;

#define sz(x) ((int)((x).size()))
#define len(x) ((int)((x).length()))
typedef long long ll;
typedef double real;
typedef mpz_class bigint;

const real eps = 1e-9;

string itos(int i) {
    string s; bool neg = false;
    if (i < 0) {
        neg = true;
        i = -i;
    }
    while (i) {
        s += '0'+(i%10);
        i /= 10;
    }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    return s;
}

string itos_bx(int i, int b) {
    string s; bool neg = false;
    if (i < 0) {
        neg = true;
        i = -i;
    }
    while (i) {
        s += "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i%b];
        i /= b;
    }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    return s;
}

int stoi(string s) {
    if (len(s) < 1) return 0;
    int num = 0, idx = 0; bool neg = false;
    if (s[0] == '-') {
        neg = true;
        idx++;
    }
    while (idx < len(s)) {
        num = num*10 + (s[idx]-'0');
        idx++;
    }
    return neg ? -num : num;
}

bool isPalin(string s) {
    int n = (int)s.size();
    for (int i = 0; i < n/2; i++)
        if (s[i] != s[n-i-1])
            return false;
    return true;
}

template<typename T>
T gcd(T a, T b) {
    if (a < T(0)) return gcd(-a, b);
    if (b < T(0)) return gcd(a, -b);
    if (!b) return a;
    return gcd(b, a%b);
}

template<typename T>
bool isPrime(T a) {
    if (a < T(0)) a = -a;
    T two = T(2), i = two;
    if (!(a % i)) return false;
    for (i++; i*i <= a; i += two)
        if (!(a % i))
            return false;
    return true;
}

template<typename T>
int numFactors(T a) {
    if (a < T(0)) a = -a;
    int count = 0;
    T i = T(1);
    for (; i*i < a; i++)
        if (!(a % i))
            count += 2;
    if (i*i == a) count++;
    return count;
}

template<typename T>
vector<T> getFactors(T a) {
    vector<T> factors;
    if (a < T(0)) a = -a;
    T i = T(1);
    for (; i*i < a; i++) {
        if (!(a % i)) {
            factors.push_back(i);
            factors.push_back(a/i);
        }
    }
    if (i*i == a) factors.push_back(i);
    return factors;
}

template<typename T>
T factorial(T a) {
    T f = 1, one = T(1);
    while (a > one) {
        f *= a;
        a--;
    }
    return f;
}

template<typename T>
int numDigits(T a) {
    T ten = T(10);
    int digits = 0;
    while (a) {
        a /= ten;
        digits++;
    }
    return digits;
}

// GCJ | 2012 | Round 1A | Q1
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int testCases;
    scanf("%d", &testCases);
    for (int testNum = 1; testNum <= testCases; testNum++) {
        int A, B;
        real p[100010], q[100010];
        
        scanf("%d%d", &A, &B);
        q[0] = 1.0;
        for (int i = 1; i <= A; i++) {
            scanf("%lf", &p[i]);
            q[i] = p[i] * q[i-1];
            //fprintf(stderr, "q[%d] %lf\n", i, q[i]);
        }
        
        real ans = 2.0 + (real)B;
        for (int b = 0; b <= A; b++) {
            //fprintf(stderr, "%d %lf %lf\n", b, real(B-(A-b)+1.0+b), (real(B-(A-b)+2.0+B+b)));
            ans = min(ans, q[A-b] * real(B-(A-b)+1.0+b) + (1.0-q[A-b]) * (real(B-(A-b)+2.0+B+b)));
        }
        
        printf("Case #%d: ", testNum);
        printf("%.7lf", ans);
        printf("\n");
    }
}
