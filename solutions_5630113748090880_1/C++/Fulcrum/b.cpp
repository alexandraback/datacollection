#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> solve(std::vector<int>& soldiers) {
    std::sort(soldiers.begin(), soldiers.end());

    int current_number = -1;
    int current_count = 0;
    std::vector<int> answer;

    for (int i = 0; i < soldiers.size(); ++i) {
        int soldier = soldiers[i];
        if (soldier != current_number) {
            if (current_count % 2 == 1) {
                answer.push_back(current_number);
            }

            current_number = soldier;
            current_count = 1;
        } else {
            ++current_count;
        }
    }

    if (current_count % 2 == 1) {
        answer.push_back(current_number);
    }

    std::sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    int tests_count = 0;

    std::cin >> tests_count;

    for (int i = 0; i < tests_count; ++i) {
        int soldiers_count;
        std::cin >> soldiers_count;
        std::vector<int> soldiers;
        for (int i = 0; i < soldiers_count * (2 * (soldiers_count) - 1); ++i) {
            int soldier;
            std::cin >> soldier;
            soldiers.push_back(soldier);
        }

        std::vector<int> answer = solve(soldiers);
        std::cout << "Case #" << (i + 1) << ":";
        for (int i = 0; i < answer.size(); ++i) {
            std::cout << " " << answer[i];
        }
        std::cout << std::endl;
    }

    return 0;
}
