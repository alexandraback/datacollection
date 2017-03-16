// Boost libraries available from www.boost.org 
#include <boost/lexical_cast.hpp>
using boost::lexical_cast;

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <memory>
#include <map>
#include <list>
#include <bitset>
#include <cstring>

using namespace std;


typedef size_t Int;

Int T;
Int n;
Int L;
string s;



int64_t answer()
{
    uint64_t tot = 0;
    Int cc = 0;
    //Int p = 0;
    Int lp = n - 2;
    for (Int i = 0; i < L; ++i) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o'
                || s[i] == 'i' || s[i] == 'u') {
            cc = 0;

        } else {
            ++cc;
        }
        cerr << cc << endl;
        if (cc==n) {
                cerr << L << ' ' << i << ' ' << lp << endl;
                cerr << "run: " << i - lp  << endl;
                cerr << "x's: " << (L - i ) << endl;
                tot += (L  - i  )* ( i -lp     );
            --cc;
            lp = i ;

        }
    }
    return tot;
}

int main(int argc, char** argv)
{
    cin >> T;

    string junk;
    for (Int testcase = 1; testcase <= T; ++testcase) {
        cin >> s >> n;
        L = s.size();

        cerr << s << ' ' << n << endl;

        cout << "Case #" << testcase << ": "
            << answer() << endl;

    }
}



