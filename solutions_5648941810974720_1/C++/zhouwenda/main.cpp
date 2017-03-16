#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>


void addNumber(std::vector<int>& instance, int num, char id, std::string chars, std::vector<int>& result) {
    int count = instance[id - 'a'];

    std::fill_n(std::back_inserter(result), count, num);

    for (auto c : chars) {
        instance[c - 'a'] -= count;
    }
}


std::vector<int> solveInstance(std::vector<int> instance) {
    std::vector<int> result;

    addNumber(instance, 0, 'z', "zero", result);
    addNumber(instance, 2, 'w', "two", result);
    addNumber(instance, 6, 'x', "six", result);
    addNumber(instance, 8, 'g', "eight", result);
    addNumber(instance, 4, 'u', "four", result);

    // now that eight is gone three is only one with h
    addNumber(instance, 3, 'h', "three", result);
    addNumber(instance, 1, 'o', "one", result);
    addNumber(instance, 5, 'f', "five", result);
    addNumber(instance, 7, 'v', "seven", result);
    addNumber(instance, 9, 'i', "nine", result);

    std::sort(result.begin(), result.end());

    return result;
}


int main(int argc, char** argv) {
    std::ifstream stream(argv[1]);

    std::string line;

    std::getline(stream, line);

    auto exampleCount = std::atoi(line.c_str());

    for (int i = 0; i < exampleCount; ++i) {
        std::vector<int> chars(26);

        std::getline(stream, line);

        for(auto c : line) {
            chars[c - 'A'] += 1;
        }

        auto result = solveInstance(chars);

        std::cout << "Case #" << i + 1 << ": ";

        for (auto n : result) {
            std::cout << n;
        }

        std::cout << std::endl;
    }
    return 0;
}