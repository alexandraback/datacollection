#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//long long f[1000005];

long long N;

long long reverse(long long k) {
    long long ret = 0;
    while (k) {
        ret = ret * 10 + (k % 10);
        k /= 10;
    }
    return ret;
}

/*
void dp() {
    memset(f, 0, sizeof(f));
    for (long long i = 0; i <= 9; ++ i)
        f[i] = i;
    for (long long i = 10; i <= 1000000; ++ i) {
        if (f[i] == 0 || f[i - 1] + 1 < f[i])
            f[i] = f[i - 1] + 1;
        long long k = reverse(i);
        if (k <= 1000000 && k > i)
            f[k] = f[i] + 1;
    }
}
*/

int bit_length(long long k) {
    int ret;
    for (ret = 0; k; k /= 10) ++ ret;
    return ret;
}

long long solve(long long N) {
    long long ret = 0;
    while (N > 9) {
        if (N % 10 == 0) {
            -- N;
            ++ ret;
            continue;
        }
        int bits = bit_length(N);
        bits = bits >> 1;
        long long M = 1;
        while (bits --) M *= 10;
        long long next = (N / M) * M + 1;
        ret = ret + (N - next);
        N = reverse(next);
        if (N == next) {
            N = N - 2;
            ret = ret + 2;
        }
        else
            ++ ret;
    }
    ret = ret + N;
    return ret;
}

int main() {
    int T;
    //dp();
    /*
    for (int i = 1; i <= 1000000; ++ i) {
        long long p = solve(i);
        if (f[i] != p)
            printf("%d = %lld, %lld\n", i, f[i], p);
    }
    */
        //if (f[i] != f[i - 1] + 1) {
            //printf("%d = %d\n", i - 1, f[i - 1]);
        //}
    scanf("%d", &T);
    for (int test = 1; test <= T; ++ test) {
        scanf("%lld", &N);
        printf("Case #%d: %lld\n", test, solve(N));
    }
    return 0;
}
