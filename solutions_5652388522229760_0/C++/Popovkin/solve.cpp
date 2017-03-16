#include <iostream>
#include <fstream>
#define ll long long

using namespace std;

ll a, b, c, d, e;
bool m[10];

void update(ll a) {
    if (a == 0) m[0] = 1;
    while (a) {
        m[a % 10] = 1;
        a /= 10;
    }
}

bool check() {
    for (int i = 0; i < 10; ++i)
        if (!m[i]) return 0;
    return 1;
}

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    cin >> a;
    for (int i = 0; i < a; ++i) {
        cin >> b;
        for (ll q = 0; q < 10; ++q)
            m[q] = 0;
        ll q = 0;
        for (q = 1; q < 1000000 && !check(); ++q)
            update(q * b);
        if (check()) cout << "Case #" << i + 1 << ": " << (q - 1) * b << "\n";
        else cout << "Case #" << i + 1 << ": INSOMNIA\n";
    }
}