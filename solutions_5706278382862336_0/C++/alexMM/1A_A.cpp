// 1A_A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <math.h>

using namespace std;

long long gcd (long long a, long long b) {
    if (a < b) {
        swap (a, b);
    }
    while (b) {
        long long tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

bool two_pow (long long q) {
    while (q > 1) {
        if (q % 2) {
            return false;
        }
        q >>= 1;
    }
    return true;
}

int main(int argc, char* argv[])
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        string s;
        cin >> s;
        long long p = 0, q = 0;
        int i = 0;
        for (; s [i] != '/'; ++i) {
            p = p * 10 + (s [i] - '0');
        }
        ++i;
        for (; i < s.length (); ++i) {
            q = q * 10 + (s [i] - '0');
        }
        int g = gcd (p, q);
        p /= g;
        q /= g;
        if (!two_pow (q)) {
            cout << "Case #" << t + 1 << ": impossible" << endl;
            continue;
        }
        int ans = 0;
        while (p < q) {
            p <<= 1;
            ++ans;
        }
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
	return 0;
}

