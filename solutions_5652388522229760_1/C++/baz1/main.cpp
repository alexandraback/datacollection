#include <iostream>
#include <string>

#include <gmpxx.h>

using namespace std;

void fillup(bool *digits, int number) {
    while (number) {
        digits[number % 10] = true;
        number /= 10;
    }
}

int main() {
    bool seen[10];
    int T, N, result;
    cin >> T;
    for (int i = 0; i < T;) {
        cin >> N;
        if (N == 0) {
            cout << "Case #" << (++i) << ": INSOMNIA" << endl;
            continue;
        }
        memset(seen, 0, 10 * sizeof(bool));
        result = N;
        while (true) {
            fillup(seen, result);
            for (int j = 10;;) {
                if (!seen[--j])
                    break;
                if (!j)
                    goto endLoop;
            }
            result += N;
        }
endLoop:
        cout << "Case #" << (++i) << ": " << result << endl;
    }
    return 0;
}

// Gives: 4782
