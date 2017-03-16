#include <iostream>
#include <stdint.h>

void solveTestCase()
{
    int B;
    double Mf;
    std::cin >> B >> Mf;
    
    if ((1 << (B - 2)) < Mf) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        uint64_t M = Mf;
        std::cout << "POSSIBLE" << std::endl;
        std::cout << '0';
        for (int i = 0; i < B - 2; ++i)
            std::cout << (((M - 1) & (1 << (B - 3 - i))) ? '1' : '0');
        std::cout << '1' << std::endl;
        for (int i = 0; i <= B - 2; ++i)
            std::cout << std::string(i + 2, '0') << std::string(B - 2 - i, '1') << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << (i + 1) << ": ";
        solveTestCase();
    }
    return 0;
}
