# /*
this_md5="$(md5sum < "$0" | cut -d' ' -f1)"
last_md5="$(readelf -p SOURCE_FILE_HASH "${0%.cpp}" 2>/dev/null | awk '/\[ *0\]/ { print $3 }')"
[ "$this_md5" != "$last_md5" ] && (
g++ -pipe -Wall -Wextra -g -O2 -DTHIS_MD5="\"$this_md5\"" -o "${0%.cpp}" "$0" ||
exit 1 )
exec "${0%.cpp}" "$@"
exit 1
# */
#ifndef THIS_MD5
#define THIS_MD5 "not set"
#endif
char MD5[] __attribute__((section ("SOURCE_FILE_HASH"))) = THIS_MD5;

#include <cstdlib>
#include <iostream>
#include <set>

using namespace std;

namespace
{
  void next_number( string &n )
  {
    unsigned i = n.size();
    while( i-- )
      {
        if( n[i] == '9' )
          n[i] = '0';
        else
          {
            n[i]++;
            break;
          }
      }
  }
}

int main()
{
  unsigned nbCases;
  cin >> nbCases;
  for( unsigned noCase = 1 ; noCase <= nbCases ; noCase++ )
    {
      string a, b;
      cin >> a >> b;
      unsigned res = 0;
      for( string n = a ; n < b ; next_number( n ) )
        {
          string nn = n + n;
          set< string > r;
          for( unsigned i = 1 ; i < a.size() ; i++ )
            if( nn.compare( i, a.size(), b ) <= 0 &&
                nn.compare( i, a.size(), n ) > 0 )
              r.insert( string( nn, i, a.size() ) );
          res += r.size();
        }
      cout << "Case #" << noCase << ": " << res << endl;
    }
  return EXIT_SUCCESS;
}
