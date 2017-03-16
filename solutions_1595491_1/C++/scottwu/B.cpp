#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin ("b.in");
ofstream fout ("b.out");

int main()
{
    int t; fin >> t;
    for (int test = 0; test < t; test++)
    {
        int n, s, p;
        int val[110];
        fin >> n >> s >> p;
        for (int i = 0; i < n; i++)
            fin >> val[i];
        int ng = 0, ns = 0, np = 0;
        for (int i = 0; i < n; i++)
        {
            if (3 * p - 2 <= val[i])
                ng++;
            else if (3 * p - 4 <= val[i] && val[i] < 29 && val[i] > 1)
                ns++;
        }
        fout << "Case #" << test + 1 << ": " << ng + min (ns, s) << "\n";
    }
    return 0;
}
