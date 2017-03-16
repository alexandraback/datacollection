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


typedef uint64_t Int;

Int T;
Int A, N;
multiset<Int> mo;


Int answer(Int A, multiset<Int> mo)
{
    Int ops= 0;
    while (mo.size()) {
        if (A > *mo.begin()) {
            A += *mo.begin();
            mo.erase(mo.begin());
        } else { 
            break;
        }
    }
    if (mo.empty()) return ops;


    if (A*2-1 <= A) return ops + mo.size();
    return min(ops + mo.size(), ops+1 + answer(A*2-1,mo)
            );

}

int main(int argc, char** argv)
{
    cin >> T;

    string junk;
    for (Int testcase = 1; testcase <= T; ++testcase) {
        mo.clear();
        cin >> A >> N;
        for (Int i=0; i<N; ++i) {
            Int m;
            cin >> m;
            mo.insert(m);
        }


        cout << "Case #" << testcase << ": "
            << answer(A, mo) << endl;

    }
}



