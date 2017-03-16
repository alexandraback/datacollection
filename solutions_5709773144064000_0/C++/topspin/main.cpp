#include <stdio.h>
#include <iostream>
#include <fstream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt", ios::in);
    ofstream fout("output.txt", ios::out);
    fout.precision(20);

    int T;
    double c, f, x;
    fin >> T;
    for (int it = 0; it < T; it++)
    {
        fin >> c >> f >> x;
        fout << "Case #" << it + 1 << ": ";
        double alpha = 2;
        double time = 0;
        while (c * alpha + c * f < x * f)
        {
            time += c / alpha;
            alpha += f;
        }
        time += x / alpha;
        fout << time << endl;

    }

    fin.close();
    fout.close();

    return 0;
}
