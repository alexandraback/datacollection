#include <deque>
#include <iostream>
#include <string>

int main()
{
    unsigned T;
    std::cin >> T;
    for (unsigned t = 1; t <= T; ++t)
    {
        std::string S;
        std::cin >> S;
        std::cout << "Case #" << t << ": ";
        std::deque<char> result;
        result.push_back(S.front());
        for (unsigned long i = 1; i < S.length(); ++i)
        {
            if (S[i] < result.front())
            {
                result.push_back(S[i]);
            }
            else
            {
                result.push_front(S[i]);
            }
        }
        for (auto&& c : result)
        {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    return 0;
}

