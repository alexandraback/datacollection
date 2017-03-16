
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)

int f(int s_max, const char* s_count) {
    int sum = 0;
    int additional = 0;
    for(int i = 0; i <= s_max; i++) {
        int s_i = s_count[i] - '0';

        if(s_i > 0 && i - sum > additional) {
            additional = i - sum;
        }
        sum += s_i;
    }

    return additional;
}

int main() {
    std::string line;

    int numTestCases = 0;
    std::cin >> numTestCases;
    std::getline(std::cin, line);

    for(int testCase = 0; testCase < numTestCases; testCase++) {
        int s_max;

        std::getline(std::cin, line);
        sscanf(line.c_str(), "%d ", &s_max);

        std::cout << "Case #" << (testCase + 1) << ": " << f(s_max, line.c_str() + 2) << std::endl;
    }
}
