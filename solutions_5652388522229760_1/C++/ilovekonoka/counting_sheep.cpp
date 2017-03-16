#include <fstream>
#include <iostream>

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
    int N;
    for (int t = 1; t <= T; ++t) {
        input >> N;
        if (N == 0) {
            output << "Case #" << t << ": INSOMNIA\n";
            continue;
        }

        bool table[10] = { false };
        int S = N;
        Loop:
        while (true) {
            int M = S;
            while (M > 0) {
                table[M % 10] = true;
                M /= 10;
            }
            for (int i = 0; i < 10; ++i) {
                if (!table[i]) {
                    S += N;
                    goto Loop;
                }
            }
            break;
        }

        output << "Case #" << t << ": " << S << "\n";
    }
}