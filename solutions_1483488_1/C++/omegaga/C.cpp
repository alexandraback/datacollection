#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int t;
    ifstream infile;
    infile.open( "xx.in" );
    ofstream outfile;
    outfile.open( "xx.out" );
    infile>>t;
    for ( int z = 0; z < t; z++ ){
        int a, b;
        infile>>a>>b;
        int ans = 0;
        for ( int i = a; i <=b; i++ ){
            int num[ 20 ] = { 0 };
            int tmp = i, top = 0;
            while ( tmp != 0 ){
                num[ top++ ] = tmp % 10;
                tmp /= 10;
            }
            int rep[ 10 ] = { 0 };
            for ( int j = 0; j < top; j++ )
                num[ top + j ] = num[ j ];
            for ( int j = 1; j < top; j++ ){
                int newn = 0;
                if ( num[ top + j - 1 ] == 0 ) continue;
                for ( int k = top + j - 1; k >= j; k-- )
                    newn = newn * 10 + num[ k ];
                bool flag = false;
                for ( int k = 1; k <= j - 1; k++ )
                    if ( newn == rep[ k ] ) flag = true;
                if ( flag ) continue;
                rep[ j ] = newn;
                if ( newn != i && newn >= a && newn <= b ) ans++;
            }

        }

        ans /= 2;
        outfile<<"Case #"<<z + 1<<": "<<ans<<endl;


    }
    return 0;

}
