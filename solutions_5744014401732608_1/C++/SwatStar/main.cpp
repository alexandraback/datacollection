#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int64_t i, j, k, T, B, M, array[70], matrix[50][50], temp, last, power_check = 1;
    ifstream filin;
    ofstream filout;
    filin.open ("input.txt");
    filout.open ("output.txt");
    filin >> T;
    for (i = 0; i < T; i++)
    {
        cout << i + 1 << endl;
        filin >> B >> M;
        power_check = 1;
        for (j = 0; (j < B - 2) && (power_check < M); j++)
        {
            power_check *= 2;
        }
        if (power_check >= M)
        {
        for (j = 0; j < 60; j++)
            array[j] = 0;
        temp = M;
        for (j = 0; j < 50; j++)
        {
            for (k = 0; k < 50; k++)
            {
                matrix[j][k] = 0;
            }
        }
        for (j = 0; temp != 0; j++)
        {
            array[j] = temp % 2;
            temp /= 2;
        }
        last = j;
        if (last != B - 1)
        {
            for (j = 0; j < 70; j++)
            {
                if (array[j] == 1)
                {
                    matrix[j + 1][B - 1] = 1;
                }
            }
            for (j = 0; j < last; j++)
            {
                for (k = j + 1; k < last + 1; k++)
                {
                    matrix[j][k] = 1;
                }
            }
        }
        else
        {
            for (j = 0; j < B; j++)
            {
                for (k = j + 1; k < B; k++)
                {
                    matrix[j][k] = 1;
                }
            }
        }
        filout << "Case #" << i + 1 << ": POSSIBLE\n";
        for (j = 0; j < B; j++)
        {
            for (k = 0; k < B; k++)
            {
                filout << matrix[j][k];
            }
            filout << "\n";
        }
        }
        else
        {
            filout << "Case #" << i + 1 << ": IMPOSSIBLE\n";
        }
    }
    filin.close ();
    filout.close ();
    return 0;
}
