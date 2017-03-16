#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

const char SmileyFace = '+';
const char EmptyFace = '-';

std::string sequence;
int changes_count;

void solve() {
    for (size_t i = 1; i < sequence.size(); ++i) {
        if (sequence[i] != sequence[i - 1]) {
            ++changes_count;
        }
    }
}


void read(std::istream &input) {
    input >> sequence;

    changes_count = 0;
}


void print(std::ostream &output) {
    output << changes_count + (sequence.back() == SmileyFace ? 0 : 1) << std::endl;
}


int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    size_t t;
    std::cin >> t;
    for (size_t i = 1; i <= t; ++i) {
        read(std::cin);
        solve();
        std::cout << "Case #" << i << ": ";
        print(std::cout);
    }
    return 0;
}