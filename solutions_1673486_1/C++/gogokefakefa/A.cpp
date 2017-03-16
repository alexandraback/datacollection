#include <cstdio>
#include <algorithm>

using namespace std;

double p[1 << 20];
int N, M;


void scan(){
    scanf ( "%d%d", &N, &M );

    for ( int i = 0; i < N; ++i )
        scanf ( "%lf", p + i );
}

void solve(int cs){
    double mn = M + 2;
    double prob = 1.;

    for ( int i = 0; i < N; ++i ){
        prob *= p[i];
        mn = min ( mn, ( M - i - 1 ) + ( N - i  - 1 ) + 1 + ( 1 - prob ) * ( M + 1 ) );
    }

    printf ( "Case #%d: %.6f\n", cs, mn );
}


int main(){

    int tests;

    scanf ( "%d", &tests );


    for ( int i = 0; i < tests; ++i ){
        scan();
        solve(i + 1);
    }
}
