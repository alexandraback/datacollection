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
                // XXX: overflow?
                x = (x * x + 1) % n;
                y = (y * y + 1) % n;
                y = (y * y + 1) % n;
                d = gcd(n, abs(x - y));
        }
        return d;
}

int main(int argc, char **argv)
{
        int T;
        cin >> T;
        for (int t = 0; t < T; t++) {
                cout << "Case #" << t+1 << ":" << endl;
                int N, J;
                cin >> N >> J;
                int64_t n = 1 << (N - 1);
                while (J > 0) {
                        n++;
                        if (!(n & 1))
                                continue;
                        cerr << '-' << endl;
                        int64_t m;
                        vector<int64_t> r;
                        for (int i = 2; i <= 10; i++) {
                                m = 0;
                                for (int64_t j = 1 << (N - 1); j > 0; j >>= 1) {
                                        m *= i;
                                        if (n & j)
                                                m++;
                                }
                                int64_t d = rho(m);
                                cerr << i << ' ' << m << ' ' << d << endl;
                                if (d == m)
                                        break;
                                r.push_back(d);
                        }
                        if (r.size() < 9)
                                continue;
                        cout << m;
                        for (auto i: r)
                                cout << ' ' << i;
                        cout << endl;
                        J--;
                }
        }
        return 0;
}
