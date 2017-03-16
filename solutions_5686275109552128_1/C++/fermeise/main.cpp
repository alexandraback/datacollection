
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#pragma warning(disable: 4996)

int f(const std::map<int, int>& m) {
    int min_steps = std::prev(m.end())->first;

    for(int i = 1; i < min_steps; i++) {
        int special_steps = 0;
        for(const auto& v: m) {
            if(v.first > i) {
                special_steps += v.second * ((v.first - i - 1) / i + 1);
            }
        }
        int steps = special_steps + i;
        if(steps < min_steps) {
            min_steps = steps;
        }
    }

    return min_steps;
}

int main() {
    std::string line;

    int numTestCases = 0;
    std::cin >> numTestCases;
    std::getline(std::cin, line);

    for(int testCase = 0; testCase < numTestCases; testCase++) {
        std::map<int, int> m;

        int d;
        std::cin >> d;

        for(int i = 0; i < d; i++) {
            int p;
            std::cin >> p;
            m[p]++;
        }

        std::cout << "Case #" << (testCase + 1) << ": " << f(m) << std::endl;
    }
}
