// Solution to Problem B. Lawnmower in C++.

#include <algorithm>
#include <iostream>

int main()
{
    int t, n, m;
    int lawn[100][100];
    bool can_x[100][100];
    int i, j, max;
    
    std::cin >> t;
    for (int c = 1; c <= t; c++)
    {
        std::cin >> n >> m;
        
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                std::cin >> lawn[i][j];
        
        char const* res = "YES";
        
        for (i = 0; i < n; i++)
        {
            max = *std::max_element(lawn[i], lawn[i] + m);
            for (j = 0; j < m; j++)
                can_x[i][j] = lawn[i][j] == max;
        }
        for (j = 0; j < m; j++)
        {
            max = 1;
            for (i = 0; i < n; i++)
            {
                if (lawn[i][j] > max)
                    max = lawn[i][j];
            }
            for (i = 0; i < n; i++)
            {
                if (lawn[i][j] < max)
                {
                    if (!can_x[i][j])
                    {
                        res = "NO";
                        goto done;
                    }
                }
            }
        }
        
done:
        std::cout << "Case #" << c << ": " << res << std::endl;
    }

}
