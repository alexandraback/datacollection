#include <cassert>
#include <bitset>
#include <cctype>
#include <fstream>
#include <iostream>

// convert a binary string to some base
uint64_t convert_to_base(uint64_t string, uint32_t base)
{
    uint64_t result = 0;
    uint64_t mask = 1;
    uint64_t b = 1;
    for (uint32_t i = 0; i < 32; ++i) {
        auto temp = (string & mask);
        result += (string & mask) * b;
        string >>= 1;
        b *= base;
    }
    return result;
}

// 1abcdef11abcdef1
void solve_small(std::ofstream& output)
{
    uint16_t counter = 0;
    uint16_t template_ = (1u << 15) + (1u << 8) + (1u << 7) + 1u;
    for (int i = 0; i < 50; ++i) {
        uint16_t num = (counter << 1) + (counter << 9) + template_;
        output << std::bitset<16>(num) << " ";
        for (uint32_t base = 2; base <= 10; ++base) {
            output << convert_to_base(num >> 8, base) << " ";
            assert(num % (num >> 8) == 0);
        }
        output << "\n";
        ++counter;
    }
}

// 1abcdefghi100000000001abcdefghi1
void solve_large(std::ofstream& output)
{
    uint32_t counter = 0;
    uint32_t template_ = (1u << 31) + (1u << 21) + (1u << 10) + 1u;
    for (int i = 0; i < 500; ++i) {
        uint32_t num = (counter << 1) + (counter << 22) + template_;
        output << std::bitset<32>(num) << " ";
        for (uint32_t base = 2; base <= 10; ++base) {
            output << convert_to_base(num >> 21, base) << " ";
            assert(num % (num >> 21) == 0);
        }
        output << "\n";
        ++counter;
    }
}

int main(int argc, char** argv)
{
    if (argc < 3) {
        std::cout << "filename input output\n";
        return EXIT_FAILURE;
    }

    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);
    int T = 0;
    input >> T;
    for (int t = 1; t <= T; ++t) {
        int N, J;
        input >> N >> J;
        output << "Case #" << t << ":\n";
        if (N == 16)
            solve_small(output);
        else
            solve_large(output);
    }
}