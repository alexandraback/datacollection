#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

typedef long long unsigned Num;

Num gcd(Num a, Num b)
{
    Num t = a % b;
    while (t > 0)
    {
        a = b;
        b = t;
        t = a % b;
    }
    return b;
}

vector<Num> powers;

int main()
{
    {
        Num t = 1;
        for (size_t i = 0; i <= 40; ++i, t <<= 1)
            powers.push_back(t);
    }

    int t;
    cin >> t;
    for (int qq = 1; qq <= t; ++qq)
    {
        Num p, q;
        char ch;
        cin >> p >> ch >> q;

        Num r = gcd(p, q);
        p /= r;
        q /= r;

        int pi = -1, qi = -1;
        for (size_t i = 0; i < powers.size(); ++i)
        {
            if (q == powers[i]) qi = i;
            if (p >= powers[i]) pi = i;
        }

        cout << "Case #" << qq << ": ";
        if (q < p || pi < 0 || qi < 0)
            cout << "impossible";
        else
            cout << qi - pi;
        cout << endl;
    }
    return 0;
}
