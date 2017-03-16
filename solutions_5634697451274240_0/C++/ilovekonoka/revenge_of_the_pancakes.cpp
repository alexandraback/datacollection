#include <fstream>
#include <iostream>
#include <limits>
#include <string>

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
    std::string line;
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int t = 1; t <= T; ++t) {
        line.clear();
        std::getline(input, line);
        int count = 0;
        for (size_t i = 1; i < line.size(); ++i) {
            if (line[i] != line[i-1]) {
                ++count;
            }
        }
        if (line.back() == '-') {
            ++count;
        }
        output << "Case #" << t << ": " << count << "\n";
    }
}