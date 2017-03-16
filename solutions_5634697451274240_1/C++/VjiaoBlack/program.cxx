#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        printf("Case #%d: ", i+1);
        string stack;

        cin >> stack;
        int length = stack.size();

        bool is_flipped = false;
        int flips = 0;

        for (int j = length - 1; j >= 0; j--) {
            if (is_flipped && stack[j] == '+') {
                flips++;
                is_flipped = !is_flipped;
            } else if (!is_flipped && stack[j] == '-') {
                flips++;
                is_flipped = !is_flipped;
            }
        }

        printf("%d\n", flips);

    }
}
