# /*
this_md5="$(md5sum < "$0" | cut -d' ' -f1)"
last_md5="$(readelf -p SOURCE_FILE_HASH "${0%.cpp}" 2>/dev/null | awk '/\[ *0\]/ { print $3 }')"
[ "$this_md5" != "$last_md5" ] && (
g++-4.7 -pipe -std=c++0x -Wall -Wextra -g -O2 -DTHIS_MD5="\"$this_md5\"" -o "${0%.cpp}" "$0" ||
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
#include <cassert>
#include <algorithm>

using namespace std;

int main()
{
  // googlerese                        "abcdefghijklmnopqrstuvwxyz"
  constexpr char reverseGooglerese[] = "yhesocvxduiglbkrztnwjpfmaq";

  unsigned nbCases;
  cin >> nbCases;
  assert( cin.get() == '\n' );
  for( unsigned noCase = 1 ; noCase <= nbCases ; noCase++ )
    {
      string googlerese;
      getline( cin, googlerese );
      string clear( googlerese.size(), '!' );
      transform( googlerese.begin(),
                 googlerese.end(),
                 clear.begin(),
                 []( char i )
                 {
                   if( i == ' ' )
                     return ' ';
                   else if( i >= 'a' && i <= 'z' )
                     return reverseGooglerese[ i - 'a' ];
                   else
                     return '?';
                 } );
      cout << "Case #" << noCase << ": " << clear << endl;
    }
  return EXIT_SUCCESS;
}
