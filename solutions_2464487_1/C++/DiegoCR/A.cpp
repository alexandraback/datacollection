#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

double t, r;

bool ok(double i)
{
    double sum = 0, op ;

    sum += 2.0*r*(i + 1.0);

    if ( sum > t || sum < 0 ) return false;

    sum += 2.0*i*(i + 1.0);

    if ( sum > t || sum < 0 || op < 0 ) return false;

    sum += i + 1.0;

    if ( sum > t || sum < 0 ) return false;

    return true;

}

int main()
{
    freopen ( "Large.in", "r", stdin );
    freopen ( "Large.out", "w", stdout );

    int tc = 0, ntc;

    cin >> ntc;

    while ( ntc -- )
    {
        tc ++;

        cin >> r >> t;

        long long ini = 0, fin = sqrt(t), mit;

        while ( ini <= fin )
        {
            mit = (ini + fin)/2;
            if ( ok(mit) )
                ini = mit + 1;
            else
                fin = mit - 1;
        }

        cout << "Case #" << tc << ": " << ini << endl;
    }
}
