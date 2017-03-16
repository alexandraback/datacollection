#include <iostream>
#include <set>

int main()
{
    unsigned T;
    std::cin >> T;
    for (unsigned t = 1; t <= T; ++t)
    {
        unsigned long N;
        std::cin >> N;
        std::cout << "Case #" << t << ":";
        std::set<unsigned> items;
        for (unsigned i = 0, item; i < 2 * N * N - N; ++i)
        {
            std::cin >> item;
            auto it = items.find(item);
            if (it != items.end())
            {
                items.erase(it);
            }
            else
            {
                items.insert(item);
            }
        }
        for (auto&& item : items)
        {
            std::cout << ' ' << item;
        }
        std::cout << std::endl;
    }
    return 0;
}

