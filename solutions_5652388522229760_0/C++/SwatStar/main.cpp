#include <iostream>
#include <fstream>
#include <inttypes.h>

using namespace std;

int main()
{
    uint64_t cases, N, i, j, temp, digit[10], init;
    ifstream fin;
    ofstream fout;
    fin.open ("input.txt");
    fout.open ("output.txt");
    fin >> cases;
    for (i = 0; i < cases; i++)
    {
        for (j = 0; j < 10; j++)
            digit[j] = 10;
        fin >> N;
        init = N;
        if (N == 0)
            fout << "Case #" << i + 1 << ": INSOMNIA" << endl;
        else
        {
            for (;;)
            {
                temp = N;
                for (;;)
                {
                    if (temp == 0)
                        break;
                    digit [temp % 10] = temp % 10;
                    temp /= 10;
                }
                for (j = 0; j < 10; j++)
                {
                    if (digit[j] != j)
                        break;
                }
                if (j == 10)
                {
                    fout << "Case #" << i + 1 << ": " << N << endl;
                    break;
                }
                N += init;
            }
        }
    }
    fin.close ();
    fout.close ();
    return 0;
}
