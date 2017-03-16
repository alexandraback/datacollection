#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
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
        int N = read<int>();
        std::vector<int> F(N, 0);
        for (int i = 0; i < N; ++i) {
            F[i] = read<int>() - 1;
        }
        int R = 0;
        // all pairs that form a loop
        std::unordered_map<int, int> loop_sizes;
        for (int start = 0; start < N; ++start) {
            std::vector<bool> visited(N, false);
            int prev = -1;
            int current = start;
            int count = 0;
            while (!visited[current]) {
                ++count;
                visited[current] = true;
                prev = current;
                current = F[current];
            }
            if (F[current] == prev) {
                // ends in a loop, will be considered later
                auto& loop_size = loop_sizes[prev * N + current];
                if (loop_size < count)
                    loop_size = count;
                if (R < count)
                    R = count;
                continue;
            }
            if (current == start) {
                // full circle, valid answer
                if (R < count)
                    R = count;
            }
        }
        int P = 0;
        while (!loop_sizes.empty()) {
            auto it = loop_sizes.begin();
            int key = it->first;
            int inv = (key % N) * N + (key / N);
            int count = it->second;
            loop_sizes.erase(it);
            it = loop_sizes.find(inv);
            if (it != loop_sizes.end()) {
                count += it->second - 2;
                loop_sizes.erase(it);
            }
            P += count;
        }
        if (R < P)
            R = P;
        printf("Case #%d: %d\n", caseNum, R);
    }
    return 0;
}
