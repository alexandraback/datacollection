package problem3;

import java.util.ArrayList;
import java.util.List;

import org.junit.experimental.theories.PotentialAssignment.CouldNotGenerateValueException;

import net.lab0.tools.Pair;

public class Case
{
    private int x;
    private int y;
    private int m;
    
    public int getX()
    {
        return x;
    }
    
    public int getY()
    {
        return y;
    }
    
    public int getM()
    {
        return m;
    }
    
    public Case(int x, int y, int m)
    {
        super();
        this.x = x;
        this.y = y;
        this.m = m;
    }
    
    private char[][] createGrid(int x, int y)
    {
        char[][] grid = new char[x][y];
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                grid[i][j] = '.';
            }
        }
        return grid;
    }
    
    public Object solve()
    {
        // easy case: empty
        if (m == 0)
        {
            char[][] grid = createGrid(x, y);
            for (int i = 0; i < x; ++i)
            {
                for (int j = 0; j < y; ++j)
                {
                    grid[i][j] = '.';
                }
            }
            return new Answer(x - 1, y - 1, grid);
        }
        
        // easy case: full
        if (m == x * y - 1)
        {
            char[][] grid = createGrid(x, y);
            for (int i = 0; i < x; ++i)
            {
                for (int j = 0; j < y; ++j)
                {
                    grid[i][j] = '*';
                }
            }
            grid[0][0] = '.';
            return new Answer(0, 0, grid);
        }
        
        int free = x * y - m;
        int minSize = Math.min(x, y);
        
        // easy cases: 1/2 rows/columns
        switch (minSize)
        {
            case 1:
                char[][] grid = createGrid(x, y);
                if (x == minSize)
                {
                    for (int i = 0; i < m; ++i)
                    {
                        grid[0][i] = '*';
                    }
                }
                else
                {
                    for (int i = 0; i < m; ++i)
                    {
                        grid[i][0] = '*';
                    }
                }
                return new Answer(x - 1, y - 1, grid);
                
            case 2:
                if (m % 2 == 0)
                {
                    if (x * y - m == 2)
                    {
                        return "Impossible";
                    }
                    char[][] grid1 = createGrid(x, y);
                    if (x == minSize)
                    {
                        for (int i = 0; i < m / 2; ++i)
                        {
                            grid1[0][i] = '*';
                            grid1[1][i] = '*';
                        }
                        
                        return new Answer(0, y - 1, grid1);
                    }
                    else
                    {
                        for (int i = 0; i < m / 2; ++i)
                        {
                            grid1[i][0] = '*';
                            grid1[i][1] = '*';
                        }
                        
                        return new Answer(x - 1, 0, grid1);
                    }
                }
                else
                {
                    return "Impossible";
                }
        }
        
        // normal solve
        
        char[][] grid = createGrid(x, y);
        int count = 0;
        
        outer:
        {
            for (int i = 0; i < x - 2; ++i)
            {
                for (int j = 0; j < y - 2; ++j)
                {
                    grid[i][j] = '*';
                    count++;
                    if (count == m)
                    {
                        break outer;
                    }
                }
            }
            
            if (grid[x - 3][y - 3] == '*')
            {
                grid[x - 3][y - 3] = '.';
                count--;
            }
            
            for (int i = 0; i < x - 3; ++i)
            {
                grid[i][y - 1] = '*';
                grid[i][y - 2] = '*';
                count += 2;
                if (m - count < 2)
                {
                    break outer;
                }
            }
            
            for (int j = 0; j < y - 3; ++j)
            {
                grid[x - 1][j] = '*';
                grid[x - 2][j] = '*';
                count += 2;
                if (m - count < 2)
                {
                    break outer;
                }
            }
        }
        
        // hard-coded solutions
        switch (m - count)
        {
            case 8:
                grid[x - 2][y - 2] = '*';
                grid[x - 2][y - 1] = '*';
                grid[x - 1][y - 2] = '*';
                
            case 5:
                grid[x - 1][y - 3] = '*';
                grid[x - 2][y - 3] = '*';
                
            case 3:
                grid[x - 3][y - 2] = '*';
                grid[x - 3][y - 1] = '*';
                
            case 1:
                grid[x - 3][y - 3] = '*';
                
            case 0:
                return new Answer(x - 1, y - 1, grid);
            default:
                return "Impossible";
        }
    }
    
    @Override
    public String toString()
    {
        return "Case [x=" + x + ", y=" + y + ", m=" + m + "]";
    }
    
}
