#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
        if (a < b)
                swap(a, b);
        while (b) {
                int64_t d = a % b;
                a = b;
                b = d;
        }
        return a;
}

int64_t rho(int64_t n)
{
        int64_t x = 1, y = 1, d = 1;
        while (d == 1) {
                x = (x * x + 1) % n;
                y = (y * y + 1) % n;
                y = (y * y + 1) % n;
                d = gcd(n, abs(x - y));
        }
        return d;
}

int64_t popcount(int64_t n)
{
        n = ((n >>  1) & 0x5555555555555555LL) + (n & 0x5555555555555555LL);
        n = ((n >>  2) & 0x3333333333333333LL) + (n & 0x3333333333333333LL);
        n = ((n >>  4) & 0x0f0f0f0f0f0f0f0fLL) + (n & 0x0f0f0f0f0f0f0f0fLL);
        n = ((n >>  8) & 0x00ff00ff00ff00ffLL) + (n & 0x00ff00ff00ff00ffLL);
        n = ((n >> 16) & 0x0000ffff0000ffffLL) + (n & 0x0000ffff0000ffffLL);
        n = ((n >> 32) & 0x00000000ffffffffLL) + (n & 0x00000000ffffffffLL);
        return n;
}

int64_t mod(int64_t N, int64_t n, int64_t k)
{
        const static vector<int64_t> primes = {
                5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
                61, 57, 71, 73, 83, 89, 97, 101, 103, 107, 109, 113, 127,
        };
        for (auto p: primes) {
                int64_t m = 0;
                for (int64_t i = 1LL << (N - 1); i > 0; i >>= 1) {
                        m = m * k;
                        if (n & i)
                                m++;
                        m %= p;
                }
                if (!m)
                        return p;
        }
        return 0;
}

int main(int argc, char **argv)
{
        int T;
        cin >> T;
        for (int t = 0; t < T; t++) {
                cout << "Case #" << t+1 << ":" << endl;
                int N, J;
                cin >> N >> J;
                int64_t n = 1LL << (N - 1);
                vector<int64_t> r = { 0, 2, 0, 2, 0, 2, 0, 2, 3 };
                while (J > 0) {
                        n++;
                        if (!(n & 1))
                                continue;
                        if (popcount(n) % 6)
                                continue;
                        r[0] = rho(n);
                        if (r[0] == n)
                                continue;
                        if (!(r[2] = mod(N, n, 4)))
                                continue;
                        if (!(r[4] = mod(N, n, 6)))
                                continue;
                        if (!(r[6] = mod(N, n, 8)))
                                continue;
                        for (int64_t i = 1LL << (N - 1); i > 0; i >>= 1)
                                cout << (n & i ? '1' : '0');
                        for (auto i: r)
                                cout << ' ' << i;
                        cout << endl;
                        J--;
                }
        }
        return 0;
}
