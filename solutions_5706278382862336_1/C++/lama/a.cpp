#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

long long gcd(long long a, long long b) {
    if (b == 0LL)
        return a;
    else
        return gcd(b, a % b);
}

int logg2(long long a) {
    int i = 0;
    long long current = 1LL;
    while (current < a) {
        current *= 2LL;
        i++;
    }

    return (current == a) ? i : -1;
}

int main() {
    int T;
    cin >> T;
    for (int Ti = 1; Ti <= T; ++Ti) {
        long long P, Q;
        char c;
        cin >> P >> c >> Q;

        long long d = gcd(P, Q);
        P /= d;
        Q /= d;

        if (logg2(Q) == -1)
            cout << "Case #" << Ti << ": impossible" << endl;
        else {
            long long half = Q / 2LL;
            if (P >= half)
                cout << "Case #" << Ti << ": " << 1 << endl;
            else {
                int res = 1;
                long long current = P;
                while (current < half) {
                    current *= 2;
                    res++;
                }
                cout << "Case #" << Ti << ": " << res << endl;
            }
        }
            
    }
    return 0;
}