#include <iostream>
#include <unordered_set>

void extract_digits(unsigned N, std::unordered_set<unsigned>& digits)
{
    while (N)
    {
        digits.insert(N % 10);
        N /= 10;
    }
}

int main()
{
    unsigned T;
    std::cin >> T;
    for (unsigned i = 1; i <= T; ++i)
    {
        unsigned N, iN = 0;
        std::cin >> N;
        if (N == 0)
        {
            std::cout << "Case #" << i << ": INSOMNIA" << std::endl;
            continue;
        }
        std::unordered_set<unsigned> digits;
        while (digits.size() < 10)
        {
            iN += N;
            extract_digits(iN, digits);
        }
        std::cout << "Case #" << i << ": " << iN << std::endl;
    }
    return 0;
}
