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

int solve(int R, int C, int W) {
    int perrow = C / W; // initial dots per row
    int hits = R * perrow; // initial dots until the first hit
    int left = W - 1; // how many places to the left
    int right = C - (W * perrow); // how many places to the right
    if (!right)
        return hits + left;
    return hits + 1 + left;
}

int main() {
    int T = read<int>();
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int R = read<int>();
        int C = read<int>();
        int W = read<int>();
        printf("Case #%d: %d\n", caseNum, solve(R, C, W));
    }
    return 0;
}
