#include <iostream>
#include <vector>
#include <string>

int solve(std::string input) {
    int answer = (input[0] == '-') ? 1 : 0;

    for (int i = 0; i < input.size() - 1; ++i) {
        if ((input[i] == '+') && (input[i + 1] == '-')) {
            answer += 2;
        }
    }

    return answer;
}

int main() {
    int tests_count = 0;

    std::cin >> tests_count;
    std::string input;
    getline(std::cin, input);

    for (int i = 0; i < tests_count; ++i) {
        int n;
        getline(std::cin, input);
        int answer = solve(input);
        std::cout << "Case #" << (i + 1) << ": " << answer << std::endl;
    }

    return 0;
}
