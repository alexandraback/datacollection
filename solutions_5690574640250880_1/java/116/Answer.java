package problem3;

import java.util.List;

public class Answer
{
    private int      x, y; // start point
    private char[][] grid;
    
    public Answer(int x, int y, List<String> grid)
    {
        this.grid = new char[grid.size()][grid.get(0).length()];
        
        int i = 0;
        for (String s : grid)
        {
            int j = 0;
            for (char c : s.toCharArray())
            {
                this.grid[i][j] = c;
                j++;
            }
            i++;
        }
        
        this.x = x;
        this.y = y;
    }
    
    public Answer(int x, int y, char[][] grid)
    {
        this.grid = grid;
        this.x = x;
        this.y = y;
    }
    
    public boolean validSolution()
    {
        recursiveBrowse(x, y);
        return count('.') == 0;
    }
    
    /**
     * recursively browse the grid from the start point
     * 
     * @param grid2
     */
    private void recursiveBrowse(int x, int y)
    {
        if (x < 0 || y < 0 || x >= grid.length || y >= grid[0].length || grid[x][y] != '.')
        {
            return;
        }
        else
        {
            int surrounding = countArround('*', x, y);
            if (surrounding == 0)
            {
                grid[x][y] = '0';
                
                for (int i = -1; i < 2; ++i)
                {
                    for (int j = -1; j < 2; ++j)
                    {
                        recursiveBrowse(x + i, y + j);
                    }
                }
            }
            else
            {
                grid[x][y] = (char) ('0' + surrounding);
            }
        }
    }
    
    public int count(char c)
    {
        int total = 0;
        for (int i = 0; i < grid.length; ++i)
        {
            for (int j = 0; j < grid[0].length; ++j)
            {
                if (grid[i][j] == c)
                {
                    total++;
                }
            }
        }
        
        return total;
    }
    
    /**
     * Coutns the occurences of c on the 8 points arround (x,y)
     * 
     * @param c
     * @param x
     * @param y
     * @return
     */
    private int countArround(char c, int x, int y)
    {
        int total = 0;
        for (int i = -1; i < 2; ++i)
        {
            for (int j = -1; j < 2; ++j)
            {
                try
                {
                    if (grid[x + i][y + j] == c)
                    {
                        total++;
                    }
                }
                catch (ArrayIndexOutOfBoundsException e)
                {
                    // this is expected
                }
            }
        }
        return total;
    }
    
    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < grid.length; ++i)
        {
            for (int j = 0; j < grid[0].length; ++j)
            {
                if (x == i && y == j)
                {
                    sb.append('c');
                }
                else
                {
                    sb.append(grid[i][j]);
                }
            }
            if (i != grid.length - 1)
            {
                sb.append('\n');
            }
        }
        return sb.toString();
    }
    
}
