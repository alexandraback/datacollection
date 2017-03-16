#include <iostream>
#include <vector>
#include <algorithm>

bool solve()
{
    std::vector<std::vector<unsigned int>> lawn;
    unsigned int height, width;

    // Init
    std::cin >> height >> width;
    lawn.resize(width, std::vector<unsigned int>(height));

    // Read
    for(unsigned int y = 0; y < height; y++)
    {
        for(unsigned int x = 0; x < width; x++)
        {
            std::cin >> lawn[x][y];
        }
    }

    // Calculate helpers
    unsigned int rowMax[height];
    unsigned int colMax[width];

    for(unsigned int y = 0; y < height; y++)
    {
        rowMax[y] = 0;

        for(unsigned int x = 0; x < width; x++)
        {
            rowMax[y] = std::max(rowMax[y], lawn[x][y]);
        }

        // std::cout << "Row #" << y << ": " << rowMax[y] << std::endl;
    }

    for(unsigned int x = 0; x < width; x++)
    {
        colMax[x] = *std::max_element(lawn[x].begin(), lawn[x].end());

        // std::cout << "Col #" << x << ": " << colMax[x] << std::endl;
    }


    // Solve
    for(unsigned int y = 0; y < height; y++)
    {
        for(unsigned int x = 0; x < width; x++)
        {
            if(rowMax[y] > lawn[x][y] && colMax[x] > lawn[x][y])
                return false;
        }
    }

    return true;
}

int main()
{
    unsigned int t;
    std::cin >> t;
    for(unsigned int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": " << (solve() ? "YES" : "NO") << std::endl;
    }

    return 0;
}
