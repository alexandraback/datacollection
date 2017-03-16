#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

intmax_t calc_hops(intmax_t p, intmax_t q, intmax_t max_hops)
{
    intmax_t counter = 0;
    if (p == q) return 0;
    while (counter < max_hops)
    {
        counter++;
        // try to double p
        p *= 2;
        if (p == q)
        {   
            return counter;
        }
        else if (p > q)
        {
            if (calc_hops(p - q, q, max_hops - counter) != -1)
                return counter;
            else
                return -1;
        }
    }
    return -1;
}

int main()
{

    // Read the number of test cases
    int no_test_cases;
    std::cin >> no_test_cases;
    
    // Debug
    //std::cout << no_test_cases << std::endl;
    
    for (int i = 1; i <= no_test_cases; i++)
    {
        intmax_t p, q;
        std::cin >> p;
        std::cin.ignore(1);
        std::cin >> q;
        const intmax_t no_hops = calc_hops(p, q, 40);
        if (no_hops != -1)
        {
            std::cout << "Case #" << i << ": " << no_hops << std::endl;
        }
        else
        {
            std::cout << "Case #" << i << ": impossible" << std::endl;
        }
    }
    
    return 0;
    
}
