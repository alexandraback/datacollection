#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int t;
    ifstream infile;
    ofstream outfile;
    infile.open( "xx.in" );
    outfile.open( "xx.out" );
    infile>>t;
    for ( int z = 0; z < t; z++ ){

        int n, s, p, ans = 0;
        infile>>n>>s>>p;
        int a[ 100 ], b[ 100 ];
        for ( int i = 0; i < n; i++ ){
            infile>>a[ i ];
            b[ i ] = ( a[ i ] + 2 ) / 3;
            if ( b[ i ] >= p ) ans++;
            if ( a[ i ] != 0 && b[ i ] == p - 1 && a[ i ] % 3 != 1 && s > 0 ){
                s--;
                ans++;
            }
        }
        outfile<<"Case #"<<z+1<<": "<<ans<<endl;
    }
    return 0;
}
