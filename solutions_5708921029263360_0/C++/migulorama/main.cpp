#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <vector>
#include <sstream>
#include <numeric>

using table_line = std::vector < uint32_t > ;
using table = std::vector<table_line>;

std::string eval(uint16_t J, uint16_t P, uint16_t S, uint16_t K)
{
    auto sp = table(S, table_line(P, 0));
    auto pj = table(P, table_line(J, 0));
    auto sj = table(S, table_line(J, 0));

    std::ostringstream oss;
    uint32_t total = 0;

    for (uint16_t s = 0; s < S; ++s)
    {
        for (uint16_t p = 0; p < P; ++p)
        {
            if (sp[s][p] == K)
                continue;

            for (uint16_t j = 0; j < J; ++j)
            {
                if (pj[p][j] == K)
                    continue;
                if (sj[s][j] == K)
                    continue;

                sp[s][p]++;
                pj[p][j]++;
                sj[s][j]++;

                total++;
                oss << std::endl << j+1 << " " << p+1 << " " << s+1;
            }
        }
    }

    return std::to_string(total) + oss.str();
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <test_file> <output_file>" << std::endl;
        return 1;
    }

    auto inputFilename = argv[1];
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open())
    {
        std::cerr << "File not found: '" << inputFilename << "'" << std::endl;
        return 2;
    }

    auto outputFilename = argv[2];
    std::ofstream outFile(outputFilename);
    if (!outFile.is_open())
    {
        std::cerr << "Could not open file '" << outputFilename << "' for writing." << std::endl;
        return 2;
    }

    uint16_t T;
    inputFile >> T;

    for (uint16_t t = 1; t <= T; ++t)
    {
        uint16_t J, P, S, K;
        inputFile >> J >> P >> S >> K;

        auto result = eval(J, P, S, K);

        outFile << "Case #" << t << ": " << result << std::endl;
    }
}