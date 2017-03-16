#include <cstdlib>
#include <iostream>
#include <set>


int main(void)
{
    int n = 16;
    int j = 50;

    std::cout << "Case #1:" << std::endl;
    std::set<__int128> seen;

    while (j--) another: {
        std::string seq(n, '1');

        for (unsigned i = 1; i < seq.size() - 1; i++) {
            if (rand() & 1) {
                seq[i] = '0';
            }
        }

        int divs[9];

        for (int j = 10; j > 1; j--) {
            __int128 r = 0;
            for (unsigned i = 0; i < seq.size(); i++)
                r = r * j + (seq[i] == '1');
            std::cerr << seq << ' ' << j << ' ' << (unsigned long long) r << std::endl;
            if (j == 10) {
                if (seen.find(r) != seen.end())
                    goto another;
                seen.insert(r);
            }

            __int128 div = 2;
            if (r % div == 0)
                goto found;
            for (div = 3; div < 10000; div += 2)
                if (r % div == 0)
                    goto found;
            goto another;

        found:
            divs[j - 2] = (int) div;
        }

        std::cout << seq;
        for (int i = 0; i < 9; i++)
            std::cout << ' ' << divs[i];
        std::cout << std::endl;
    }
    return 0;
}