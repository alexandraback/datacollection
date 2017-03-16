#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdint>
#include <vector>

const size_t DigitsCount = 10;

int64_t n, cur;
int seen_count;
std::vector<bool> seen;

void observe_number(int64_t cur) {
    while (cur > 0) {
        if (!seen[cur % DigitsCount]) {
            ++seen_count;
            seen[cur % DigitsCount] = true;
        }
        cur /= DigitsCount;
    }
}

void solve() {
    if (n == 0)
        return;

    observe_number(cur);
    while (seen_count < DigitsCount) {
        cur = cur + n;
        observe_number(cur);
    }
}


void read(std::istream &input) {
    input >> n;
    cur = n;

    seen_count = 0;
    seen.assign(DigitsCount, false);
}


void print(std::ostream &output) {
    if (seen_count < DigitsCount) {
        output << "INSOMNIA" << std::endl;
    } else {
        output << cur << std::endl;
    }
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