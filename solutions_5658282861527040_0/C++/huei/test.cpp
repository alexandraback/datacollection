#include <set>
#include <iostream>

#define BITS_SIZE 16

int main(void)
{
    int cases = 0;
    std::cin >> cases;

    for (int i = 1; i <= cases; ++i)
    {
        int a = 0;
        int b = 0;
        int k = 0;
        std::cin >> a >> b >> k;

        std::set<std::pair<int, int>> s;

        for (int j = 0; j < a; ++j)
        {
            for (int l = 0; l < b; ++l)
            {
                if ((j & l) < k)
                {
                    s.insert(std::make_pair(j, l));
                }
            }
        }

        std::cout << "Case #" << i << ": ";
        std::cout << s.size() << std::endl;
    }

    return 0;
}
