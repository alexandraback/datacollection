#include <iostream>
#include <fstream>
#include <inttypes.h>

using namespace std;

uint64_t min (uint64_t a, uint64_t b)
{
    if (a < b)
        return a;
    else
        return b;
}

uint64_t pow (uint64_t base, uint64_t exponent)
{
    uint64_t result = 1, i;
    for (i = 0; i < exponent; i++)
        result *= base;
    return result;
}

int main()
{
    uint64_t cases, i, j, k, K, C, S, number, to_print;
    ifstream fin;
    fin.open ("input.txt");
    ofstream fout;
    fout.open ("output.txt");
    fin >> cases;
    for (i = 0; i < cases; i++)
    {
        fout << "Case #" << i + 1 << ":";
        fin >> K >> C >> S;
        if (C * S < K)
            fout << " IMPOSSIBLE";
        else
        {
            number = ((K - 1) / C) + 1;
            for  (j = 0; j < number; j++)
            {
                fout << " ";
                to_print = 0;
                for (k = 0; k < C; k++)
                {
                    to_print += pow(K, C - 1 -  k) * min(((number * k) + j), (K - 1));
                }
                fout << to_print + 1;
            }
        }
        fout << endl;
    }
    fin.close ();
    fout.close ();
    return 0;
}
