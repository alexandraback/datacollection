#include <iostream>
#include <cassert>

void emit_coinjem(int N, unsigned long long mask)
{
    for (int i = N - 1; i >= 0; --i)
    {
        std::cout << ((mask & (1ull << i)) ? '1' : '0');
    }
    for (int base = 2; base < 11; ++base)
    {
        unsigned long long div = base + 1;
#ifdef CHECK
        unsigned long long number = 0;
        unsigned long long curr = 1;
        for (int i = 0; i < N; ++i)
        {
            if (mask & (1ull << i))
            {
                number += curr;
            }
            curr *= base;
        }
        if (number % div != 0)
        {
            std::cout << std::endl;
            std::cout << "Number " << number << std::endl;
            std::cout << "Div " << div << std::endl;
            std::cout << "Base " << base << std::endl;
            assert(false);
        }
#endif
        std::cout << " " << div;
    }
    std::cout << std::endl;
}

const int div_size = 2;

int gen_coinjam_iter(int N, int J, unsigned long long mask, int start_pos)
{
    int total = 0;
    if (start_pos + div_size + 1 >= N)
    {
        return 0;
    }
    if (J == 0)
    {
        return 0;
    }
    unsigned long long div_mask = ~(((1ull << div_size) - 1) << start_pos);
    unsigned long long new_mask = mask & div_mask;
    emit_coinjem(N, new_mask);
    total++;
    total += gen_coinjam_iter(N, J - total, mask, start_pos + div_size);
    total += gen_coinjam_iter(N, J - total, new_mask, start_pos + div_size);
    return total;
}

void gen_coinjam(int N, int J)
{
    unsigned long long mask = (1ull << (N)) - 1;
    gen_coinjam_iter(N, J, mask, 1);
}

int main()
{
    int num_cases;
    std::cin >> num_cases;

    for (int current = 1; current <= num_cases; ++current)
    {
        int N, J;
        std::cin >> N >> J;
        std::cout << "Case #" << current << ": " << std::endl;
        gen_coinjam(N, J);
    }
    return 0;
}
