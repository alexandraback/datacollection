#include <cstdint>
#include <iostream>

int FindMinialScore(int number_of_rows, int number_of_columns, int ship_size)
{
    int result = number_of_rows * (number_of_columns / ship_size);
    if (number_of_columns > ship_size && number_of_columns % ship_size > 0) {
        result += ship_size;
    } else {
        result += ship_size - 1;
    }
    return result;
}

int main()
{
    int number_of_cases;
    std::cin >> number_of_cases;
    for (int case_no = 0; case_no < number_of_cases; ++case_no) {
        int number_of_rows, number_of_columns, ship_size;
        std::cin >> number_of_rows >> number_of_columns >> ship_size;

        std::cout << "Case #" << (case_no + 1) << ": " << FindMinialScore(number_of_rows, number_of_columns, ship_size) << '\n';
    }
    return 0;
}
