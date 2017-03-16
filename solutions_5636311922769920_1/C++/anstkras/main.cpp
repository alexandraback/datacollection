#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long long mpow(long long a, long long b)
{
    long long ans = 1;
    for (int i = 1; i <= b; i++)
    {
        ans *= a;
    }
    return ans;
}

int main()
{
    int t;
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        long long k, c, s;
        fin >> k >> c >> s;
        if (s < k - 1)
        {
            fout << "Case #" << i + 1 << ": " << "IMPOSSIBLE\n";
            continue;
        }
        if (c == 1)
        {
            fout << "Case #" << i + 1 << ": ";
            if (s != k)
            {
                fout << "IMPOSSIBLE\n";
                continue;
            }
            else
            for (int j = 0; j < k; j++)
                fout << j + 1 << " ";
            fout << '\n';
            continue;
        }
        long long z = mpow(k, c - 1);
        long long zz = z / k;
        fout << "Case #" << i + 1 << ": ";
        if (k == 1)
            fout << 1;
        else

        for (int j = 0; j < k - 1; j++)
            fout << z * (j + 1) + 1 + j * zz << " ";
        fout << '\n';
    }

    return 0;
}

