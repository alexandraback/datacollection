#include <iostream>
#include <vector>

using std::vector;

vector<long long> solve(int size, int complexity, int workers) {
    vector<long long> answer;
    if (complexity * workers < size) {
        return answer;
    }

    long long tile = 1;
    long long depth = 1;
    long long position = 1;
    bool is_finished = false;
    while (true) {
        if (tile < size) {
            ++tile;
        } else {
            is_finished = true;
        }

        if (depth == complexity) {
            depth = 1;
            answer.push_back(position);
            position = tile;
            if (is_finished) {
                break;
            }
        } else {
            ++depth;
            position *= size;
            position -= (size - tile);
        }
    }

    return answer;
}

int main() {
    int tests_count = 0;

    std::cin >> tests_count;

    for (int i = 0; i < tests_count; ++i) {
        int size;
        int complexity;
        int workers;
        std::cin >> size >> complexity >> workers;
        vector<long long> answer = solve(size, complexity, workers);
        std::cout << "Case #" << (i + 1) << ":";
        if (answer.empty()) {
            std::cout << " IMPOSSIBLE";
        } else {
            for (int i = 0; i < answer.size(); ++i) {
                std::cout << " " << answer[i];
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
