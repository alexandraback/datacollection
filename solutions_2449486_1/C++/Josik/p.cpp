#include <algorithm>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int lawn[ 114 ][ 114 ];
int maxRow[ 114 ], maxCol[ 114 ];

int main ( int argc, char * argv [] )
{
  int cases;
  scanf( "%d", &cases );
  for ( int i = 1; i <= cases; i++ )
  {
    memset( maxRow, 0, sizeof( maxRow ) );
    memset( maxCol, 0, sizeof( maxCol ) );
    
    int n, m;
    scanf( "%d%d", &n, &m );
    for ( int j = 0; j < n; j++ )
    {
      for ( int k = 0; k < m; k++ )
      {
        scanf( "%d", &lawn[ j ][ k ] );
        if ( lawn[ j ][ k ] > maxRow[ j ] ) maxRow[ j ] = lawn[ j ][ k ];
        if ( lawn[ j ][ k ] > maxCol[ k ] ) maxCol[ k ] = lawn[ j ][ k ];
      }
    }
    
    bool pos = true;
    for ( int j = 0; j < n; j++ )
    {
      for ( int k = 0; k < m; k++ )
      {
        if ( lawn[ j ][ k ] < maxRow[ j ] && lawn[ j ][ k ] < maxCol[ k ] )
        {
          pos = false;
          break;
        }
      }
    }
    
    printf( "Case #%d: %s\n", i, ( pos ? "YES" : "NO" ) );
  }
  
  return 0;
}