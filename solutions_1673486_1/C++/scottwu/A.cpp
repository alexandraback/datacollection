#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
ifstream fin ("blah.in");
ofstream fout ("blah.out");

int main()
{
    fout << fixed << setprecision (7);
    int ntest; fin >> ntest;
    for (int test = 0; test < ntest; test++)
    {
        int a, b; fin >> a >> b;
        double prob[100100];
        for (int i = 0; i < a; i++)
            fin >> prob[i];
        double best = b + 2.0;
        double p = 1.0;
        for (int i = 0; i <= a; i++)
        {
            double val = a - i + b - i + 1;
            val += (1 - p) * ((double) b + 1.0);
            best = min (best, val);
            if (i < a) p *= prob[i];
        }
        fout << "Case #" << test + 1 << ": " << best << "\n";
    }
    //system ("Pause");
    return 0;
}
