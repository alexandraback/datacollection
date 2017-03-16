#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    std::string str;
    std::getline(std::cin, str);
    for (int i = 1; i <= T; ++i)
    {
        std::cout << "case #" << i << ": ";
        std::getline(std::cin, str);
        bool current = str[0] == '+';
        int nb_change = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            if ((str[i] == '+') != current)
            {
                ++nb_change;
                current = !current;
            }
        }
        if (str[str.length() - 1] == '-')
            ++nb_change;
        std::cout << nb_change << '\n';
    }
    return 0;
}
