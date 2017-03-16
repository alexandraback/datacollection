#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void inc(string &target, string step) {
    size_t size = max(target.size(), step.size());
    target = string(size - target.size(), '0') + target;
    step = string(size - step.size(), '0') + step;
    string::value_type carry = 0;
    for (size_t i = 0; i < size; ++i) {
        size_t j = size - i - 1;
        string::value_type value = target[j] + step[j] + carry - '0' - '0';
        target[j] = value % 10 + '0';
        carry = value / 10;
    }
    if (carry) {
        target = (char)(carry + '0') + target;
    }
}

int main(int argc, const char *argv[]) {
    ifstream fin("A.in");
    ofstream fout("A.out");
    size_t t;
    fin >> t;
    for (size_t i = 0; i < t; ++i) {
        string step;
        fin >> step;
        if (step == "0") {
            fout << "Case #" << i + 1 << ": INSOMNIA" << endl;
            continue;
        }
        auto num = step;
        uint16_t test = 0b1111111111;
        while (true) {
            for (const auto &c : num) {
                test &= ~(1 << (c - '0'));
            }
            if (test) {
                inc(num, step);
            } else {
                break;
            }
        }
        fout << "Case #" << i + 1 << ": " << num << endl;
    }
    return EXIT_SUCCESS;
}
