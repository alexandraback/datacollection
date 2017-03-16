#include <cstdio>
#include <iostream>

using namespace std;

#define PROBLEM "A-small-attempt0"

int solve(long long N) {
    long long n;
    int i, m;
    for (n = N, i = 0, m = 0; i < 10000; ++i) {
        for(long long nn = n; nn; nn /= 10)
            m |= 1 << (nn % 10);
        if (m == 1023)
            return n;
        n += N;
    }
    cerr << "Problem number: " << N << endl;
    throw "FAILED";
}

int main()
{
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        cout << "Case #" << t << ": ";
        if (n == 0)
            cout << "INSOMNIA" << endl;
        else
            cout << solve(n) << endl;
    }

    return 0;
}
