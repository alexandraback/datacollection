#include <iostream>

using namespace std;

double Solve( double c, double f, double x )
{
    double m = x/2.0, v = 2.0, z = 0.0;
    for ( int i = 0; ; i++ ) {
        z += c/v;
        v += f;
        double f = z + x/v;
        if ( f < m ) {
            m = f;
        } else {
            break;
        }
    }
    return m;
}

int main()
{
    int T = 0;
    cin >> T;
    for ( int t = 1; t <= T; t++ ) {
        double C, F, X;
        cin >> C >> F >> X;
        printf( "Case #%d: %.10f\n", t, Solve(C, F, X) );
    }
    return 0;
}
