#include <bits/stdc++.h>
#include <QtCore>

using namespace std;

inline long long gcd (long long a, long long b)
{
    while (b)
    {
        a %= b;
        swap (a,b);
    }
    return a;
}

long long mas [32];

int main ()
{
    ios_base::sync_with_stdio(false);
    ifstream cin ("/home/misha/A-small-attempt0.in");
    ofstream cout ("/home/misha/OuTtT");
    mas[0] = 1;
    for (int i = 1; i < 32; ++i)
    {
        mas[i] = mas[i - 1] * 2;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        long long a,b;
        cin >> a;
        cin.clear();
        cin.get();
        cin >> b;
        long long temp = gcd (a,b);
        a /= temp;
        b /= temp;
        bool ok = false;
        for (int j = 0; j < 32; ++j)
        {
            if (b == mas[j])
                ok = true;
        }
        if (!ok || (a == 0))
        {
            cout << "impossible" << endl;
            continue;
        }

        for (int j = 0; j < 32; ++j)
        {
            if (static_cast <double> (a) / b >= 1.0 / mas[j])
            {
                cout << j << endl;
                break;
            }
        }

    }
}
