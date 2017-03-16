#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_set>

using Integer = uint64_t;

using Frontier = std::vector<Integer>;

Integer Reverse(Integer integer)
{
    Integer result = 0;
    while (integer > 0) {
        result = 10 * result + integer % 10;
        integer /= 10;
    }
    return result;
}

void StepForward(const Frontier& input, Frontier* output)
{
    output->clear();
    for (auto integer : input) {
        output->push_back(integer + 1);
        output->push_back(Reverse(integer));
    }
    std::sort(output->begin(), output->end());
    output->erase(std::unique(output->begin(), output->end()), output->end());
}

int FindNumberOfSteps(Integer n)
{
    std::unordered_set<Integer> visited = { 1 };
    Frontier frontier = { 1 };
    Frontier next_frontier;

    //std::cout << "######\n";
    for (int step = 1; ; ++step) {
        if (visited.count(n)) {
            return step;
        }
        next_frontier.clear();
        for (auto integer : frontier) {
            if (visited.insert(integer + 1).second) {
                next_frontier.push_back(integer + 1);
            }
            integer = Reverse(integer);
            if (visited.insert(integer).second) {
                next_frontier.push_back(integer);
            }
        }
        frontier.swap(next_frontier);
        //std::cout << frontier.size() << '\n';
    }
}

int main()
{
    int number_of_cases;
    std::cin >> number_of_cases;
    for (int case_no = 0; case_no < number_of_cases; ++case_no) {
        Integer n;
        std::cin >> n;
        std::cout << "Case #" << (case_no + 1) << ": " << FindNumberOfSteps(n) << '\n';        
    }
    return 0;
}

