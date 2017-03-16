#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;

int main()
{
    char ans[ 26 ] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };
    ifstream infile;
    ofstream outfile;
    infile.open( "xx.in" );
    outfile.open( "xx.out" );
    char c;
    int n;
    string tmp;
    getline( infile, tmp );
    n = atoi( tmp.c_str() );
    for ( int t = 0; t < n; t++ ){
        string g;
        getline( infile, g );
        outfile<<"Case #"<<t + 1<<": ";
        int l = g.size();
        for ( int i = 0; i < l; i++ )
        {
            c = g[ i ];
            if ( c >= 'a' && c <= 'z' )
                c = ans[ c - 'a' ];
            outfile<<c;
        }
        outfile<<endl;
    }
    return 0;
}
