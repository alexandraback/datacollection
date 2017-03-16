// Boost libraries available from www.boost.org 
#include <boost/lexical_cast.hpp>
using boost::lexical_cast;

#include <iomanip>
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


typedef int64_t Int;

Int T;
Int P, Q;
typedef vector<Int> vt;
vt A(20);
Int testcase;

Int GCD(Int a, Int b)
{
    while( 1 )
    {
        a = a % b;
        if( a == 0 )
            return b;
        b = b % a;

        if( b == 0 )
            return a;
    }
}


ostream& operator<<(ostream& os, const vt& v) 
{
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) os << " ";
        os << v[i];
    }
    return os;
}

Int sum(vt& S)
{
    Int s = 0;
    for (size_t i =0; i < S.size(); ++i) {
        s += S[i];
    }
    return s;
    
}


Int answer()
{
    //if (Q== 1) return (P==1 ? 0 : -1);
    Int q = Q;
    Int pow = 0;
    while (!(q%2)) { q /=2, ++pow;}
    if (q !=1)  return -1;
    Int p = P;
    Int powp = 0;
    while (p) { p /=2, ++powp;}
    
    
    return pow - powp + 1;
}

string answer2()
{
    Int a = answer();


    if ( a == -1) return "impossible";
    return boost::lexical_cast<string>(a);
}

int main(int argc, char** argv)
{
    cin >> T;

    char junk;
    for (testcase = 1; testcase <= T; ++testcase) {
        //cerr << "\nTest case: " << testcase << endl;
        A.clear();
        cin >> P >> junk >> Q ;
        Int G = GCD(P,Q);
        P /= G;
        Q /= G;
        cerr << P << ' ' << Q << endl;
        cout << "Case #" << testcase << ": "
            << answer2() << endl;

    }
}
