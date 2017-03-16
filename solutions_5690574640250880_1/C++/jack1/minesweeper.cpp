#include <iostream>
#include <stack>
#include <vector>


template<typename Matrix>
void print(int r, int c, const Matrix& matrix)
{
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
            std::cout << matrix[x][y];
        std::cout << std::endl;
    }   
}

template<typename Matrix>
bool process_case(int r, int c, int m, Matrix& matrix)
{

    matrix[r-1][c-1] = 'c';
    
    // Special case
    if (m == r * c - 1)
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (!(i == r-1 && j == c-1))
                    matrix[i][j] = '*';
        return true;
    }
    
    int amount;
    
    // Fill row-wise
    for (int i = 0; i < r && m > 0; i++)
    {
        if (i < r - 2) // We are not in the last two rows (that are special)
        {
            amount = (m != c - 1) ? std::min(m, c) : (c - 2);
            if (amount > 0)
            {
                std::fill(&matrix[i][0], &matrix[i][0] + amount, '*');
                m -= amount;
            }
            else
            {
                break;
            }
        }
        else // We are in the last two rows!
        {
            if (r == 1) // there is only one row
            {
                if (m > c - 2) return false; // there are not enough free columns
                std::fill(&matrix[i][0], &matrix[i][0] + m, '*'); // put the mines
                m = 0;
            }
            else // there are at least two rows
            {
                int limit = c - 2;
                if (m % 2 != 0) // try to steal some mines from the previous row
                {
                    if (r == 2) return false; // there are exactly 2 rows, we cannot steal anything 
                    if (c <= 3) return false; // doing this on rows having less than 3 columns would lead to some inconsistencies
                    int take = (amount == c) ? 3 : 1; // we should take 3 from a full row, 1 from a partial row
                    for (int k = 1; k <= take; k++)
                        matrix[i - 1][amount - k] = '.'; // remove the mines
                    m += take;
                    limit--; // let's bring the limit back
                }
                if (m / 2 > limit) return false;
                std::fill(&matrix[i][0], &matrix[i][0] + m / 2, '*');
                std::fill(&matrix[i + 1][0], &matrix[i + 1][0] + m / 2, '*');
                m = 0;
            }
        }
    }
    
    return m == 0;
    
}

int main()
{

    int no_test_cases;
    std::cin >> no_test_cases;
    
    //debug
    //std::cout << no_test_cases << std::endl;
    
    for (int i = 1; i <= no_test_cases; i++)
    {
        int r, c, m;
        std::cin >> r >> c >> m;
        //debug
        //std::cout << r << " " << c << " " << m << std::endl;
        std::cout << "Case #" << i << ": " << std::endl;
        std::vector<std::vector<char> > matrix(r, std::vector<char>(c, '.'));
        if (process_case(r, c, m, matrix))
        {
            print(r, c, matrix);
        }
        else
        {
            std::cout << "Impossible" << std::endl;
        }
    }
    
    return 0;
    
}
