#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>


struct Run {
    size_t begin;
    size_t end;
};


typedef std::vector<Run> RunSeq;


RunSeq Unite(const RunSeq& leftSeq, const RunSeq& rightSeq)
{
    RunSeq result;
    auto leftIt = leftSeq.begin();
    auto rightIt = rightSeq.begin();
    while (leftIt != leftSeq.end() && rightIt != rightSeq.end()) {
        const auto begin = std::min(leftIt->begin, rightIt->begin);
        auto end = begin;
        for (;;) {
            if (leftIt != leftSeq.end() && leftIt->begin <= end) {
                end = std::max(end, leftIt->end);
                ++leftIt;

            } else if (rightIt != rightSeq.end() && rightIt->begin <= end) {
                end = std::max(end, rightIt->end);
                ++rightIt;

            } else {
                break;
            }
        }
        result.push_back({ begin, end });
    }
    result.insert(result.end(), leftIt, leftSeq.end());
    result.insert(result.end(), rightIt, rightSeq.end());
    return result;
}


const size_t LIMIT = 1000000001;

RunSeq Shift(RunSeq runSeq, size_t shift)
{
    for (auto& run : runSeq) {
        run.begin = std::min(run.begin + shift, LIMIT);
        run.end = std::min(run.end + shift, LIMIT);
    }
    return runSeq;
}


RunSeq Extend(RunSeq runSeq, size_t value, size_t usage_factor)
{
    for (size_t usage = 1; usage <= usage_factor; ++usage) {
        //std::cout << '+';
        // for (auto run : runSeq) {
        //     std::cout << run.begin << '-' << (run.end-1) << ' ';
        // }
        //std::cout << '\n';
        //std::cout << '+';
        // for (auto run : Shift(runSeq, value)) {
        //     std::cout << run.begin << '-' << (run.end-1) << ' ';
        // }
        // std::cout << '\n';
        runSeq = Unite(runSeq, Shift(runSeq, value));
    }
    return runSeq;
}


size_t FindMissing(const RunSeq& runSeq)
{
    return runSeq.at(0).end;
}

size_t FindMinimalExtension(std::vector<size_t> set, size_t limit, size_t usage_factor)
{
    std::sort(set.begin(), set.end());
    auto it = set.begin();
    size_t result = 0;
    RunSeq runSeq = { Run{0, 1} };
    while (FindMissing(runSeq) <= limit) {
        if (it != set.end() && *it <= FindMissing(runSeq)) {
            //std::cout << '!' << *it << '\n';
            runSeq = Extend(runSeq, *it, usage_factor);
            ++it;
        } else {
            //std::cout << '!' << FindMissing(runSeq) << '\n';
            runSeq = Extend(runSeq, FindMissing(runSeq), usage_factor);
            ++result;
        }
    }
    return result;
}


int main()
{
    int number_of_cases;
    std::cin >> number_of_cases;
    for (int case_no = 0; case_no < number_of_cases; ++case_no) {
        size_t usage_factor, set_size, limit;
        std::cin >> usage_factor >> set_size >> limit;
        std::vector<size_t> set(set_size);
        for (auto& value : set) {
            std::cin >> value;
        }
        auto result = FindMinimalExtension(set, limit, usage_factor);
        std::cout << "Case #" << (case_no + 1) << ": " << result << '\n';
    }
    return 0;
}
