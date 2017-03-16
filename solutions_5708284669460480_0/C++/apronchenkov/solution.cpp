#include <numeric>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


std::vector<size_t> ComputePrefixFunction(const std::string& input)
{
    std::vector<size_t> result;
    result.reserve(input.size() + 1);
    result.push_back(0);
    result.push_back(0);

    size_t offset = 0;
    for (size_t i = 1; i < input.size(); ++i) {
        while (offset > 0 && input[offset] != input[i]) {
            offset = result[offset];
        }
        if (input[offset] == input[i]) {
            ++offset;
        }
        result.push_back(offset);
    }
    return result;
}


std::unordered_map<char, double> ComputeKeyProbability(const std::string& keyboard)
{
    std::unordered_map<char, double> result;
    for (char c : keyboard) {
        result[c] += 1.0 / keyboard.size();
    }
    return result;
}


double FindMaxNumberOfMatches(const std::string& keyboard, const std::string& target, size_t total_size)
{
    const auto key_probability = ComputeKeyProbability(keyboard);
    for (char c : target) {
        if (key_probability.count(c) == 0) {
            return 0.0;
        }
    }
    const auto prefix_function = ComputePrefixFunction(target);
    return (total_size - prefix_function.back()) / (target.size() - prefix_function.back());
}


std::vector<double> Normalize(std::vector<double> values)
{
    const auto total = std::accumulate(values.begin(), values.end(), 0.0);
    for (auto& value : values) {
        value /= total;
    }
    return values;
}


size_t NextOffset(const std::string& target, const std::vector<size_t>& prefix_function, size_t offset, char c)
{
    while (offset > 0 && target[offset] != c) {
        offset = prefix_function[offset];
    }
    if (target[offset] == c) {
        offset += 1;
    }
    return offset;
}


double FindAvrNumberOfMatches(const std::string& keyboard, const std::string& target, size_t total_size)
{
    const auto key_probability = ComputeKeyProbability(keyboard);
    const auto prefix_function = ComputePrefixFunction(target);

    double result = 0.0;
    std::vector<double> state(target.size() + 1, 0.0);
    state[0] = 1.0;
    for (size_t i = 0; i < total_size; ++i) {
        // for (auto x : state) {
        //     std::cout << x << ' ';
        // }
        // std::cout << '\n';
        std::vector<double> next_state(target.size() + 1, 0.0);
        for (size_t offset = 0; offset < state.size(); ++offset) {
            for (const auto& pair : key_probability) {
                size_t next_offset = NextOffset(target, prefix_function, offset, pair.first);
                next_state[next_offset] += state[offset] * pair.second;
            }
        }
        state = Normalize(std::move(next_state));
        result += state.back();
    }
    return result;
}


int main()
{
    int number_of_cases;
    std::cin >> number_of_cases;
    for (int case_no = 0; case_no < number_of_cases; ++case_no) {
        int keyboard_size, target_size, total_size;
        std::string keyboard, target;
        std::cin >> keyboard_size >> target_size >> total_size >> keyboard >> target;

        const double max_number_of_matches = FindMaxNumberOfMatches(keyboard, target, total_size);
        const double avr_number_of_matches = FindAvrNumberOfMatches(keyboard, target, total_size);
        std::cout << "Case #" << (case_no + 1) << ": " << std::setprecision(9) << (max_number_of_matches - avr_number_of_matches) << '\n';
    }
    return 0;
}
