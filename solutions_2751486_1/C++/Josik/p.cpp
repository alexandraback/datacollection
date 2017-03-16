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

typedef unsigned long long ull;

ull res, tmp;
string s;
int n, cnt;

bool isVow ( char c )
{
  return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ); 
}

int main ( int argc, char * argv [] )
{
  int cases;
  cin >> cases;
  for ( int z = 1; z <= cases; z++ )
  {
    cin >> s >> n;
    res = cnt = 0;
    int len = s . length();
    int from = 0, pos = 0;
    for ( int i = 0; i < len; i++ )
    {
      if ( ! isVow( s[ i ] ) )
      {
        if ( ! cnt++ ) pos = i;
        if ( cnt == n )
        {
          tmp = ( pos - from + 1 );
          tmp *= ( len - i );
          res += tmp;
          from = pos + 1;
          if ( pos < from ) pos = from;
          --cnt;
        }
      }
      else cnt = 0;
    }
    
    cout << "Case #" << z << ": " << res << endl;
  }
  
  return 0;
}