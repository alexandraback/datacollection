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

int act[ 14 ];
int e, r, n;

int bestGain ( int from, int to, int energy )
{
  if ( from == to ) return act[ to ] * energy;
  int max = 0;
  for ( int i = 0; i <= energy; i++ )
  {
    int ne = energy - i + r;
    if ( ne > e ) ne = e;
    int cnt = i * act[ from ] + bestGain( from + 1, to, ne );
    if ( cnt > max && ne >= 0 ) max = cnt;
  }
  return max;
}

int main ( int argc, char * argv [] )
{
  int cases;
  scanf( "%d", &cases );
  for ( int i = 1; i <= cases; i++ )
  {
    scanf( "%d%d%d", &e, &r, &n );
    for ( int j = 1; j <= n; j++ )
    {
      scanf( "%d", &act[ j ] );
    }
    printf( "Case #%d: %d\n", i, bestGain( 1, n, e ) );
  }
  
  return 0;
}