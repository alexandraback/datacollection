#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream lire("input.in", ios::in);
ofstream ecrire("output.txt", ios::out);

long long int pgcd(long long int a, long long int b)
{
    return a % b == 0 ? b : pgcd(b, a % b);
}

int main()
{
    int T;
    lire >> T;
    for (int t = 1; t <= T; t++)
    {
        long long int P, Q;
        long long int d = 2;
        char a;
        lire >> P >> a >> Q;
        long long int A = P, B = Q;
        long long int C = pgcd(B,A);
        P /= C;
        Q /= C;
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
