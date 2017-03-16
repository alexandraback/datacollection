# /*
this_md5="$(md5sum < "$0" | cut -d' ' -f1)"
last_md5="$(readelf -p SOURCE_FILE_HASH "${0%.cpp}" 2>/dev/null | awk '/\[ *0\]/ { print $3 }')"
if [ "$this_md5" != "$last_md5" ]; then
g++ -pipe -Wall -Wextra -std=c++0x -g -march=native -O3 -lgmpxx -DTHIS_MD5="\"$this_md5\"" -o "${0%.cpp}" "$0" ||
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
#include <gmpxx.h>

using namespace std;

struct Thing
{
  mpz_class nb;
  unsigned type;
};

struct State
{
  unsigned ai;
  mpz_class ain;
  unsigned bi;
  mpz_class bin;
  mpz_class boxed;
};

int main()
{
  unsigned nbCases;
  cin >> nbCases;
  for( unsigned noCase = 1 ; noCase <= nbCases ; noCase++ )
    {
      unsigned nbBoxes, nbToys;
      cin >> nbBoxes >> nbToys;

      vector< Thing > boxes( nbBoxes ), toys( nbToys );
      for( unsigned i = 0 ; i < nbBoxes ; i++ )
        {
          string nb;
          cin >> nb >> boxes[i].type;
          boxes[i].nb = mpz_class( nb );
        }
      for( unsigned i = 0 ; i < nbToys ; i++ )
        {
          string nb;
          cin >> nb >> toys[i].type;
          toys[i].nb = mpz_class( nb );
        }

      mpz_class max_boxed = 0;

      stack< State > st;
      {
        State s;
        s.ai = s.bi = 0;
        s.ain = s.bin = s.boxed = mpz_class( 0 );
        st.push( s );
      }

      while( !st.empty() )
        {
          State s = st.top();
          st.pop();

          if( s.ai == nbBoxes || s.bi == nbToys )
            {
              max_boxed = max( max_boxed, s.boxed );
              continue;
            }

          if( boxes[ s.ai ].type == toys[ s.bi ].type )
            {
              if( boxes[ s.ai ].nb - s.ain > toys[ s.bi ].nb - s.bin )
                {
                  mpz_class advance = toys[ s.bi ].nb - s.bin;
                  s.ain += advance;
                  s.bi++;
                  s.bin = 0;
                  s.boxed += advance;
                  st.push( s );
                }
              else if( boxes[ s.ai ].nb - s.ain < toys[ s.bi ].nb - s.bin )
                {
                  mpz_class advance = boxes[ s.ai ].nb - s.ain;
                  s.ai++;
                  s.ain = 0;
                  s.bin += advance;
                  s.boxed += advance;
                  st.push( s );
                }
              else
                {
                  mpz_class advance = toys[ s.bi ].nb - s.bin;
                  s.ai++;
                  s.ain = 0;
                  s.bi++;
                  s.bin = 0;
                  s.boxed += advance;
                  st.push( s );
                }
            }
          else
            {
              State s1 = s, s2 = s;
              s1.ai++;
              s1.ain = 0;
              st.push( s1 );
              s2.bi++;
              s2.bin = 0;
              st.push( s2 );
            }
        }

      cout << "Case #" << noCase << ": " << max_boxed << endl;
    }
  return EXIT_SUCCESS;
}
