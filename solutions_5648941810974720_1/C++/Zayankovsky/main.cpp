#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool contains_word(std::unordered_map<char, unsigned>& all_letters, std::unordered_map<char, unsigned>& letters)
{
    for (auto&& pair : letters)
    {
        if (all_letters[pair.first] < letters[pair.first])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    unsigned T;
    std::cin >> T;
    for (unsigned t = 1; t <= T; ++t)
    {
        std::string S;
        std::cin >> S;
        std::unordered_map<char, unsigned> letters;
        for (char letter : S)
        {
            ++letters[letter];
        }
        std::cout << "Case #" << t << ": ";
        std::vector<unsigned> number;
        unsigned digits[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        std::string code = "ZWUXGOHFSN";
        for (unsigned i = 0; i < 10; ++i)
        {
            while (true)
            {
                if (letters[code[i]])
                {
                    number.push_back(digits[i]);
                    for (char letter : words[digits[i]])
                    {
                        --letters[letter];
                    }
                }
                else
                {
                    break;
                }
            }
        }
        std::sort(number.begin(), number.end());
        for (unsigned digit : number)
        {
            std::cout << digit;
        }
        std::cout << std::endl;
    }
    return 0;
}

