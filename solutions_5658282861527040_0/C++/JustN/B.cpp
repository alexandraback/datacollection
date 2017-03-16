#include <iostream>
#include <cstdio>
using namespace std;

long long GetPower( long long x )
{
    long long res = 1 ;
    while ( res <= x ) res *= 2 ;
    return res / 2 ;
}

long long Solve( long long A , long long B , long long K )
{
    //cout << A << " " << B << " " << K << endl;
    if ( K > min( A , B ) || A == 0 || B == 0 ) return ( A + 1 ) * ( B + 1 );
    long long pow = GetPower( max( A , B ) );

    long long NewA , NewB;
    long long res = 0;

    if ( A >= pow ) NewA = pow - 1 ;
    else NewA = A;

    if ( B >= pow ) NewB = pow - 1 ;
    else NewB = B;

    if ( pow > K )
    {
        res += Solve( NewA , NewB , K );
        if ( A >= pow ) res += Solve( A - pow , NewB , K );
        if ( B >= pow ) res += Solve( NewA , B - pow , K );
    }
    else
    {
        res += ( pow * pow ) + ( pow * ( A - pow + 1 ) ) + ( pow * ( B - pow + 1 ) );
        res += Solve( A - pow , B - pow , K - pow );
    }

    return res;

}

int main()
{
    freopen("input.in" , "r" , stdin );
    freopen("output.out" , "w" , stdout );

    int T;
    cin >> T;

    for ( int t = 1 ; t <= T ; t++ )
    {
        long long A , B , K ;
        cin >> A >> B >> K ;
        A--; B--; K--;
        cout << "Case #" << t << ": " << Solve( A , B , K ) << endl;
    }

    return 0;
}
