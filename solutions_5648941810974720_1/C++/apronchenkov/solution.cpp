#include <iostream>
#include <string>
#include <unordered_map>

std::string DecodePhoneNumber(const std::string& string) {
    std::unordered_map<char, int> histogram;
    for (auto c : string) {
        ++histogram[c];
    }
    std::string result;
    const auto decode = [&](char digit, char witness, const std::string& name) {
        const auto n = histogram[witness];
        result.append(n, digit);
        for (auto c : name) {
            histogram[c] -= n;
        }
    };
    decode('0', 'Z', "ZERO");
    decode('2', 'W', "TWO");
    decode('6', 'X', "SIX");
    decode('8', 'G', "EIGHT");
    decode('4', 'U', "FOUR");
    decode('3', 'R', "THREE");
    decode('5', 'F', "FIVE");
    decode('7', 'S', "SEVEN");
    decode('1', 'O', "ONE");
    decode('9', 'E', "NINE");
    std::sort(result.begin(), result.end());
    return result;
}

int main() {
    int number_of_cases;
    std::cin >> number_of_cases;
    for (int case_no = 0; case_no < number_of_cases; ++case_no) {
        std::string string;
        std::cin >> string;
        std::cout << "Case #" << case_no + 1 << ": " << DecodePhoneNumber(string) << '\n';
    }
    return 0;
}
