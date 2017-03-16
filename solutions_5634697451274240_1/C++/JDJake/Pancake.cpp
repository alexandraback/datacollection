#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    string sequence;
    for (int i = 1; i <= T; i++) {
        cin >> sequence;

        int num_flips = 0;

        while (true) {
            int flipped_so_far = 0;
            bool flipped_everything = true;
            char current_symbol = sequence[0];
            for (int i = 0; i < sequence.length(); i++) {
                if (sequence[i] != current_symbol) {
                    flipped_everything = false;
                    break;
                }
                else flipped_so_far = i;
            }
            if (flipped_everything) {
                if (current_symbol == '-') num_flips++;
                break;
            }

            char next_symbol;
            if (current_symbol == '+') next_symbol = '-';
            else next_symbol = '+';
            for (int i = 0; i <= flipped_so_far; i++) {
                sequence[i] = next_symbol;
            }

            num_flips++;
        }

        printf("Case #%d: %d\n", i, num_flips);
    }
}