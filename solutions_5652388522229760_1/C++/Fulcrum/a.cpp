#include <iostream>
#include <vector>

int solve(int n) {
    if (n == 0) {
        return -1;
    }

    int digits_count = 0;
    std::vector<bool> digits(10, false);

    int number = 0;
    while (true) {
        number += n;
        int number_copy = number;
        while (number_copy > 0) {
            int digit = number_copy % 10;
            number_copy /= 10;

            if (digits[digit] == false) {
                digits[digit] = true;
                ++digits_count;
            }

            if (digits_count == 10) {
                return number;
            }
        }
    }
}


int main() {
    int tests_count = 0;

    std::cin >> tests_count;

    for (int i = 0; i < tests_count; ++i) {
        int n;
        std::cin >> n;
        int answer = solve(n);
        std::cout << "Case #" << (i + 1) << ": ";
        if (answer == -1) {
            std::cout << "INSOMNIA" << std::endl;
        } else {
            std::cout << answer << std::endl;
        }
    }

    return 0;
}
