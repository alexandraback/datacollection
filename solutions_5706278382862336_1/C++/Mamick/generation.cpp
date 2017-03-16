#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long u, long long v) {
    while ( v != 0) {
        long long r = u % v;
        u = v;
        v = r;
    }
    return u;
}

long long highest(long long p, long long q) {
    long long tmp2 = GCD(p,q);
    p /= tmp2;
    q /= tmp2;
    // cout << p << " " << q << endl;
    if (q % 2 != 0) return -99999999;
    if (p == q) return 0;
    return highest(p / 2 + p % 2, q / 2) + 1;
}

bool works(long long q) {
    if (q == 1) return true;
    if (q % 2 != 0) return false;
    return works(q/2);
}

int main() {
    long long t;
    cin >> t;
    for (long long cases = 1; cases <= t; cases++) {
        long long p, q;
        char tmp;
        cin >> p >> tmp >> q;
        long long tmp2 = GCD(p,q);
        p /= tmp2;
        q /= tmp2;
        cout << "Case #" << cases <<": ";
        // long long tmp3 = highest(p,q);
        if (!works(q)) {
            cout << "impossible" << endl;
            continue;
        }
        int count = 0;
        long long num = 1;
        while (num * 2 < p) num *= 2;
        while (num < q) {
            num *= 2;
            count ++;
        }
        cout << count << endl;
    }
}