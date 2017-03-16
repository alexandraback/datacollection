#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <vector>
#include <sstream>
#include <numeric>

// max_paths[B-2] B in [2, 22]
uint64_t max_paths[20] = {
1                    ,
2                    ,
5                    ,
16                   ,
65                   ,
326                  ,
1957                 ,
13700                ,
109601               ,
986410               ,
9864101              ,
108505112            ,
1302061345           ,
16926797486          ,
236975164805         ,
3554627472076        ,
56874039553217       ,
966858672404690      ,
17403456103284421    ,
330665665962404000
};

std::string eval(uint32_t B, uint64_t M)
{
    if (B < 22 && max_paths[B - 2] < M)
        return "IMPOSSIBLE";

    auto matrix = std::vector<std::vector<bool>>(B, std::vector<bool>(B, false));

    for (uint32_t i = 0; i < B-1 && M > 0; ++i)
    {
        for (uint32_t j = 0; j < i; ++j)
            matrix[j][i] = true;
        matrix[i][B - 1] = true;
        M -= 1;
    }

    std::ostringstream oss;
    oss << "POSSIBLE";
    for (const auto& line : matrix)
    {
        oss << std::endl;
        for (const auto& value : line)
            oss << value;
    }

    return oss.str();
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
        uint32_t B;
        inputFile >> B;

        uint64_t M;
        inputFile >> M;

        auto result = eval(B, M);

        outFile << "Case #" << t << ": " << result << std::endl;
    }
}