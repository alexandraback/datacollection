#include <iostream>

unsigned long long count_sheep(int start)
{
    char digits[10] = {};
    int counter = 0;
    if (!start)
    {
        return 0;
    }
    unsigned long long number = start;
    while(1)
    {
        unsigned long long current = number;
        while(current)
        {
            if (!digits[current % 10])
            {
                counter++;
                digits[current % 10] = 1;
            }
            current /= 10;
        }
        if (counter == 10)
        {
            break;
        }
        number += start;
    }
    return number;
}

int main()
{
    int num_cases;
    std::cin >> num_cases;

    for (int current = 1; current <= num_cases; ++current)
    {
        int base;
        std::cin >> base;
        unsigned long long result = count_sheep(base);
        if (!result)
        {
            std::cout << "Case #" << current << ": " << "INSOMNIA" << std::endl;
        }
        else
        {
            std::cout << "Case #" << current << ": " << result << std::endl;
        }
    }
    return 0;
}
