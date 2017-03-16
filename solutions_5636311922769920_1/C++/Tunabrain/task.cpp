#include <iostream>
#include <stdint.h>

int main()
{
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int k, c, s;
        std::cin >> k >> c >> s;
        
        std::cout << "Case #" << (i + 1) << ":";
        
        int numRequired = (k + c - 1)/c;
        if (numRequired > s) {
            std::cout << " IMPOSSIBLE";
        } else {
            int numKnown = 0;
            while (numKnown < k) {
                uint64_t index = numKnown++;
                for (int j = 0; j < c - 1; ++j) {
                    index = index*k;
                    if (j + 1 < k && numKnown < k)
                        index += numKnown++;
                }
                std::cout << " " << (index + 1);
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}