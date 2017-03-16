#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream lire("input.in", ios::in);
ofstream ecrire("output.txt", ios::out);

int main()
{
    int T;
    lire >> T;
    for (int t = 1; t <= T; t++)
    {
        long long int P, Q;
        char a;
        lire >> P >> a >> Q;
        int p = 0;
        while (Q % 2 == 0)
        {
            if (P < Q)
                p++;
            Q /= 2;
        }
        if (P % Q == 0)
            ecrire << "Case #" << t << ": " << p << endl;
        else
            ecrire << "Case #" << t << ": " << "impossible" << endl;
    }
    return 0;
}
