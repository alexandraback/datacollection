#include <iostream>
#include <set>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

long long pgcd(long long a, long long b)
{
    if (a < b)
        return pgcd(b,a);
    if (b == 0)
        return a;
    else
        return pgcd(b, a%b);
}


int main()
{
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
    long long num, denom;
    int nbT;
    cin >> nbT;
    for (int t = 1; t <= nbT; t++)
    {
        cin >> num;
        cin.get();
        cin >> denom;

        long long pgcdFrac = pgcd(num, denom);
        long long numBis = num/pgcdFrac, denomBis = denom/pgcdFrac;

        long long coeff = 1<<20;
        coeff *= 1<<20;
        if (coeff%denomBis != 0)
            cout << "Case #" << t << ": impossible" << '\n';
        else
        {
            long long cool = numBis * (coeff/denomBis);
            int rep = 0;
            long long puiss2 = 1;
            while (puiss2 <= cool)
            {
                rep++;
                puiss2*=2;
            }

            cout << "Case #" << t << ": " << 41-rep << '\n';
        }



    }
    return 0;
}
