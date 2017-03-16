#include <iostream>
#include <vector>

bool isVocal(char c)
{
    switch(c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;

        default:
            return false;
    }
}

uint64_t solve()
{
    std::string str;
    uint64_t n;

    std::cin >> str;
    std::cin >> n;

    if(n == 0)
    {
        uint64_t l = str.length();

        return (l * (l + 1)) / 2;
    }

    std::vector<uint64_t> consonants(str.length());

    consonants[0] = isVocal(str[0]) ? 0 : 1;
    for(uint64_t i = 1; i < str.length(); i++)
    {
        consonants[i] = isVocal(str[i]) ? 0 : consonants[i - 1] + 1;
    }

    std::vector<uint64_t> ending(str.length());

    uint64_t total = 0;

    ending[0] = consonants[0] >= n ? 1 : 0;
    total += ending[0];
    for(uint64_t i = 1; i < str.length(); i++)
    {
        if(consonants[i] >= n)
        {
            ending[i] = (i - (n - 1)) + 1;
        }
        else
        {
            ending[i] = ending[i - 1];
        }

        total += ending[i];
    }

    return total;
}

int main()
{
    uint64_t t;
    std::cin >> t;

    for(uint64_t i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": " << solve() << std::endl;
    }

    return 0;
}
