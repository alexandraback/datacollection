#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
#define INF 1 << 30;
#define SMAX 9999


long long N;

inline long long swap(long long i) {
    long long o = 0;
    for (;i > 0; i /= 10) {
        o *= 10;
        o += (i%10);
    }
    return o;
}

inline long long msd(long long i) {
    return swap(i)%10;
}

inline long long lsd(long long i) {
    return i%10;
}

inline long long length(long long i) {
    long long res = 0;
    for (;i > 0; i /= 10) {
        ++res;
    }
    return res;
}

inline long long left(long long i) {
    long long upto = length(i)/2;
    long long mod = 1;
    for(long long o = 0; o < upto; o++, mod *= 10);
    return i%mod;
}


unsigned long long dp[SMAX+100];

long long rec(long long n) {
    /* cout << "*" << n << endl; //DEB */
    // base case
    if (n < SMAX) return dp[n];
    // keep decrementing until leftside digits consist of (0^n)1
    long long count = 0;
    while (left(n) != 1 || swap(n) >= n) {
        ++count;
        --n;
        if (n < SMAX) return count + dp[n];
    }
    // then swap and rec
    return rec(swap(n)) + count + 1;
}

int main() {
    int TC;
    cin >> TC;
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    for (int i = 1; i < SMAX; i++) {
        long long swapped = swap(i);
        if (swapped < SMAX) dp[swapped] = min(dp[i]+1, dp[swapped]);
        dp[i+1] = min(dp[i]+1, dp[i+1]);
    }
    for (int tc = 1; tc <= TC; tc++) {
        cin >> N;

        long long res = rec(N);

        cout << "Case #" << tc << ": " << res << endl;
    }
    return 0;
}
