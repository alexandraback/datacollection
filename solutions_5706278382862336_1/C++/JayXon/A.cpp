#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdint>

using namespace std;

bool IsPowerOf2(uint64_t n)
{
    if (n == 1)
    {
        return false;
    }
    while (n % 2 == 0)
        n /= 2;
    return n == 1;
}

int solve(uint64_t p, uint64_t q)
{
    if (p == 1)
    {
        return lrint(log2(q));
    }
    if (2 * p > q)
    {
        return 1;
    }
    else
    {
        return 1 + solve(p, q/2);
    }
}

uint64_t gcd(uint64_t n1, uint64_t n2)
{
    uint64_t tmp;
    while (n2 != 0) {
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    char name[256];
    strcpy(name, argv[1]);

    ifstream fin(name);
    name[strlen(name)-2] = 0;
    strcat(name, "out");
    ofstream fout(name);

    if (!fin.is_open() || !fout.is_open())
    {
        return 1;
    }

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t)
    {
        uint64_t p, q, r;
        char c;
        fin >> p >> c >> q;
        bool fail = false;
        uint64_t g;
        while ((g = gcd(p, q)) != 1)
        {
            p /= g;
            q /= g;
        }
        if (!IsPowerOf2(q))
        {
            fail = true;
        }
        else
        {
            r = solve(p, q);
        }

        fout << "Case #" << t1 << ": ";
        if (fail)
        {
            fout << "impossible" << endl;
        }
        else
        {
            fout << r << endl;
        }
        

    }

    return 0;
}