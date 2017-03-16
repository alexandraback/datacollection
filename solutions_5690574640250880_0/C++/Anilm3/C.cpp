#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <cfloat>
#include <utility>
#include <algorithm>

void PrintGrid(std::vector<std::vector<char> > & grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            std::cout << (grid[i][j] == 'w' ? '.' : grid[i][j]);
        }
        std::cout << std::endl;
    }
}

int Crawl(std::vector<std::vector<char> > & grid, std::pair<int, int> position, int R, int C, int SpaceLeft)
{

    for(int i = position.first - 1; i <= (position.first + 1); i++)
    {
        if (i < 0) continue;
        if (i >= R) break;

        for(int j = position.second - 1; j <= (position.second + 1); j++)
        {
            if (i == position.first && j == position.second) continue;
            if (j < 0) continue;
            if (j >= C) break;

            if (grid[i][j] == 'w' || grid[i][j] == 'c') continue;

            bool NoSpace = false;
            std::deque<std::pair<int, int> > UndoMines;

            grid[i][j] = 'w';

            for(int k = i - 1; k <= (i + 1); k++)
            {
                if (k < 0) continue;
                if (k >= R) break;

                for(int l = j - 1; l <= (j + 1); l++)
                {
                    if (l < 0) continue;
                    if (l >= C) break;
                    if (k == i && l == j) continue;


                    if (grid[k][l] == '*')
                    {
                        if (SpaceLeft > 0)
                        {
                            UndoMines.push_back(std::make_pair(k, l));
                            grid[k][l] = '.';
                            --SpaceLeft;
                        }
                        else
                        {
                            NoSpace = true;
                            break;
                        }
                    }
                }

                if (NoSpace) break;
            }

            if (!NoSpace)
            {
                if (SpaceLeft == 0)
                {
                    return 1;
                }
                else
                {
                    if (Crawl(grid, std::make_pair(i, j), R, C, SpaceLeft) == 1)
                    {
                        return 1;
                    }
                }
            }

            grid[i][j] = '.';

            for (int k = 0; k < UndoMines.size(); k++)
            {
                grid[UndoMines[k].first][UndoMines[k].second] = '*';
                SpaceLeft++;
            }
        }
    }

    return 0;
}

int StartCrawl(std::vector<std::vector<char> > & grid, int R, int C, int x, int y, int SpaceLeft)
{
    bool NoSpace = false;
    std::deque<std::pair<int, int> > UndoMines;

    grid[x][y] = 'c';
    --SpaceLeft;

    if (SpaceLeft == 0)
    {
        return 1;
    }
    
    for(int i = x - 1; i <= (x + 1); i++)
    {
        if (i < 0) continue;
        if (i >= R) break;

        for(int j = y - 1; j <= (y + 1); j++)
        {
            if (j < 0) continue;
            if (j >= C) break;

            if (grid[i][j] == '*')
            {
                if (SpaceLeft > 0)
                {
                    UndoMines.push_back(std::make_pair(i, j));
                    grid[i][j] = '.';
                    --SpaceLeft;
                }
                else
                {
                    NoSpace = true;
                    break;
                }
            }
        }

        if (NoSpace) break;
    }
    
    if (!NoSpace)
    {
        if (SpaceLeft == 0)
        {
            return 1;
        }
        else
        {
            if (Crawl(grid, std::make_pair(x, y), R, C, SpaceLeft) == 1)
            {
                return 1;
            }
        }
    }

    grid[x][y] = '*';

    for (int k = 0; k < UndoMines.size(); k++)
    {
        grid[UndoMines[k].first][UndoMines[k].second] = '*';
        SpaceLeft++;
    }
    
    return 0;
}
int main()
{
    int T;

    std::cin >> T;


    for (int idx = 1; idx <= T; idx ++)
    {
        int R, C, M;
        bool Case = false;
        std::cin >> R;
        std::cin >> C;
        std::cin >> M;

        std::vector<std::vector<char> > grid(R, std::vector<char>(C, '*'));
        int Space = R*C - M;
        // PrintGrid(grid);
        std::cout << "Case #" << idx << ":" << std::endl;
        if (StartCrawl(grid, R, C, 0, 0, Space))
        {
            PrintGrid(grid);
        }
        else
        {
            std::cout << "Impossible" << std::endl;
        }
    }

    return 0;
}