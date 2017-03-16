#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    int testCase;
    ifstream fi;
    ofstream fo;
    fi.open( "A.in" );
    fo.open( "A.out" );
    fi>>testCase;
    for ( int z = 1; z <= testCase; z++ ){
        int n;
        fi>>n;
        int sum = 0, a[ 1000 ];
        for ( int i = 0; i < n; i++ ){
            fi>>a[ i ];
            sum += a[ i ];
        }
        double k = (double)( sum + sum ) / n;
        int nn = n, sum2 = sum;
        bool flag[ 1000 ] = { 0 }, re;
        for ( int i = 0; i < n; i++ )
            if ( ( k - a[ i ] ) < 0 ){ flag[ i ] = true;
                re = true;
                nn--;
                sum2 -= a[ i ];
            }
        cout<<"nn="<<nn<<endl;
        cout<<"sum2="<<sum2<<endl;
        k = (double)( sum + sum2 ) / nn;
        cout<<"k="<<k<<endl;
        fo<<"Case #"<<z<<':';
        for ( int i = 0; i < n; i++ ){
            double ans = (double )( k - a[ i ] )/ (double )sum * 100;
            if ( ans < 0.0 ) ans = 0;
            fo<<fixed<<setprecision(6)<<' '<<ans;
        }
        fo<<endl;
        
    }
    return 0;
}
