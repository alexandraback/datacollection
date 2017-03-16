#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("test.in");
ofstream fout("test.out");

bool solve(int n, int m, int x)
{
    if (n < m)
        swap(n,m);

    if (n*m % x != 0)
        return 0;

    int mid = x/2;
    if (x&1)
        ++mid;

    if (n < x)
        return 0;
    if (m < mid)
        return 0;

    if (x <= 3)
        return 1;

    if (x == 4)
    {
        if (m == mid)
            return 0;
        else return 1;
    }
    else
    {
        if (m > mid)
            return 1;
        else if (m == x/2)
            return 0;
        else
            return 1;
    }
}

int main()
{
    int test;

    fin >> test;

    for (int k = 1; k <= test; ++k)
    {
        int n,m,x;
        fin >> x >> n >> m;
        bool ok = solve(n,m,x);

        fout << "Case #" << k << ": ";

        if(ok)
            fout << "GABRIEL\n";
        else fout << "RICHARD\n";
    }
}
