#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

uint64_t rev(uint64_t n)
{
    uint64_t r = 0;
    while (n > 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

int dig(uint64_t n)
{
    int d = 0;
    while (n > 0) {
        d++;
        n /= 10;
    }
    return d;
}

int msd(uint64_t n)
{
    int r;
    while (n > 0) {
        r = n % 10;
        n /= 10;
    }
    return r;
}

int main()
{
    int T;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        uint64_t N;
        cin >> N;

        uint64_t s;
        for (s = 0; N > 0; s++) {
            cerr << N << endl;
            int64_t a = 1;
            while (a*a < N)
                a *= 10;
            if (N % a == 1) {
                int64_t r = rev(N);
                if (r < N) {
                    N = r;
                    continue;
                }
            }
            N--;
        }

        cout << "Case #" << testcase+1 << ": ";
        cout << s << endl;
    }
    return 0;
}

// vim: set sw=4:
