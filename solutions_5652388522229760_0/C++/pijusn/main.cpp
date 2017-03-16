// Pijus Navickas <pijus.navickas@gmail.com>

#include <iostream>
#include <unordered_set>
#include <cstring>

#define BASE 10

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ullong;

using namespace std;

void markDigits(ullong x, bool* seenDigits, uint& remaining) {
    static uint digit;
    do {
        digit = x % BASE;
        if (!seenDigits[digit]) {
            --remaining;
            seenDigits[digit] = true;
        }
        x /= BASE;
    } while (x);
}

ullong findSolution(ullong x, ullong increment) {
    static bool seenDigits[BASE];

    unordered_set<ullong> checkedValues;
    ullong maxX = static_cast<ullong>(-1) - increment;

    memset(seenDigits, false, sizeof(bool) * BASE);
    uint remaining = BASE;

    for (;;) {
        if (!checkedValues.insert(x).second) {
            return 0;
        }

        markDigits(x, seenDigits, remaining);

        if (!remaining) {
            return x;
        }

        if (x > maxX) {
            cout << "fucked?" << endl;
            return 0; // May not be correct but we won't be able to find solution with it.
        }

        // cout << "x=" << x << "; remaining=" << remaining << endl;

        x += increment;
    }
}

void doTestCase(uint number) {
    ullong n;
    cin >> n;

    ullong result = findSolution(n, n);

    if (result) {
        cout << "Case #" << number << ": " << result << endl;
    } else {
        cout << "Case #" << number << ": " << "INSOMNIA" << endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    uint t;
    cin >> t;
    for (uint i = 0; i != t; ++i) {
        doTestCase(i + 1);
    }

    return 0;
}
