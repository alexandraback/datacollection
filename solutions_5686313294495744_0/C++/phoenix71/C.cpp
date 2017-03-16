#include <bits/stdc++.h>
using namespace std ;

map < string , int > ck , gk ;
string c[1005], g[1005] ;

int main()
{
    freopen("C-s.txt", "r" , stdin ) ;
    freopen("ansCs.txt", "w+" , stdout ) ;
    int t , cse = 0 ;
    cin >> t ;
    while(t-- )
    {

        ck.clear() ;
        gk.clear() ;
        int n , ans = 0 ;
        cin >> n ;
        for( int i = 0 ; i < n ; i++ )
        {
            cin >> c[i] >> g[i] ;
            ck[c[i]]++ ;
            gk[g[i]]++ ;
        }

        for( int i = 0 ; i < n ; i++ )
        {
            if( ck[c[i]] > 1 && gk[g[i]] > 1 )
            {
                ans++ ;
                ck[c[i]]-- ;
                gk[g[i]]-- ;
            }
        }
        cout << "Case #"<<++cse<< ": "<< ans << endl  ;

    }



return 0 ;
}
