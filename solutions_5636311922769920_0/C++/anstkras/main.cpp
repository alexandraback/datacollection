#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        int k, c, s;
        fin >> k >> c >> s;
        fout << "Case #" << i + 1 << ": ";
        for (int j = 1; j <= k; j++)
            fout << j << " ";
        fout << '\n';
    }

    return 0;
}

