#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int pot(int n, int x)
{
    if (x == 0) return 1;
    int z = pot(n, x/2);
    z *= z;
    if (x % 2) return z*n;
    return z;
}

int log(int n)
{
    int exp = 0;
    int x = 1;

    while (n / x >= 10)
    {
        x *= 10;
        ++exp;
    }

    return exp;
}

int main (void)
{
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso)
    {
        int a, b;
        scanf ("%d %d", &a, &b);

        int alg = log(a) + 1;

        int ans = 0;
        for (int n = a; n <= b; ++n)
        {
            set<int> marca;

            for (int i = 1; i < alg; ++i)
            {
                int m = 0;
                m += n / pot(10, i);
                m += (n % pot(10, i)) * pot(10, alg-i);

                if (marca.find(m) != marca.end()) continue;
                marca.insert(m);

                if (n < m && m <= b)
                {
                    ++ans;
                    //printf ("%d %d\n", n, m);
                }
            }
        }

        printf ("Case #%d: %d\n", caso, ans);
    }

    return 0;
}

