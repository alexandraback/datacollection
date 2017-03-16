#include <iostream>
#include <string>
#include <vector>


int countWinCombinations(int firstMax, int secondMax, int boundary)
{
    int result = 0;
    for (int a = 0; a < firstMax; ++a) {
        for (int b = 0; b < secondMax; ++b) {
            if ((a & b) < boundary) {
                ++result;
            }
        }
    }
    return result;
}


int main()
{
    int numberOfCases;
    std::cin >> numberOfCases;
    for (int caseNo = 1; caseNo <= numberOfCases; ++caseNo) {
        int A, B, K;
        std::cin >> A >> B >> K;
        std::cout << "Case #" << caseNo << ": " << countWinCombinations(A, B, K) << '\n';
    }
    return 0;
}
