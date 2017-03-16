#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>

uint64_t pow(int base, int exp)
{
    uint64_t p = 1;
    for (int i = 0; i < exp; ++i) {
        p *= base;
    }
    return p;
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
        int K, C, S;
        input >> K >> C >> S;
        uint64_t index = 0;
        int count = 0;
        uint64_t max_index = pow(K, C);
        output << "Case #" << t << ": ";
        std::ostringstream out;
        while (true) {
            uint64_t final_index = index;
            for (int i = 1; i < C; ++i) {
                if (index < K-1) {
                    final_index = final_index * K + (index+1);
                    ++index;
                }
                else { // index == K-1
                    final_index = final_index * K + (index);
                }
            }
            ++count;
            if (count > S) {
                 output << "IMPOSSIBLE\n";
                break;
            }
            if (index < K-1) {
                out << final_index+1 << " ";
                ++index;
                continue;
            }
            else { // index == K-1
                out << std::min(final_index+1, max_index) << "\n";
                output << out.str();
                break;
            }
        }
    }
}