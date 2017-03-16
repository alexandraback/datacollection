#include <iostream>
#include <algorithm>
using namespace std;

const int size = 1000;
int p[size+10];

int main( ) {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("b.txt","w",stdout);
    int t , n , x , temp , res;
    cin >> t;
    for ( int k = 1 ; k<=t ; ++k ) {
        cin >> n;
        for ( int i = 0 ; i<n ; ++i ) {
            cin >> p[i];
        }
        res = 0x3f3f3f3f;
        sort( p , p+n );
        for ( int i = 1 ; i<=p[n-1] ; ++i ) {
            temp = i;
            for ( int j = n-1 ; j>=0 ; --j ) {
                if ( p[j]>i ) {
                    temp += p[j] / i;
                    if ( p[j]%i==0 ) {
                    	-- temp;
					}
                }
            }
            res = min( temp , res );
        }
        cout << "Case #" << k << ": " << res << endl;
    }
    return 0;
}

