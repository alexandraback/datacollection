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

// Gnu multiprecision library available from www.gnu.org (package
// libgmpxx4ldbl in Debian).
#include <gmpxx.h>

using namespace std;


// 64 bits should be enough, but I don't want to figure out how to make that
// multiplcation work.
typedef mpz_class Int;

Int T;
Int r, t;

Int search (Int lo, Int hi) 
{
    for (;;) {
        Int m = (lo + hi) / 2;
        if (  t < 2 * m * m - m + 2 * m * r) {
            hi = m;
        } else {
            lo = m;
        }
        if (lo + 1 == hi) return lo;
    }

}


Int answer()
{
    for (Int N=1; ; N *= 2) {

        if ( t <  2 * N * N - N + 2 * N * r )
            return search ( N / 2, N);
    }

}

int main(int argc, char** argv)
{
    cin >> T;

    string junk;
    for (Int testcase = 1; testcase <= T; ++testcase) {
        cin >> r >> t;

        cerr << r << " " << t << endl;


        cout << "Case #" << testcase << ": "
            << answer() << endl;

    }
}


    
