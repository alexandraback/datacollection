#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct b
{
    char c;
    int v;
};

struct _less
{
     bool operator() (const int x, const int y) const
        {return x<y;}
};

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int t;
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        fout << "Case #" << i + 1 << ": ";
        int b;
        long long m;
        fin >> b >> m;
        if (m > pow(2, b - 2))
        {
            fout << "IMPOSSIBLE";
            fout << '\n';
        }
        else
        {
            int a[100][100] = {};
            for (int i = 0; i < b - 1; i++)
                for (int j = i + 1; j < b; j++)
                        a[i][j] = 1;
            if (m < (long long)(pow(2, b - 2)))
            {
                a[0][b - 1] = 0;
                for (int j = 1; j < b; j++)
                {
                    if (((1 << (b - 1 - j)) & m) == 0)
                        a[0][j - 1] = 0;
                }
            }
            fout << "POSSIBLE\n";
            for (int i = 0; i < b; i++)
            {
                for (int j = 0; j < b; j++)
                    fout << a[i][j];
                fout << '\n';
            }
        }
    }
    return 0;
}

