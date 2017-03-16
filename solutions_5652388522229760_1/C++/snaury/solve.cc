#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

template<class T>
inline T read() {
    T value;
    std::cin >> value;
    return value;
}

int main() {
    int T = read<int>();
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        auto N = read<int64_t>();
        if (N == 0) {
            printf("Case #%d: INSOMNIA\n", caseNum);
            continue;
        }
        std::unordered_set<int> waiting = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto current = N;
        for (;;) {
            auto check = current;
            while (check) {
                waiting.erase(check % 10);
                check /= 10;
            }
            if (waiting.empty())
                break;
            current += N;
        }
        printf("Case #%d: %lld\n", caseNum, current);
    }
    return 0;
}
