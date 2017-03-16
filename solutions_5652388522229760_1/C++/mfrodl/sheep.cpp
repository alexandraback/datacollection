#include <iostream>
#include <bitset>

using namespace std;

unsigned long compute(unsigned long n) {
    unsigned long m;
    unsigned short r;
    bitset<10> digits;

    digits.flip();

    for (int i = 1; true; i++) {
        m = i * n;
        while (m > 0) {
            r = m % 10;
            m = m / 10;
            digits.reset(r);
        }

        if (digits.none()) {
            return i * n;
        }
    }
}

int main() {
    unsigned short t;
    unsigned long n;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << "Case #" << i + 1 << ": ";
        if (n == 0) {
            cout << "INSOMNIA";
        }
        else {
            cout << compute(n);
        }
        cout << endl;
    }

    return 0;
}
