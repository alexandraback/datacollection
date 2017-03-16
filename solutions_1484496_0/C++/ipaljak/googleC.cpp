#include <cstdio>
#include <fstream>
#include <algorithm>

#define KONJ 42 - 42

FILE *fin = fopen( "Subset.in", "r" );
FILE *fout = fopen( "Subset.out", "w" );

using namespace std;

struct subset{

    int index, sum;

    subset (){}

    subset( int _index, int _sum ){
        index = _index; sum = _sum;
    }

} sume[1 << 21];

int T, N;
int niz[22];

inline bool cmp( const subset &A, const subset &B ){
    return A.sum < B.sum;
}

void print( int x, int y ){

    for ( int i = 0; i < N; ++i ){
        if ( ( x & ( 1 << i ) ) != 0 ) fprintf( fout, "%d ", niz[i] );
    }
    fprintf( fout, "\n" );

    for ( int i = 0; i < N; ++i ){
        if ( ( y & ( 1 << i ) ) != 0 ) fprintf( fout, "%d ", niz[i] );
    }
    fprintf( fout, "\n" );


}

void solve( int t ){

    fprintf( fout, "Case #%d:\n", t );

    fscanf( fin, "%d", &N );
    for ( int i = 0; i < N; ++i ) fscanf( fin, "%d", &niz[i] );

    for ( int i = 0; i < ( 1 << N ); ++i ){
        int sum = 0;
        for ( int j = 0; j < N; ++j ){
            if ( ( i & ( 1 << j ) ) != 0 ) sum += niz[j];
        }
        sume[i] = subset( i, sum );
    }

    int cnt = ( 1 << N );
    sort( sume, sume + cnt, cmp );

    bool found = false;

    for ( int i = 1; i < cnt; ++i ){
        if ( sume[i].sum != sume[i - 1].sum ) continue;
        if ( __builtin_popcount( sume[i].index ) != __builtin_popcount( sume[i - 1].index ) ){
            print( sume[i].index, sume[i - 1].index );
            found = true; break;
        } else {

            int A[22], B[22];
            int cntA = 0, cntB = 0;

            for ( int j = 0; j < N; ++j ){
                if ( ( sume[i].index & ( 1 << j ) ) != 0 ) A[cntA++] = niz[j];
                if ( ( sume[i - 1].index & ( 1 << j ) ) != 0 ) B[cntB++] = niz[j];
            }

            sort ( A, A + cntA );
            sort ( B, B + cntB );

            for ( int j = 0; j < cntA; ++j ){
                if ( A[j] != B[j] ){ found = true; break; }
            }

            if ( found ){
                print( sume[i].index, sume[i - 1].index );
                found = true; break;
            } else {
                continue;
            }

        }
    }

    if ( !found ){ fprintf( fout, "Impossible\n" ); }

}

int main( void ){

    fscanf( fin, "%d", &T );
    for ( int i = 0; i < T; ++i ) solve( i + 1 );

    return KONJ;

}
