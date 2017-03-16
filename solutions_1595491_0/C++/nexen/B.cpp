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

using namespace std;

int main()
{
  unsigned nbCases;
  cin >> nbCases;
  for( unsigned noCase = 1 ; noCase <= nbCases ; noCase++ )
    {
      unsigned nbGooglers, s, p;
      cin >> nbGooglers >> s >> p;
      unsigned n = 0;
      while( nbGooglers-- )
        {
          unsigned t;
          cin >> t;
          switch( t % 3 )
            {
            case 0:
              if( t / 3 >= p )
                n++;
              else if( s && t >= 3 && t / 3 + 1 >= p )
                n++, s--;
              break;
            case 1:
              if( t / 3 + 1 >= p )
                n++;
              break;
            case 2:
              if( t / 3 + 1 >= p )
                n++;
              else if( s && t / 3 + 2 >= p )
                n++, s--;
              break;
            }
        }
      cout << "Case #" << noCase << ": " << n << endl;
    }
  return EXIT_SUCCESS;
}
