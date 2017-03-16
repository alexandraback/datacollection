#include <cstdio>
#include <string>
#include <iostream>
#include <bitset>

using namespace std;

#define PROBLEM "C-small-attempt1"

// Output operator for __int128_t
// Author: James Kanze
// Source: http://stackoverflow.com/a/25115163
std::ostream& operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

void solve(int n, int j) {
    const int N = 16;
    const int N1 = N - 1;
    const int maxbase = 10;

    if (n != N) throw "Unsupported N";

    long long m = (1UL << N1) + 1;
    int cnt = 0;
    while (cnt < j) {
        long long d = 3;
        while(d * d <= m) {
            if (m % d == 0) break;
            d += 2;
        }
        if (m % d == 0) {
            bool ok = true;
            for (int b = 3; ok && b <= maxbase; ++b) {
                __int128_t a = 0, e = 0;
                for (long long f = 1UL << N1; f; f >>= 1) {
                    a = a * b + (f&m ? 1 : 0);
                    e = e * b + (f&d ? 1 : 0);
                }
                ok = (a % e == 0);
            }
            if (ok) {
                cnt++;
                cout << bitset<N>((unsigned int)m) << " " << d;
                for (int b = 3; b <= maxbase; ++b) {
                    __int128_t a = 0, e = 0;
                    for (long long f = 1UL << N1; f; f >>= 1) {
                        a = a * b + (f&m ? 1 : 0);
                        e = e * b + (f&d ? 1 : 0);
                    }
                    cout << "  " << e;
                }
                cout << endl;
            }
        }
        m += 2;
    }
}

int main()
{
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, j;
        cin >> n >> j;
        cout << "Case #" << t << ":" << endl;
        solve(n, j);
    }

    return 0;
}
