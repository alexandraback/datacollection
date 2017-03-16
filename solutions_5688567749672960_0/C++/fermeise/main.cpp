
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

bool initialized = false;
std::vector<int> steps(1000001, INT_MAX);

int reverse(int x) {
    int r = 0;
    while(x > 0) {
        r *= 10;
        r += x % 10;
        x /= 10;
    }

    return r;
}

int f(int x) {
    if(!initialized) {
        steps[0] = 0;
        for(int i = 0; i < 1000000; i++) {
            steps[i + 1] = std::min(steps[i + 1], steps[i] + 1);
            steps[reverse(i)] = std::min(steps[reverse(i)], steps[i] + 1);
        }
        initialized = true;
    }

    return steps[x];
}

int main() {
    std::string line;

    int numTestCases = 0;
    std::cin >> numTestCases;
    std::getline(std::cin, line);

    for(int testCase = 0; testCase < numTestCases; testCase++) {
        int x;

        std::cin >> x;

        std::cout << "Case #" << (testCase + 1) << ": " << f(x) << std::endl;
    }
}
