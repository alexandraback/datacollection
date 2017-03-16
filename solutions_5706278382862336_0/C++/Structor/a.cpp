#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

uint64_t gcd(uint64_t a, uint64_t b)
{
    while (b)
    {
        uint64_t t = b;
        b = a % t;
        a = t;
    }
    return a;
}

bool ispow2(uint64_t n)
{
    while (n != 1)
    {
        if (n & 1)
            return false;
        n /= 2;
    }
    return true;
}

void solve()
{
    string s;
    cin >> s;
    size_t pos = s.find('/');
    istringstream snon(s.substr(0, pos));
    istringstream sden(s.substr(pos + 1));

    uint64_t nom;
    uint64_t den;
    snon >> nom;
    sden >> den;

    uint64_t d = gcd(nom, den);
    nom /= d;
    den /= d;

    if (den == 1)
    {
        cout << "1" << endl;
        return;
    }

    if (!ispow2(den))
    {
        cout << "impossible" << endl;
        return;
    }

    int gen = 0;
    while (nom < den)
    {
        nom *= 2;
        ++gen;
    }
    cout << gen << endl;
}


int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}