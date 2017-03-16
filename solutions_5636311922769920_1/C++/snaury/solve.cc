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

int main() {
    int T = read<int>();
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int K = read<int>();
        int C = read<int>();
        int S = read<int>();
        printf("Case #%d:", caseNum);
        // We have K tiles down C levels
        // At level C each student can verify C original tiles at once
        int need_students = (K + C - 1) / C;
        if (need_students > S) {
            printf(" IMPOSSIBLE\n");
            continue;
        }
        // To calculate unions we use zero-based indexes with this formula:
        // index = t1 * K^C + t2 * K^C-1 + t3 * K^C-2 ...
        int base = 0;
        while (base < K) {
            uint64_t index = base++;
            for (int i = 1; i < C; ++i) {
                index *= K;
                if (base < K) {
                    index += base++;
                }
            }
            printf(" %llu", index + 1);
        }
        printf("\n");
    }
    return 0;
}
