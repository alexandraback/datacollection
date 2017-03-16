# /*
this_md5="$(md5sum < "$0" | cut -d' ' -f1)"
last_md5="$(readelf -p SOURCE_FILE_HASH "${0%.cpp}" 2>/dev/null | awk '/\[ *0\]/ { print $3 }')"
if [ "$this_md5" != "$last_md5" ]; then
g++ -pipe -Wall -Wextra -std=c++0x -g -march=native -O3 -DTHIS_MD5="\"$this_md5\"" -o "${0%.cpp}" "$0" ||
exit 1
fi
exec "${0%.cpp}" "$@"
exit 1
# */
#ifndef THIS_MD5
#  define THIS_MD5 "not set"
#endif
char MD5[] __attribute__((section ("SOURCE_FILE_HASH"))) = THIS_MD5;

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
  unsigned nbCases;
  cin >> nbCases;
  for( unsigned noCase = 1 ; noCase <= nbCases ; noCase++ )
    {
      unsigned nbClasses;
      cin >> nbClasses;
      vector< vector< unsigned > > edges;
      for( unsigned i = 0 ; i < nbClasses ; i++ )
        {
          edges.push_back( vector< unsigned >() );
          unsigned nbParents;
          cin >> nbParents;
          for( unsigned j = 0 ; j < nbParents ; j++ )
            {
              unsigned parent;
              cin >> parent;
              edges[i].push_back( parent-1 );
            }
        }

      bool isDiamond = false;
      for( unsigned s = 0 ; s < nbClasses && !isDiamond ; s++ )
        {
          vector< bool > visited( edges.size(), false );
          stack< unsigned > st;
          st.push( s );

          while( !st.empty() )
            {
              unsigned i = st.top(); st.pop();
              if( visited[i] )
                {
                  isDiamond = true;
                  break;
                }
              else
                visited[i] = true;

              for( unsigned j = 0 ; j < edges[i].size() ; j++ )
                st.push( edges[i][j] );
            }
        }
      cout << "Case #" << noCase << ": " << ( isDiamond ? "Yes" : "No" ) << endl;
    }
  return EXIT_SUCCESS;
}
