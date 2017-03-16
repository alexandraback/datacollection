#include <iostream>
#include <fstream>

using namespace std;

std::ifstream fin("input.in");
std::ofstream fout("output.out");


int main()
{
    int num, i, j, ans, n, z, x;
    int a [2510];

    fin >> num;
    for (i=0; i<num; i++)
    {
        fin >> n;
        for (j=0; j<2510; j++) a[j] = 0;
        for (j=0; j<2*n-1; j++)
        {
            for (z=0; z<n; z++)
            {
                fin >> x;
                a[x]++;
            }
        }
        fout << "Case #" << i + 1 << ": ";
        for (j=0; j<2510; j++) if (a[j] % 2!=0) fout << j << " ";
        fout << endl;
    }
    return 0;
}
