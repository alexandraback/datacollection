#include <iostream>
#include <string>

size_t findMinimalNumberOfFlips(const std::string& row) {
    size_t result = 0;
    for (size_t i = 0; i + 1 < row.size(); ++i) {
        if (row[i] != row[i + 1]) {
            ++result;
        }
    }
    if (!row.empty() && row.back() != '+') {
        ++result;
    }
    return result;
}

int main() {
    int numberOfCases;
    std::cin >> numberOfCases;
    for (int caseNo = 0; caseNo < numberOfCases; ++caseNo) {
        std::string row;
        std::cin >> row;
        std::cout << "Case #" << caseNo + 1 << ": " << findMinimalNumberOfFlips(row) << '\n';
    }
    return 0;
}
