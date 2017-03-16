#include <iostream>

int MakeDigitBitmask(int x) {
    int result = 0;
    while (x > 0) {
        result |= 1 << (x % 10);
        x /= 10;
    }
    return result;
}

int FindFinalNumber(int initialNumber) {
    if (initialNumber == 0) {
        return -1;
    }
    int x = initialNumber;
    int bitmask = MakeDigitBitmask(initialNumber);
    while (bitmask < 1023) {
        x += initialNumber;
        bitmask |= MakeDigitBitmask(x);
    }
    return x;
}


int main() {
    int numberOfCases;
    std::cin >> numberOfCases;
    for (int caseNo = 0; caseNo < numberOfCases; ++caseNo) {
        int initialNumber;
        std::cin >> initialNumber;
        const auto finalNumber = FindFinalNumber(initialNumber);
        std::cout << "Case #" << caseNo + 1 << ": ";
        if (finalNumber >= 0) {
            std::cout << finalNumber;
        } else {
            std::cout << "INSOMNIA";
        }
        std::cout << '\n';
    }
    return 0;
}
