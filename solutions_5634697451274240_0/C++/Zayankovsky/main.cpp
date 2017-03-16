#include <iostream>
#include <string>

int main()
{
    unsigned T;
    std::cin >> T;
    for (unsigned i = 1; i <= T; ++i)
    {
        std::string S;
        std::cin >> S;
        unsigned n = 0;
        for (unsigned long j = 1; j < S.length(); ++j)
        {
            if (S[j - 1] != S[j])
            {
                ++n;
            }
        }
        if (S.back() == '-')
        {
            ++n;
        }
        std::cout << "Case #" << i << ": " << n << std::endl;
    }
    return 0;
}
