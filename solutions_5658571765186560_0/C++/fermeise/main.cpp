
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#pragma warning(disable: 4996)

int f(int x, int r, int c) {
    const int n = r * c;
    if(n % x != 0) return false;
    
    if(x == 1) {
        return true;
    } else if(x == 2) {
        return true;
    } else if(x == 3) {
        if(std::min(r, c) < 2) return false;
        if(std::max(r, c) < 3) return false;
        return true;
    } else if(x == 4) {
        if(std::min(r, c) < 2) return false;
        if(std::max(r, c) < 4) return false;
        return true;
    } else if(x == 5) {
        if(std::min(r, c) < 4) return false;
        if(std::max(r, c) < 5) return false;
        return true;
    } else if(x == 6) {
        if(std::min(r, c) < 4) return false;
        if(std::max(r, c) < 6) return false;
        return true;
    } else {
        return false;
    }
}

int main() {
    std::string line;

    int numTestCases = 0;
    std::cin >> numTestCases;
    std::getline(std::cin, line);

    for(int testCase = 0; testCase < numTestCases; testCase++) {
        int x, r, c;

        std::cin >> x;
        std::cin >> r;
        std::cin >> c;

        std::cout << "Case #" << (testCase + 1) << ": " << (f(x, r, c) ? "GABRIEL" : "RICHARD") << std::endl;
    }
}
