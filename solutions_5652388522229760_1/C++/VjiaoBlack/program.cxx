#include <iostream>

using namespace std;


int see_number(long number, int seen_digits) {
    while (number > 0) {
        int shift = number % 10;

        int add_mask = 1;
        add_mask = add_mask << shift;

        seen_digits |= add_mask;

        number /= 10;
    }

    return seen_digits;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int seen_digits = 0;
        long N;
        cin >> N;
        long hold = 0;

        cout << "Case #" << i+1 << ": ";

        if (N == 0) {
            cout << "INSOMNIA" << endl;
            continue;
        }

        while (seen_digits != 0x3FF) {
            hold += N;
            seen_digits = see_number(hold, seen_digits);
        }

        cout << hold << endl;

    }
}

