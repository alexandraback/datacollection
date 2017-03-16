#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

int clear(char **grid, int C, int R, int x, int y)
{
    int c = 0;
    if(grid[x][y] == '*')
    {
        grid[x][y] = '.';
        c++;
    }
    if(x>0)
    {
        if (y>0 && grid[x-1][y-1] == '*')
        {
            grid[x-1][y-1] = '.';
            c++;
        }
        if(grid[x-1][y] == '*')
        {
            grid[x-1][y] = '.';
            c++;
        }
        if (y<R-1 && grid[x-1][y+1] == '*')
        {
            grid[x-1][y+1] = '.';
            c++;
        }
    }
    if (y>0 && grid[x][y-1] == '*')
    {
        grid[x][y-1] = '.';
        c++;
    }
    if(grid[x][y] == '*')
    {
        grid[x][y] = '.';
        c++;
    }
    if (y<R-1 && grid[x][y+1] == '*')
    {
        grid[x][y+1] = '.';
        c++;
    }
    if(x<C-1)
    {
        if (y>0 && grid[x+1][y-1] == '*')
        {
            grid[x+1][y-1] = '.';
            c++;
        }
        if(grid[x+1][y] == '*')
        {
            grid[x+1][y] = '.';
            c++;
        }
        if (y<R-1 && grid[x+1][y+1] == '*')
        {
            grid[x+1][y+1] = '.';
            c++;
        }
    }
    return c;
}

int main(int argc, char **argv)
{
    fstream input;
    int n;
    input.open(argv[1], fstream::in);
    input >> n;
    for(int i = 1; i<=n; i++)
    {   
        int R, C, M;
        input >> R >> C >> M;
        cout << "Case #" << i << ":" << endl;
        int toclear = R*C-M;
        int clearspace = 1;
        char **grid = new char*[C];
        for(int j = 0; j<C; j++)
        {
            grid[j] = new char[R];
            for(int k = 0; k<R; k++)
                grid[j][k] = '*';
        }
        grid[0][0] = 'c';
        int compx = 1, compy = 0, x = 1, y = 1;
        while(clearspace < toclear)
        {
            if(toclear-clearspace == 1)
            {
                if(x<C && y<R)
                {
                    clearspace += clear(grid, C, R, x, y);
                    break;
                }
            }
            if(compy < 2 && compy < R)
            {
                clearspace += clear(grid, C, R, 0, compy);
                compy++;
            }
            else if(compx < C)
            {
                clearspace += clear(grid, C, R, compx, 0);
                compx++;
            }
            else if(compy < R-1)
            {
                clearspace += clear(grid, C, R, 0, compy);
                compy++;
            }
            else
            {
                clearspace += clear(grid, C, R, x, y);
                x++;
                if(x == C-1)
                {
                    y++;
                    x = 1;
                }
            }
        }

        if(clearspace == toclear)
        {
            for(int j = 0; j<R; j++)
            {
                for(int k = 0; k<C; k++)
                    cout << grid[k][j];
                cout << endl;
            }
        }
        else
            cout << "Impossible" << endl;
        for(int j = 0; j<C; j++)
            delete grid[j];
        delete grid;
    }
}
