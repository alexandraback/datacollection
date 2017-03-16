#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <string.h>
#include <iomanip>

using namespace std;

const int S = 50;

int f[S][S];
char t[S][S];
int g_r;
int g_c;

int func3(int r, int c)
{
    if (t[r][c] == '*')
    {
        return (1);
    }
    return (0);
}

bool func2(int r, int c)
{
    int ret = 0;

    if (func3(r, c)) { return (true); }

    if (r - 1 >= 0)
    {
        if (c - 1 >= 0)
        {
            if (func3(r - 1, c - 1)) { return (true); }
        }
        if (func3(r - 1, c)) { return (true); }
        if (c + 1 < g_c)
        {
            if (func3(r - 1, c + 1)) { return (true); }
        }
    }

    if (r + 1 < g_r)
    {
        if (c - 1 >= 0)
        {
            if (func3(r + 1, c - 1)) { return (true); }
        }
        if (func3(r + 1, c)) { return (true); }
        if (c + 1 < g_c)
        {
            if (func3(r + 1, c + 1)) { return (true); }
        }
    }

    if (c - 1 >= 0)
    {
        if (func3(r, c - 1)) { return (true); }
    }

    if (c + 1 < g_c)
    {
        if (func3(r, c + 1)) { return (true); }
    }

    return (false);
}

void func(int r, int c)
{
    if (f[r][c] == 0)
    {
        return;
    }

    f[r][c] = 0;

    if (func2(r, c))
    {
        return;
    }

    if (r - 1 >= 0)
    {
        if (c - 1 >= 0)
        {
            func(r - 1, c - 1);
        }
        func(r - 1, c);
        if (c + 1 < g_c)
        {
            func(r - 1, c + 1);
        }
    }

    if (r + 1 < g_r)
    {
        if (c - 1 >= 0)
        {
            func(r + 1, c - 1);
        }
        func(r + 1, c);
        if (c + 1 < g_c)
        {
            func(r + 1, c + 1);
        }
    }

    if (c - 1 >= 0)
    {
        func(r, c - 1);
    }

    if (c + 1 < g_c)
    {
        func(r, c + 1);
    }

}

int main(int argc, const char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Error:%d\n", __LINE__);
        return -1;
    }

    ifstream fin(argv[1]);
    ofstream fout("out.txt");

    int T;
    fin >> T;
    for (int j = 0; j < T; j++)
    {
        int r, c, m;
        fin >> r >> c >> m;
        g_r = r;
        g_c = c;

        for (int i = 0; i < S; i++)
        {
            for (int k = 0; k < S; k++)
            {
                t[i][k] = '.'; 
                f[i][k] = -1;
            }
        }
        t[0][0] = 'c';

        int rr = r;
        int cc = c;
        int mm = m;
        while (mm != 0)
        {
            if (rr <= cc)
            {
                if (mm >= rr)
                {
                    for (int i = 0; i < rr; i++)
                    {
                        t[rr - 1 - i][cc - 1] = '*';
                    }
                    mm -= rr;
                }
                else if (mm == rr - 1)
                {
                    for (int i = 0; i < rr && mm != 0; i++)
                    {
                        t[rr - 1 - i][cc - 1] = '*';
                        mm--;
                    }
                    t[1][cc - 1] = '.';
                    t[rr - 1][cc - 2] = '*';
                }
                else
                {
                    for (int i = 0; i < rr && mm != 0; i++)
                    {
                        t[rr - 1 - i][cc - 1] = '*';
                        mm--;
                    }
                }
                cc--;
            }
            else
            {
                if (mm >= cc)
                {
                    for (int i = 0; i < cc; i++)
                    {
                        t[rr - 1][cc - 1 - i] = '*';
                    }
                    mm -= cc;
                }
                else if (mm == cc - 1)
                {
                    for (int i = 0; i < cc && mm != 0; i++)
                    {
                        t[rr - 1][cc - 1 - i] = '*';
                        mm--;
                    }
                    t[rr - 1][1] = '.';
                    t[rr - 2][cc - 1] = '*';
                }
                else
                {
                    for (int i = 0; i < cc && mm != 0; i++)
                    {
                        t[rr - 1][cc - 1 - i] = '*';
                        mm--;
                    }
                }
                rr--;
            }
        }

        func(0, 0);
        bool flag = false;
        for (int i = 0; i < r; i++)
        {
            for (int k = 0; k < c; k++)
            {
                if ((f[i][k] == -1) && (t[i][k] == '.'))
                {
                    flag = true;
                }
            }
        }

        fout << "Case #" << j+1 << ":" << endl;

        if (flag == true)
        {
            fout << "Impossible" << endl;
        }
        else
        {
            for (int i = 0; i < r; i++)
            {
                for (int k = 0; k < c; k++)
                {
                    fout << t[i][k]; 
                }
                fout << endl;
            }
        }
    }

    return (0);
}
