#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

int solve(std::vector<int>& kids) {
    for (int i = 0; i < kids.size(); ++i) {
        --kids[i];
    }

    std::unordered_map<int, int> cycles;
    std::unordered_map<int, int> chains;

    for (int first_index = 0; first_index < kids.size(); ++first_index) {
        std::set<int> visited;
        int index = first_index;
        while (visited.count(index) == 0) {
            visited.insert(index);
            index = kids[index];
        }

        if (index == first_index) {
            int id = *visited.begin();
            if (cycles.count(id) == 0) {
                cycles[id] = visited.size();
            }
        }
        if (index == kids[kids[index]]) {
            int id = index;
            if ((chains.count(id) == 0) || (chains[id] < visited.size())) {
                chains[id] = visited.size();
            }
        }
    }

    int answer = 0;

    for (auto it = chains.begin(); it != chains.end(); ++it) {
        int first_kid = it->first;
        int second_kid = kids[first_kid];
        if (first_kid > second_kid) {
            int second_chain_length = chains[second_kid];
            answer += it->second + second_chain_length - 2;
        }
    }

    for (auto it = cycles.begin(); it != cycles.end(); ++it) {
        answer = std::max(answer, it->second);
    }

    return answer;

}

int main() {
    int tests_count = 0;

    std::cin >> tests_count;

    for (int i = 0; i < tests_count; ++i) {
        int kids_count;
        std::cin >> kids_count;
        std::vector<int> kids;
        for (int i = 0; i < kids_count; ++i) {
            int kid;
            std::cin >> kid;
            kids.push_back(kid);
        }

        int answer = solve(kids);
        std::cout << "Case #" << (i + 1) << ": " << answer << std::endl;
    }

    return 0;
}
