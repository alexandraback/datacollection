#include <cassert>
#include <iostream>
#include <vector>


uint32_t EncloseSet(const std::vector<int>& set)
{
    uint32_t result = 0;
    for (uint32_t mask = 0; (mask >> set.size()) == 0; ++mask) {
        int sum = 0;
        for (size_t i = 0; i < set.size(); ++i) {
            if ((mask >> i) & 1) {
                sum += set[i];
            }
        }
        if (sum < 32) {
            result = result | (1 << sum);
        }
    }
    return result;
}


int MinZeroBit(uint32_t mask)
{
    int result = 0;
    while (mask & 1) {
        mask /= 2;
        ++result;
    }
    return result;
}


std::vector<int> ImproveSetOfCoins(std::vector<int> set, int limit)
{
    for (;;) {        
        int next_move = MinZeroBit(EncloseSet(set));
        if (next_move > limit) {
            //std::cout << '\n';
            return set;
        }
        //std::cout << next_move << ' ';
        set.push_back(next_move);
    }
}


int main()
{
    int number_of_cases;
    std::cin >> number_of_cases;
    for (int case_no = 0; case_no < number_of_cases; ++case_no) {
        int usage_factor, set_size, limit;
        std::cin >> usage_factor >> set_size >> limit;
        assert (usage_factor == 1);

        std::vector<int> set;
        for (int i = 0; i < set_size; ++i) {
            int value;
            std::cin >> value;
            set.push_back(value);
        }
        auto result = (ImproveSetOfCoins(set, limit).size() - set.size());
        std::cout << "Case #" << (case_no + 1) << ": " << result << '\n';
    }
    return 0;
}
