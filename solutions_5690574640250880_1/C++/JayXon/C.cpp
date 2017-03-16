#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool solve(int r, int c, int m, char** grid)
{
    if (r == 1)
    {
        for (int i = 1; i < c - m; ++i)
        {
            grid[0][i] = '.';
        }
        return true;
    }
    int n = r*c - m;
    if (n == 1)
    {
        return true;
    }
    if (r == 2)
    {
        if (n%2 || n == 2)
        {
            return false;
        }
        for (int i = 0; i < n/2; ++i)
        {
            grid[0][i] = '.';
            grid[1][i] = '.';
        }
        return true;
    }
    switch (n)
    {
    case 2:
    case 3:
    case 5:
    case 7:
        return false;
    case 6:
        grid[0][2] = '.';
        grid[1][2] = '.';
    case 4:
        grid[1][0] = '.';
        grid[0][1] = '.';
        grid[1][1] = '.';
        return true;

    default:
        break;
    }
    for (int i = r; i >= 3; --i)
    {
        if (n/i == 1)
        {
            continue;
        }
        if (n%i == 1)
        {
            if (n/i == 2)
            {
                continue;
            }
            for (int j = 0; j < i; ++j)
            {
                for (int k = 0; k < n/i; ++k)
                {
                    grid[j][k] = '.';
                }
            }
            grid[i-1][n/i-1] = '*';
            grid[0][n/i] = '.';
            grid[1][n/i] = '.';
            return true;
        }
        else
        {
            for (int j = 0; j < i; ++j)
            {
                for (int k = 0; k < n/i; ++k)
                {
                    grid[j][k] = '.';
                }
            }
            for (int j = 0; j < n%i; ++j)
            {
                grid[j][n/i] = '.';
            }
            return true;
        }
    }
    return false;

}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    char name[256];
    strcpy(name, argv[1]);

    ifstream fin(name);
    name[strlen(name)-2] = 0;
    strcat(name, "out");
    ofstream fout(name);

    if (!fin.is_open() || !fout.is_open())
    {
        return 1;
    }

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t)
    {
        int r, c, m;
        fin >> r >> c >> m;
        bool is_impossible = false, is_switched = false;
        if (r > c)
        {
            int temp = r;
            r = c;
            c = temp;
            is_switched = true;
        }
        char **grid = new char*[r];
        for (int i = 0; i < r; ++i)
        {
            grid[i] = new char[c];
            for (int j = 0; j < c; ++j)
            {
                grid[i][j] = '*';
            }
        }
        is_impossible = !solve(r, c, m, grid);

        fout << "Case #" << t1 << ": " << endl;
        if (is_impossible)
        {
            fout << "Impossible" << endl;
        }
        else
        {
            grid[0][0] = 'c';
            if (is_switched)
            {
                for (int i = 0; i < c; ++i)
                {
                    for (int j = 0; j < r; ++j)
                    {
                        fout << grid[j][i];
                    }
                    fout << endl;
                }
            }
            else
            {
                for (int i = 0; i < r; ++i)
                {
                    for (int j = 0; j < c; ++j)
                    {
                        fout << grid[i][j];
                    }
                    fout << endl;
                }
            }
        }

        for (int i = 0; i < r; ++i)
        {
            delete[] grid[i];
        }
        delete[] grid;

    }

    return 0;
}