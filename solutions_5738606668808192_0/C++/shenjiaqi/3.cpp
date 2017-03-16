#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int M = (int)1e4;
int msk[M / 32 + 1];
vector<int> primes;

int isOk(long long v) {
    for (auto i: primes) {
        if (v % i == 0)
            return i;
    }
    return 0;
}

void prtBinary(long long v) {
    if (v == 0)
        return;
    prtBinary(v >> 1);
    printf("%c", v & 1 ? '1' : '0');
}

bool check(long long val) {
    int div[11];
    for (int i = 2; i <= 10; ++i) {
        long long v = 0;
        for (long long m = 1, k = val; k > 0; k >>= 1) {
            if (k & 1)
                v += m;
            m *= i;
        }

        int d = isOk(v);
        if (d == 0)
            return false;
        div[i] = d;
    }
    prtBinary(val);
    for (int i = 2; i <= 10; ++i)
        printf(" %d", div[i]);
    return true;
}

bool isSet(int i) {
    return msk[i >> 5] & (1 << (i & 31));
}

void set(int i) {
    msk[i >> 5] |= (1 << (i & 31));
}

int main() {
    for (int i = 2; i <= M; ++i) {
        if (!isSet(i)) {
            for (int j = i + i; j <= M; j += i)
                set(j);
            primes.push_back(i);
        }
    }

    int N = 16, J = 50;
    printf ("Case #1:\n");
    long long a = 1 | (1LL << (N - 1));
    for (int j = 0; j < J; ++j) {
        while (a < (1LL << N) && !check(a))
            a += 2;
        a += 2;
        if (j + 1 < J)
            printf("\n");
    }
    return 0;
}
