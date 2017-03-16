#include <stdio.h>
#include <fstream>
#include <fstream>

using namespace std;

char a[50][50];

int main()
{
    ifstream fin("input.txt", ios::in);
    ofstream fout("output.txt", ios::out);

    int T, m, r, c;
    fin >> T;
    for (int it = 0; it < T; it++)
    {
        fin >> r >> c >> m;
        fout << "Case #" << it + 1 << ":" << endl;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                a[i][j] = '*';
        if (r == 1 || c == 1 || m == r * c - 1)
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                    if (!i && !j)
                    {
                        fout << 'c';
                        m++;
                    }
                    else if (m < r * c)
                    {
                        fout << '.';
                        m++;
                    } else
                        fout << '*';
                    fout << endl;
            }
        } else if (r == 2 || c == 2)
        {
            if (m % 2 || m == r * c - 2)
                fout << "Impossible" << endl;
            else
            {
                if (r == 2)
                {
                    a[0][0] = 'c';
                    a[1][0] = '.';
                    for (int i = 0; i < (r * c - m) / 2 - 1; i++)
                    {
                        a[0][i + 1] = '.';
                        a[1][i + 1] = '.';
                    }
                } else
                {
                    a[0][0] = 'c';
                    a[0][1] = '.';
                    for (int i = 0; i < (r * c - m) / 2 - 1; i++)
                    {
                        a[i + 1][0] = '.';
                        a[i + 1][1] = '.';
                    }
                }
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                        fout << a[i][j];
                    fout << endl;
                }
            }
        } else
        {
            if (m > r * c - 4 || m == r * c - 5 || m == r * c - 7)
            {
                fout << "Impossible" << endl;
                continue;
            }
            for (int i = 0; i < min(c, (r * c - m) / 2); i++)
            {
                a[0][i] = '.';
                a[1][i] = '.';
            }
            if (c >= (r * c - m) / 2)
            {
                if ((r * c - m) % 2)
                {
                    a[2][0] = '.';
                    a[2][1] = '.';
                    a[2][2] = '.';
                    a[0][(r * c - m) / 2 - 1] = '*';
                    a[1][(r * c - m) / 2 - 1] = '*';
                }
            } else
            {
                m += 2 * c;
                int lasti = 1;
                for (int i = 2; i < r; i++)
                    for (int j = 0; j < c; j++)
                        if (m < r * c)
                        {
                            m++;
                            a[i][j] = '.';
                            lasti = i;
                        }
                if (a[lasti][0] == '.' && a[lasti][1] == '*')
                {
                    a[lasti][1] = '.';
                    a[lasti - 1][c - 1] = '*';
                }
            }
            a[0][0] = 'c';
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                    fout << a[i][j];
                fout << endl;
            }
        }

    }

    fin.close();
    fout.close();

    return 0;
}
