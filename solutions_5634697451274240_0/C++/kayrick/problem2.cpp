#include <iostream>

unsigned long long count_flips(const std::string &input)
{
    int counter = 0;
    char curr = input[0];
    for (int idx = 1; idx < input.size(); ++idx)
    {
        if (input[idx] != curr)
        {
            counter++;
            curr = input[idx];
        }
    }
    if (curr == '-')
    {
        counter++;
    }
    return counter;
}

int main()
{
    int num_cases;
    std::cin >> num_cases;

    for (int current = 1; current <= num_cases; ++current)
    {
        std::string input;
        std::cin >> input;
        std::cout << "Case #" << current << ": " << count_flips(input) << std::endl;
    }
    return 0;
}
