#include <iostream>
#include <cstdint>
using namespace std;

int main(void) {
    int t, n, digitCount, unit, multiple;
    uint64_t current, temp;
    bool digits[10];
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        digitCount = 0;
        multiple = 0;
        current = n;
        temp = n;
        if (0 == n) {
            cout << "Case #" << i << ": INSOMNIA" << endl;
            continue;
        }
        for (int j = 0; j < 10; ++j) digits[j] = false;
        do {
            while (temp > 0 && digitCount < 10) {
                unit = temp % 10;
                if (!digits[unit]) {
                    ++digitCount;
                    digits[unit] = true;
                }
                temp /= 10;
            }
            if (10 == digitCount) {
                cout << "Case #" << i << ": " << current << endl;
                break;
            } else {
                temp = current + n;
                current = temp;
                ++multiple;
            }
        } while (multiple < 1000); // is 1000 a good upper bound?
    }
    return 0;
}
