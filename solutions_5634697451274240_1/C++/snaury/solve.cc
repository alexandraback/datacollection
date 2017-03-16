#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

template<class T>
inline T read() {
    T value;
    std::cin >> value;
    return value;
}

void flip(char& ch) {
    // + => 43
    // - => 45
    ch = 45 - (ch - 43);
}

void flip(std::string& S, size_t count) {
    size_t i = 0, j = count - 1;
    while (i < j) {
        std::swap(S[i], S[j]);
        flip(S[i]);
        flip(S[j]);
        ++i;
        --j;
    }
    if (i == j) {
        // single pancake special case
        flip(S[i]);
    }
}

int main() {
    auto T = read<int>();
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int flips = 0;
        auto S = read<std::string>();
        for (;;) {
            // Remove any trailing +, since it is redundant
            while (!S.empty() && S[S.size() - 1] == '+')
                S.resize(S.size() - 1);
            if (S.empty())
                break;
            if (S[0] == '+') {
                // Flip as many happy pancakes as possible
                size_t i = 0;
                do {
                    S[i++] = '-';
                } while (S[i] == '+');
                ++flips;
            }
            // Flip the whole stack
            std::reverse(S.begin(), S.end());
            for (auto& p : S) {
                flip(p);
            }
            ++flips;
        }
        printf("Case #%d: %d\n", caseNum, flips);
    }
    return 0;
}
