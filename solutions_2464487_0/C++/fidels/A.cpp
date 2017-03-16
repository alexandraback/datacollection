#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T, t;
    long long R, P, s, e, m;

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> R >> P;

        s = 1; e = 1;
        while (e*(2LL*e + 2LL*R - 1LL) <= P) e*=2;
        while (e-s > 1LL) {
            m = (s+e)/2LL;
            if (m*(2LL*m + 2LL*R - 1LL) > P) e = m;
            else s = m;
        }
        cout << "Case #" << t << ": " << s << endl;
    }

    return 0;
}
