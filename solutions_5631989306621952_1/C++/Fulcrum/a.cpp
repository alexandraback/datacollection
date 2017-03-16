#include <iostream>
#include <string>
#include <sstream>

std::string solve(const std::string& input) {
    std::string answer = "";

    for (char ch : input) {
        std::stringstream option1_stream;
        option1_stream << answer << ch;
        std::string option1 = option1_stream.str();

        std::stringstream option2_stream;
        option2_stream << ch << answer;
        std::string option2 = option2_stream.str();

        if (option1.compare(option2) < 0) {
            answer = option2;
        } else {
            answer = option1;
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
        std::string answer = solve(input);
        std::cout << "Case #" << (i + 1) << ": " << answer << std::endl;
    }

    return 0;
}
