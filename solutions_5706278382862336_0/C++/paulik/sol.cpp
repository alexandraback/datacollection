#include <iostream>
#include <sstream>
#include <string>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    string str;
    cin >> str;
    str[str.find('/')] = ' ';

    LL p, q;
    istringstream inp(str);
    inp >> p >> q;
    LL g = gcd(p, q);
    p /= g, q /= g;

    if (q & (q - 1)) {
        cout << "impossible";
        return;
    }
    for (int i = 0; i <= 41; ++i) {
        if ((q >> i) <= p) {
            cout << i;
            return;
        }
    }
    cout << "error!";
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        cout << "Case #" << t << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}

