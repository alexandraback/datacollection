#include <cstdio>
#include <fstream>
#include <cmath>
#include <algorithm>

#define KONJ 42 - 42
#define EPS 1E-8

FILE *fin = fopen( "safetyNumbers.in", "r" );
FILE *fout = fopen( "safetyNumbers.out", "w" );

using namespace std;

int T, N, X;
int J[210];

double check( double Y, int ind ){

    double x = ( double ) J[ind] + ( double ) X * Y;
    double sum = 0;

    for ( int i = 0; i < N; ++i ){
        if ( i == ind ) continue;
        double _val = ( ( double ) x - J[i] ) / (double) X;
        if ( _val < 0 ) continue;
        sum += _val;
    }

    return sum >= 1 - Y;


}

double binary( double lo, double hi, int index ){

    while ( abs( hi - lo ) > EPS ){

        double mid = ( hi + lo ) / 2;
        if ( check( mid, index ) ) hi = mid; else lo = mid;

    }

    return lo;

}

void solve( int t ){

    fscanf( fin, "%d", &N ); X = 0;
    for ( int i = 0; i < N; ++i ){ fscanf( fin, "%d", &J[i] ); X += J[i]; }

    fprintf( fout, "Case #%d:", t );
    for ( int i = 0; i < N; ++i ) fprintf( fout, " %.6lf", (double) 100.00 * binary( 0, 1, i ) );
    fprintf( fout, "\n" );

}

int main( void ){

    fscanf( fin, "%d", &T );
    for ( int i = 0; i < T; ++i ) solve( i + 1 );

    return KONJ;

}
