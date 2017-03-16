#include<iostream>
using namespace std;

int t;
int ar[100][100];
int m, n;
int main()
{
    cin>>t;
    int tt = 1;
    while( tt <= t )
    {
           cin>>m>>n;
           for(int i = 0; i < m; ++i )
           for(int j = 0 ;j < n ; ++j )
                   cin>>ar[i][j];
           bool done = false;
           for(int i = 0; i < m; ++i )
           for(int j = 0; j < n; ++j )
           {
            bool res = true;
            for( int k = 0; k < m && res; ++k )
                 if( ar[k][j] > ar[i][j] )
                     res = false;
            if( res == false )
            {
                res = true;
                for( int k = 0; k < n && res; ++k )
                if( ar[i][k] > ar[i][j] )
                res = false;
            }
            if( !res )
              cout<< "Case #" << tt << ": NO\n", done = true, i = j = m+n;
            
           }
           if(!done )
           cout<< "Case #" << tt << ": YES\n";
           tt++;
    }
    return 0;
}
