#include <iostream>
#include <stdint.h>
#include <sstream>

int main()
{
    int t, n, j;
    std::cin >> t >> n >> j;
    
    std::cout << "Case #1:" << std::endl;
    
    std::stringstream factorStream;
    for (int base = 2; base <= 10; ++base) {
        uint64_t factor = 1;
        for (int i = 0; i < n/2; ++i)
            factor *= base;
        factor += 1;
        factorStream << " " << factor;
    }
    std::string factorString = factorStream.str();
    
    uint64_t s = (uint64_t(1) << uint64_t(n/2 - 1)) + 1;
    while(j--) {
        for (int j = 0; j < 2; ++j)
            for (int i = n/2 - 1; i >= 0; --i)
                std::cout << (((s >> i) & 1) ? "1" : "0");
        std::cout << factorString << std::endl;
        
        s += 2;
    }
    
    return 0;
}